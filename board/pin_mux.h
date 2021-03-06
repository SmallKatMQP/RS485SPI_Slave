/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
    kPIN_MUX_DirectionInput = 0U,        /* Input direction */
    kPIN_MUX_DirectionOutput = 1U,       /* Output direction */
    kPIN_MUX_DirectionInputOrOutput = 2U /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief
 * Selects function mode (on-chip pull-up/pull-down resistor control).
 * : Pull-down.
 * Pull-down resistor enabled.
 */
#define PIO0_26_MODE_PULL_DOWN 0x01u

/*! @name PIO0_27 (number 11), D1[3]/P3[42]/J1[9]/P0_27-BLUE
  @{ */
#define BOARD_INITPINS_LED_BLUE_PERIPHERAL SPI0                       /*!<@brief Device name: SPI0 */
#define BOARD_INITPINS_LED_BLUE_SIGNAL MISO                           /*!<@brief SPI0 signal: MISO */
#define BOARD_INITPINS_LED_BLUE_PORT 0U                               /*!<@brief PORT device name: 0U */
#define BOARD_INITPINS_LED_BLUE_PIN 27U                               /*!<@brief 0U pin index: 27 */
#define BOARD_INITPINS_LED_BLUE_PIN_NAME PIO0_27                      /*!<@brief Pin name */
#define BOARD_INITPINS_LED_BLUE_LABEL "D1[3]/P3[42]/J1[9]/P0_27-BLUE" /*!<@brief Label */
#define BOARD_INITPINS_LED_BLUE_NAME "LED_BLUE"                       /*!<@brief Identifier name */
                                                                      /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void); /* Function assigned for the Cortex-M0P */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLEDsPins(void); /* Function assigned for the Cortex-M0P */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitDEBUG_UARTPins(void); /* Function assigned for the Cortex-M0P */

#define IOCON_PIO_CLKDIV0 0x00u      /*!<@brief IOCONCLKDIV0 */
#define IOCON_PIO_HYS_DI 0x00u       /*!<@brief Disable hysteresis */
#define IOCON_PIO_INV_DI 0x00u       /*!<@brief Input not invert */
#define IOCON_PIO_MODE_PULLUP 0x10u  /*!<@brief Selects pull-up function */
#define IOCON_PIO_OD_DI 0x00u        /*!<@brief Disables Open-drain function */
#define IOCON_PIO_SMODE_BYPASS 0x00u /*!<@brief Bypass input filter */

/*! @name SWCLK (number 6), P5[4]/U2[16]/TARGET_SWCLK
  @{ */
/*!
 * @brief Device name: SWD */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDCLK_PERIPHERAL SWD
/*!
 * @brief SWD signal: SWCLK */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDCLK_SIGNAL SWCLK
/*!
 * @brief Pin name */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDCLK_PIN_NAME SWCLK
/*!
 * @brief Label */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDCLK_LABEL "P5[4]/U2[16]/TARGET_SWCLK"
/*!
 * @brief Identifier name */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDCLK_NAME "DEBUG_SWD_SWDCLK"
/* @} */

/*! @name SWDIO (number 7), P5[2]/U2[17]/TARGET_SWDIO
  @{ */
/*!
 * @brief Device name: SWD */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDIO_PERIPHERAL SWD
/*!
 * @brief SWD signal: SWDIO */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDIO_SIGNAL SWDIO
/*!
 * @brief Pin name */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDIO_PIN_NAME SWDIO
/*!
 * @brief Label */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDIO_LABEL "P5[2]/U2[17]/TARGET_SWDIO"
/*!
 * @brief Identifier name */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDIO_NAME "DEBUG_SWD_SWDIO"
/* @} */

/*! @name RESETN (number 3), J4[3]/P3[4]/U2[3]/P5[10]/SW3[1]/TARGET_nRESET-P0_5
  @{ */
/*!
 * @brief Device name: SYSCON */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_RESETN_PERIPHERAL SYSCON
/*!
 * @brief SYSCON signal: RESETN */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_RESETN_SIGNAL RESETN
/*!
 * @brief Pin name */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_RESETN_PIN_NAME RESETN
/*!
 * @brief Label */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_RESETN_LABEL "J4[3]/P3[4]/U2[3]/P5[10]/SW3[1]/TARGET_nRESET-P0_5"
/*!
 * @brief Identifier name */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_RESETN_NAME "DEBUG_SWD_RESETN"
/* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitSWD_DEBUGPins(void); /* Function assigned for the Cortex-M0P */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitBUTTONsPins(void); /* Function assigned for the Cortex-M0P */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
