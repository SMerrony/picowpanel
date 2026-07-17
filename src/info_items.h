/**
 * SPDX-FileCopyrightText: 2023,2024,2026 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#pragma once

#include "graphics.h"

#define MAX_URGENT_CHARS 12

typedef struct {
    char topic[64];    // full MQTT topic for this item
    char prefix[8];    // string to display before item
    char suffix[8];    // string to display after item
    int x;             // left x ordinate to start drawing
    int y;             // top y ordinate to start drawing
    char fg[8];        // foreground colour name
    char bg[8];        // background colour name    
    char font[6];      // font name - only "3x5" or "5x7"
    int scale;         // scale factor for font - only 1 or 2 supported ATM
} info_item_t;

extern const int INFO_ITEM_COUNT;
extern const info_item_t info_items[];

#ifdef CLOCK1
    #define II_COUNT_INIT 4
    #define II_INIT { \
        {"rgbmatrix/time_hhmmss", "", "", 1, 0, "YELLOW", "BLACK", "3x5", 2}, \
        {"rgbmatrix/time_date", "", "", 2, 12, "MAGENTA", "BLACK", "5x7", 1}, \
        {"rgbmatrix/music_temp", "", "C", 0, 22, "CYAN", "BLACK", "3x5", 2}, \
        {"rgbmatrix/music_hum", "", "%", 42, 22, "YELLOW", "BLACK", "3x5", 2} \
     }
    #define UI_INIT {URGENT_TOPIC, "", "", 0, 22, "RED", "BLACK", "3x5", 2}
#endif
#ifdef CLOCK3
    #define II_COUNT_INIT 4
    #define II_INIT { \
        {"rgbmatrix/time_hhmm", "", "", 2, 0, "YELLOW", "BLACK", "5x7", 2}, \
        {"rgbmatrix/time_date", "", "", 3, 16, "MAGENTA", "BLACK", "5x7", 1}, \
        {"rgbmatrix/bedroom_temp", "", "C", 0, 24, "CYAN", "BLACK", "5X7", 1}, \
        {"rgbmatrix/outside_temp", "", "C", 44, 24, "GREEN", "BLACK", "5X7", 1}, \
    }
    #define UI_INIT {URGENT_TOPIC, "", "", 0, 22, "RED", "BLACK", "3x5", 2}
#endif
#ifdef INFOPANEL1
    #define II_COUNT_INIT 5
    #define II_INIT { \
        {"rgbmatrix/time_hhmm", "", "", 2, 0, "YELLOW", "BLACK", "5x7", 2}, \
        {"rgbmatrix/time_date", "", "", 3, 17, "MAGENTA", "BLACK", "5x7", 1}, \
        {"rgbmatrix/office_temp", "", "C", 0, 27, "CYAN", "BLACK", "3x5", 2}, \
        {"rgbmatrix/outside_temp", "", "", 44, 27, "GREEN", "BLACK", "3x5", 2}, \
        {"rgbmatrix/gbpeur", "", "", 8, 40, "YELLOW", "BLACK", "3x5", 1} \
    }
    #define UI_INIT {URGENT_TOPIC, "", "", 0, 0, "RED", "BLACK", "5x7", 2}
#endif

void ii_setup(image_t *image);
void show_data(int ix, const char *data, int len);
void show_urgent();
void hide_urgent();
void show_starting();
void hide_starting();
