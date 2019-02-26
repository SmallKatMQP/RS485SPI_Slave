/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v5.0
processor: LPC824
package_id: LPC824M201JHI33
mcu_data: ksdk2_0
processor_version: 5.0.0
board: LPCXpresso824
pin_labels:
- {pin_num: '11', pin_signal: PIO0_27, label: 'D1[3]/P3[42]/J1[9]/P0_27-BLUE', identifier: LED_BLUE}
- {pin_num: '10', pin_signal: PIO0_16, label: 'D1[4]/P3[43]/J2[2]/P0_16-GREEN', identifier: LED_GREEN}
- {pin_num: '2', pin_signal: PIO0_12, label: 'SW2/D1[1]/P3[45]/J2[5]/P0_12-RED-ISP', identifier: LED_RED;SW2}
- {pin_num: '22', pin_signal: PIO0_7/ADC_0, label: 'P3[14]/U2[31]/TARGET_TX-P0_7', identifier: DEBUG_UART_TX}
- {pin_num: '31', pin_signal: PIO0_18/ADC_8, label: 'P3[21]/J2[4]/U2[32]/TARGET_RX-P0_18', identifier: DEBUG_UART_RX}
- {pin_num: '6', pin_signal: SWCLK/PIO0_3, label: 'P5[4]/U2[16]/TARGET_SWCLK', identifier: DEBUG_SWD_SWDCLK}
- {pin_num: '7', pin_signal: SWDIO/PIO0_2, label: 'P5[2]/U2[17]/TARGET_SWDIO', identifier: DEBUG_SWD_SWDIO}
- {pin_num: '3', pin_signal: RESETN/PIO0_5, label: 'J4[3]/P3[4]/U2[3]/P5[10]/SW3[1]/TARGET_nRESET-P0_5', identifier: DEBUG_SWD_RESETN}
- {pin_num: '4', pin_signal: PIO0_4/ADC_11, label: 'SW1/P3[9]/J2[7]/P0_4-ISP_U_TXD-WAKEUP', identifier: SW1}
- {pin_num: '1', pin_signal: PIO0_13/ADC_10, label: 'P4[2]/P3[46]/J1[10]/P0_13'}
- {pin_num: '5', pin_signal: PIO0_28, label: 'P3[44]/J2[3]/P0_28-WKTCLKIN'}
- {pin_num: '8', pin_signal: PIO0_11/I2C0_SDA, label: 'P3[40]/J1[2]/P4[8]/P0_11-I2C0_SDA'}
- {pin_num: '9', pin_signal: PIO0_10/I2C0_SCL, label: 'P3[41]/J1[1]/P4[6]/P0_10-I2C0_SCL'}
- {pin_num: '12', pin_signal: PIO0_26, label: 'P3[5]/J1[7]/P4[3]/P0_26-MOSI'}
- {pin_num: '13', pin_signal: PIO0_25, label: 'P3[6]/J1[6]/P4[5]/P0_25-MISO'}
- {pin_num: '14', pin_signal: PIO0_24, label: 'P3[7]/J1[5]/P4[7]/P0_24-SCK'}
- {pin_num: '15', pin_signal: PIO0_15, label: 'P3[8]/J1[8]/P4[1]/P0_15-SSEL'}
- {pin_num: '16', pin_signal: PIO0_1/ACMP_I2/CLKIN, label: 'P3[11]/P0_1-CLKIN'}
- {pin_num: '17', pin_signal: PIO0_9/XTALOUT, label: 'P3[12]/U2[26]/P0_9-LINK_nWAKE'}
- {pin_num: '18', pin_signal: PIO0_8/XTALIN, label: 'P3[13]/U2[27]/P0_8-LINK_nSLEEP'}
- {pin_num: '23', pin_signal: PIO0_6/ADC_1/VDDCMP, label: 'P3[15]/J5[1]/P0_6-ADC1-VDDCMP'}
- {pin_num: '24', pin_signal: PIO0_0/ACMP_I1, label: 'P3[10]/J2[8]/P0_0-ISP_U_RXD'}
- {pin_num: '25', pin_signal: PIO0_14/ACMP_I3/ADC_2, label: 'P3[16]/J5[2]/P0_14-ADC2-ACMP_I3'}
- {pin_num: '26', pin_signal: PIO0_23/ADC_3/ACMP_I4, label: 'P3[17]/J5[3]/P0_23-ADC3-ACMP_I4'}
- {pin_num: '27', pin_signal: PIO0_22/ADC_4, label: 'P3[18]/J5[4]/P0_22-ADC4'}
- {pin_num: '28', pin_signal: PIO0_21/ADC_5, label: 'P3[19]/J5[5]/P0_21-ADC5'}
- {pin_num: '29', pin_signal: PIO0_20/ADC_6, label: 'P3[20]/J5[6]/P0_20-ADC6'}
- {pin_num: '30', pin_signal: PIO0_19/ADC_7, label: 'P3[22]/J2[6]/P0_19'}
- {pin_num: '32', pin_signal: PIO0_17/ADC_9, label: 'P4[4]/P3[47]/J2[1]/P0_17'}
- {pin_num: '19', pin_signal: VDD, label: C11/C12/FB4/VDD}
- {pin_num: '21', pin_signal: VREFP, label: C13/FB3/VREFP}
- {pin_num: '20', pin_signal: VREFN, label: FB2/VREFN}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_iocon.h"
#include "fsl_swm.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
    BOARD_InitDEBUG_UARTPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '13', peripheral: SPI0, signal: SCK, pin_signal: PIO0_25}
  - {pin_num: '12', peripheral: SPI0, signal: MOSI, pin_signal: PIO0_26, mode: pullDown}
  - {pin_num: '29', peripheral: USART1, signal: RXD, pin_signal: PIO0_20/ADC_6}
  - {pin_num: '28', peripheral: GPIO, signal: 'PIO0, 21', pin_signal: PIO0_21/ADC_5, direction: OUTPUT}
  - {pin_num: '27', peripheral: USART1, signal: TXD, pin_signal: PIO0_22/ADC_4}
  - {pin_num: '11', peripheral: SPI0, signal: MISO, pin_signal: PIO0_27}
  - {pin_num: '14', peripheral: SPI0, signal: SSEL0, pin_signal: PIO0_24}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitPins(void)
{
    /* Enables clock for IOCON block.: Enable. */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables clock for switch matrix.: Enable. */
    CLOCK_EnableClock(kCLOCK_Swm);

    GPIO->DIR[0] = ((GPIO->DIR[0] &
                     /* Mask bits to zero which are setting */
                     (~(GPIO_DIR_DIRP_MASK)))

                    /* Selects pin direction for pin PIOm_n (bit 0 = PIOn_0, bit 1 = PIOn_1, etc.). Supported pins
                     * depends on the specific device and package. 0 = input. 1 = output.: 0x200000u */
                    | GPIO_DIR_DIRP(0x200000u));

    IOCON->PIO[22] = ((IOCON->PIO[22] &
                       /* Mask bits to zero which are setting */
                       (~(IOCON_PIO_MODE_MASK)))

                      /* Selects function mode (on-chip pull-up/pull-down resistor control).: Pull-down. Pull-down
                       * resistor enabled. */
                      | IOCON_PIO_MODE(PIO0_26_MODE_PULL_DOWN));

    /* USART1_TXD connect to P0_22 */
    SWM_SetMovablePinSelect(SWM0, kSWM_USART1_TXD, kSWM_PortPin_P0_22);

    /* USART1_RXD connect to P0_20 */
    SWM_SetMovablePinSelect(SWM0, kSWM_USART1_RXD, kSWM_PortPin_P0_20);

    /* SPI0_SCK connect to P0_25 */
    SWM_SetMovablePinSelect(SWM0, kSWM_SPI0_SCK, kSWM_PortPin_P0_25);

    /* SPI0_MOSI connect to P0_26 */
    SWM_SetMovablePinSelect(SWM0, kSWM_SPI0_MOSI, kSWM_PortPin_P0_26);

    /* SPI0_MISO connect to P0_27 */
    SWM_SetMovablePinSelect(SWM0, kSWM_SPI0_MISO, kSWM_PortPin_P0_27);

    /* SPI0_SSEL0 connect to P0_24 */
    SWM_SetMovablePinSelect(SWM0, kSWM_SPI0_SSEL0, kSWM_PortPin_P0_24);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitLEDsPins:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'true'}
