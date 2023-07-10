/**
 * SPDX-FileCopyrightText: 2023 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef RGB_LED_CONFIG_H
#define RGB_LED_CONFIG_H

// connections...
#define DATA_BASE_PIN 0
// #define DATA_N_PINS 6
#define ROWSEL_BASE_PIN 6
#define ROWSEL_N_PINS 4
// Scan is usually 16 (i.e. 1/16) for 64x32, or 32 (1/32) for 64x64 panels
#define SCAN 16  
#define CLK_PIN 11
#define STROBE_PIN 12
#define OEN_PIN 13

// dimensions...
#define WIDTH 64
#define HEIGHT 32

#endif