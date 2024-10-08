/**
 * SPDX-FileCopyrightText: 2023,2024 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#pragma once

#include "config.h"

// connections...
#define DATA_BASE_PIN 0
// #define DATA_N_PINS 6
#define ROWSEL_BASE_PIN 6
#define ROWSEL_N_PINS 4 // 5 // or 4 
#define CLK_PIN 11
#define STROBE_PIN 12
#define OEN_PIN 13

#if PANEL_SIZE == 6432
    // dimensions...
    #define WIDTH 64
    #define HEIGHT 32
    // Scan is usually 16 (i.e. 1/16) for 64x32, or 32 (1/32) for 64x64 panels
    #define SCAN 16  
#elif PANEL_SIZE == 6464
    // dimensions...
    #define WIDTH 64
    #define HEIGHT 64
    // Scan is usually 16 (i.e. 1/16) for 64x32, or 32 (1/32) for 64x64 panels
    #define SCAN 32  
#endif
