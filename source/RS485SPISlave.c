/*
 * Copyright 2016-2018 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    LPC824_Project.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "clock_config.h"
#include "LPC824.h"
#include "fsl_debug_console.h"
#include "fsl_usart.h"
#include "fsl_dma.h"
#include "fsl_spi.h"
#include "fsl_gpio.h"
#include "fsl_pint.h"
#include "pin_mux.h"
#include <stdbool.h>

#define USART USART1
#define EXAMPLE_USART_CLK_SRC kCLOCK_PllOut
#define USART_CLK_FREQ CLOCK_GetFreq(EXAMPLE_USART_CLK_SRC)
//#define EXAMPLE_USART_CLK_SRC kCLOCK_MainClk
//#define EXAMPLE_USART_CLK_FREQ CLOCK_GetFreq(EXAMPLE_USART_CLK_SRC)

#define ECHO_BUFFER_LENGTH 6
#define BUFFER_SIZE 5



#define SPI_SLAVE SPI0
#define EXAMPLE_SPI_SLAVE_SSEL kSPI_Ssel0Assert

#define SPI_SLAVE_DMA_BASEADDR DMA0
#define SPI_SLAVE_TX_CHANNEL 7
#define SPI_SLAVE_RX_CHANNEL 6


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void USARTUserCallback(USART_Type *base, usart_handle_t *handle, status_t status, void *userData);
static void USARTInit(void);
static void USARTPrepareTransfer(void);
static void SPI_DmaTxCallback(dma_handle_t *handle, void *param, bool transferDone, uint32_t tcds);
static void SPI_DmaRxCallback(dma_handle_t *handle, void *param, bool transferDone, uint32_t tcds);
static void SPISlaveInit(void);
static void SlaveDMASetup(void);
static void SlaveStartDMATransfer(void);
void pint_intr_callback(pint_pin_int_t pintr, uint32_t pmatch_status);

usart_handle_t g_usartHandle;
uint8_t g_tipString[] = "Usart interrupt transfer example.\r\nBoard receives 8 characters then sends them out.\r\nNow please input:\r\n";

uint8_t Uart_TxBuffer[ECHO_BUFFER_LENGTH] = {0};
uint8_t Uart_RxBuffer[ECHO_BUFFER_LENGTH] = {0};
volatile bool rxBufferEmpty = true;
volatile bool txBufferFull = false;
volatile bool txOnGoing = false;
volatile bool rxOnGoing = false;

usart_transfer_t sendXfer;
usart_transfer_t receiveXfer;
dma_handle_t slaveTxHandle;
dma_handle_t slaveRxHandle;

static volatile bool SlaveTxFinished = false;
static volatile bool SlaveRxFinished = false;

SDK_ALIGN(dma_descriptor_t txDescriptor, 16) = {0};


static uint16_t MotorUpdate[BUFFER_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00};
static uint16_t MotorData[BUFFER_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00};
uint16_t ShiftedBuffer_16[5];
uint16_t ShiftedBuffer_8[6];

uint16_t devID = 0;

void pint_intr_callback(pint_pin_int_t pintr, uint32_t pmatch_status)
{


}

static void SPI_DmaTxCallback(dma_handle_t *handle, void *param, bool transferDone, uint32_t tcds)
{
	SlaveTxFinished = true;


}

static void SPI_DmaRxCallback(dma_handle_t *handle, void *param, bool transferDone, uint32_t tcds)
{
	SlaveRxFinished = true;

	Uart_TxBuffer[0] = MotorUpdate[0];
	Uart_TxBuffer[1] = MotorUpdate[1];
	Uart_TxBuffer[2] = MotorUpdate[2]>>8;
	Uart_TxBuffer[3] = (uint8_t)MotorUpdate[2];
	Uart_TxBuffer[4] = MotorUpdate[3];
	Uart_TxBuffer[5] = MotorUpdate[4];

	//GPIO_PinWrite(GPIO, 0, 21, 1); //set dir pin low


	USART_TransferSendNonBlocking(USART, &g_usartHandle, &sendXfer);

}

int state = 1;
static void USARTUserCallback(USART_Type *base, usart_handle_t *handle, status_t status, void *userData)
{

	if (kStatus_USART_TxIdle == status)
	{

		GPIO_PinWrite(GPIO, 0, 21, 0); //set dir pin low
//
		USART_TransferReceiveNonBlocking(USART, &g_usartHandle, &receiveXfer, NULL);
	//	SlaveStartDMATransfer();

	}

	if (kStatus_USART_RxIdle == status)
	{
		MotorData[0] = Uart_RxBuffer[0];
		MotorData[1] = Uart_RxBuffer[1];
		MotorData[2] = Uart_RxBuffer[2]<<8|Uart_RxBuffer[3];
		MotorData[3] = Uart_RxBuffer[4];
		MotorData[4] = Uart_RxBuffer[5];
		GPIO_PinWrite(GPIO, 0, 21, 1); //set dir pin High

		SlaveStartDMATransfer();
	}
}

int main(void) {

	/* Init board hardware. */
 	CLOCK_EnableClock(kCLOCK_Spi0);
	/* Enable clock of uart0. */
	CLOCK_EnableClock(kCLOCK_Uart0);
	/* Ser DIV of uart0. */
    CLOCK_SetClkDivider(kCLOCK_DivUsartClk,1U);


	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();

	USARTInit();

	USARTPrepareTransfer();

	SPISlaveInit();
	//PINT_Init(PINT);

	/* Setup Pin Interrupt 0 for rising edge */
	//PINT_PinInterruptConfig(PINT, 0, 1, pint_intr_callback);
	/* Enable callbacks for PINT0 by Index */
	//PINT_EnableCallbackByIndex(PINT, kPINT_PinInt0);

	/* Set up DMA configuration. */
	SlaveDMASetup();
	GPIO_PinWrite(GPIO, 0, 21, 1); //set dir pin high

	SlaveStartDMATransfer();

	while (1)
	{

	}
}


