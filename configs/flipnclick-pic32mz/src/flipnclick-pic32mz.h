/****************************************************************************
 * configs/flipnclick-pic32mz/src/flipnclick-pic32mz.h
 *
 *   Copyright (C) 2018 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __CONFIGS_FLIPNCLICK_PIC32MZ_SRC_FLIPNCLICK_PIC32MZ_H
#define __CONFIGS_FLIPNCLICK_PIC32MZ_SRC_FLIPNCLICK_PIC32MZ_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/compiler.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* Configuration ************************************************************/

/* LEDs *********************************************************************/
/* There are four LEDs on the top, red side of the board.  Only one can be
 * controlled by software:
 *
 *   LED L      - RB14 (SPI3_SCK)
 *
 * There are also four LEDs on the back, white side of the board:
 *
 *   LED A      - RA6
 *   LED B      - RA7
 *   LED C      - RE0
 *   LED D      - RE1
 *
 * A high output value illuminates the LEDs.
 */

#define GPIO_LED_L  (GPIO_OUTPUT | GPIO_VALUE_ZERO | GPIO_PORTB | GPIO_PIN14)
#define GPIO_LED_A  (GPIO_OUTPUT | GPIO_VALUE_ZERO | GPIO_PORTA | GPIO_PIN6)
#define GPIO_LED_B  (GPIO_OUTPUT | GPIO_VALUE_ZERO | GPIO_PORTA | GPIO_PIN7)
#define GPIO_LED_C  (GPIO_OUTPUT | GPIO_VALUE_ZERO | GPIO_PORTE | GPIO_PIN0)
#define GPIO_LED_D  (GPIO_OUTPUT | GPIO_VALUE_ZERO | GPIO_PORTE | GPIO_PIN1)

/* The Flip&Click PIC32MZ has 2 user push buttons labeled T1 and T2 on the
 * white side of the board:
 *
 * PIN   LED  Notes
 * ----- ---- -------------------------
 * RD10  T1   Sensed low when closed
 * RD11  T2   Sensed low when closed
 *
 * The switches have external pull-up resistors. The switches are pulled high
 * (+3.3V) and grounded when pressed.
 */

#define GPIO_T1      (GPIO_INPUT | GPIO_INTERRUPT | GPIO_PORTD | GPIO_PIN10)
#define GPIO_T2      (GPIO_INPUT | GPIO_INTERRUPT | GPIO_PORTD | GPIO_PIN11)

/****************************************************************************
 * Public Types
 ****************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/************************************************************************************
 * Name: pic32mz_spidev_initialize
 *
 * Description:
 *   Called to configure SPI chip select GPIO pins for the PCB Logic board.
 *
 ************************************************************************************/

#ifdef CONFIG_PIC32MZ_SPI
void weak_function pic32mz_spidev_initialize(void);
#endif

/************************************************************************************
 * Name: pic32mz_led_initialize
 *
 * Description:
 *   Configure on-board LEDs if LED support has been selected.
 *
 ************************************************************************************/

#ifdef CONFIG_ARCH_LEDS
void pic32mz_led_initialize(void);
#endif

/****************************************************************************
 * Name: pic32mz_bringup
 *
 * Description:
 *   Bring up board features
 *
 ****************************************************************************/

int pic32mz_bringup(void);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __CONFIGS_FLIPNCLICK_PIC32MZ_SRC_FLIPNCLICK_PIC32MZ_H */