- pin_list: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitLEDsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitLEDsPins(void)
{

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitDEBUG_UARTPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitDEBUG_UARTPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitDEBUG_UARTPins(void)
{

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitSWD_DEBUGPins:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '6', peripheral: SWD, signal: SWCLK, pin_signal: SWCLK/PIO0_3, mode: pullUp, invert: disabled, hysteresis: disabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
  - {pin_num: '7', peripheral: SWD, signal: SWDIO, pin_signal: SWDIO/PIO0_2, mode: pullUp, invert: disabled, hysteresis: disabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
  - {pin_num: '3', peripheral: SYSCON, signal: RESETN, pin_signal: RESETN/PIO0_5, mode: pullUp, invert: disabled, hysteresis: disabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitSWD_DEBUGPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitSWD_DEBUGPins(void)
{
    /* Enables clock for IOCON block.: Enable. */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables clock for switch matrix.: Enable. */
    CLOCK_EnableClock(kCLOCK_Swm);

    const uint32_t IOCON_INDEX_PIO0_2_config = (/* Selects pull-up function */
                                                IOCON_PIO_MODE_PULLUP |
                                                /* Disable hysteresis */
                                                IOCON_PIO_HYS_DI |
                                                /* Input not invert */
                                                IOCON_PIO_INV_DI |
                                                /* Disables Open-drain function */
                                                IOCON_PIO_OD_DI |
                                                /* Bypass input filter */
                                                IOCON_PIO_SMODE_BYPASS |
                                                /* IOCONCLKDIV0 */
                                                IOCON_PIO_CLKDIV0);
    /* PORT0 PIN2 (coords: ) is configured as  */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_2, IOCON_INDEX_PIO0_2_config);

    const uint32_t IOCON_INDEX_PIO0_3_config = (/* Selects pull-up function */
                                                IOCON_PIO_MODE_PULLUP |
                                                /* Disable hysteresis */
                                                IOCON_PIO_HYS_DI |
                                                /* Input not invert */
                                                IOCON_PIO_INV_DI |
                                                /* Disables Open-drain function */
                                                IOCON_PIO_OD_DI |
                                                /* Bypass input filter */
                                                IOCON_PIO_SMODE_BYPASS |
                                                /* IOCONCLKDIV0 */
                                                IOCON_PIO_CLKDIV0);
    /* PORT0 PIN3 (coords: ) is configured as  */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_3, IOCON_INDEX_PIO0_3_config);

    const uint32_t IOCON_INDEX_PIO0_5_config = (/* Selects pull-up function */
                                                IOCON_PIO_MODE_PULLUP |
                                                /* Disable hysteresis */
                                                IOCON_PIO_HYS_DI |
                                                /* Input not invert */
                                                IOCON_PIO_INV_DI |
                                                /* Disables Open-drain function */
                                                IOCON_PIO_OD_DI |
                                                /* Bypass input filter */
                                                IOCON_PIO_SMODE_BYPASS |
                                                /* IOCONCLKDIV0 */
                                                IOCON_PIO_CLKDIV0);
    /* PORT0 PIN5 (coords: ) is configured as  */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_5, IOCON_INDEX_PIO0_5_config);

    /* SWCLK connect to P0_3 */
    SWM_SetFixedPinSelect(SWM0, kSWM_SWCLK, true);

    /* SWDIO connect to P0_2 */
    SWM_SetFixedPinSelect(SWM0, kSWM_SWDIO, true);

    /* RESETN connect to P0_5 */
    SWM_SetFixedPinSelect(SWM0, kSWM_RESETN, true);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitBUTTONsPins:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'true'}
- pin_list: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBUTTONsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitBUTTONsPins(void)
{

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