static void USARTInit(void)
{
	usart_config_t config;

	/* Default config by using USART_GetDefaultConfig():
	 * config.baudRate_Bps = 115200U;
	 * config.parityMode = kUSART_ParityDisabled;
	 * config.stopBitCount = kUSART_OneStopBit;
	 * config.bitCountPerChar = kUSART_8BitsPerChar;
	 * config.loopback = false;
	 * config.enableRx = false;
	 * config.enableTx = false;
	 * config.syncMode = kUSART_SyncModeDisabled;
	 */
	USART_GetDefaultConfig(&config);
	config.baudRate_Bps = 1843200;
	config.enableRx = true;
	config.enableTx = true;

	/* Initialize the USART with configuration. */
	USART_Init(USART, &config, USART_CLK_FREQ);
}

static void USARTPrepareTransfer(void)
{
	/* Create USART handle, this API will initialize the g_usartHandle and install the callback function. */
	USART_TransferCreateHandle(USART, &g_usartHandle, USARTUserCallback, NULL);

	/* Set xfer parameters for sending data. */
	sendXfer.data = Uart_TxBuffer;
	sendXfer.dataSize = 7;//sizeof(Uart_TxBuffer);

	/* Set xfers parameters for receiving data. */
	receiveXfer.data = Uart_RxBuffer;
	receiveXfer.dataSize = 6;
}

static void  SPISlaveInit(void)
{
	spi_slave_config_t slaveConfig;

	/* Default configuration for slave:
	 * userConfig.enableSlave = true;
	 * userConfig.polarity = kSPI_ClockPolarityActiveHigh;
	 * userConfig.phase = kSPI_ClockPhaseFirstEdge;
	 * userConfig.direction = kSPI_MsbFirst;
	 * userConfig.dataWidth = kSPI_Data8Bits;
	 * userConfig.sselPol = kSPI_SpolActiveAllLow;
	 */
	SPI_SlaveGetDefaultConfig(&slaveConfig);

	SPI_SlaveInit(SPI_SLAVE, &slaveConfig);


}


static void SlaveDMASetup(void)
{
	DMA_Init(SPI_SLAVE_DMA_BASEADDR);

	/* Enable channel and Create handle for RX channel. */
	DMA_EnableChannel(SPI_SLAVE_DMA_BASEADDR, SPI_SLAVE_RX_CHANNEL);
	DMA_CreateHandle(&slaveRxHandle, SPI_SLAVE_DMA_BASEADDR, SPI_SLAVE_RX_CHANNEL);
	DMA_SetCallback(&slaveRxHandle, SPI_DmaRxCallback, NULL);

	/* Enable channel and Create handle for TX channel. */
	DMA_EnableChannel(SPI_SLAVE_DMA_BASEADDR, SPI_SLAVE_TX_CHANNEL);
	DMA_CreateHandle(&slaveTxHandle, SPI_SLAVE_DMA_BASEADDR,SPI_SLAVE_TX_CHANNEL);
	DMA_SetCallback(&slaveTxHandle, SPI_DmaTxCallback, NULL);

	/* Set the channel priority. */
	DMA_SetChannelPriority(SPI_SLAVE_DMA_BASEADDR, SPI_SLAVE_TX_CHANNEL, kDMA_ChannelPriority3);
	DMA_SetChannelPriority(SPI_SLAVE_DMA_BASEADDR, SPI_SLAVE_RX_CHANNEL, kDMA_ChannelPriority2);
}

static void SlaveStartDMATransfer(void)
{
	uint32_t i = 0U;
	dma_transfer_config_t slaveTxDmaConfig, slaveRxDmaConfig;

	/* Init Buffer*/


	/* Prepare and start DMA RX transfer. */
	DMA_PrepareTransfer(&slaveRxDmaConfig, (void *)&SPI_SLAVE->RXDAT, MotorUpdate, sizeof(uint16_t), BUFFER_SIZE*2,
			kDMA_PeripheralToMemory, NULL);
	DMA_SubmitTransfer(&slaveRxHandle, &slaveRxDmaConfig);

	DMA_StartTransfer(&slaveRxHandle);

	/* Prepare and start DMA TX transfer. */
	DMA_PrepareTransfer(&slaveTxDmaConfig, MotorData, (void *)&SPI_SLAVE->TXDAT, sizeof(uint16_t), BUFFER_SIZE*2,
			kDMA_MemoryToPeripheral, NULL);
	DMA_SubmitTransfer(&slaveTxHandle, &slaveTxDmaConfig);

	DMA_StartTransfer(&slaveTxHandle);
}


