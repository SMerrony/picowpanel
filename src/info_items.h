/**
 * SPDX-FileCopyrightText: 2023 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef INFO_ITEMS_H
#define INFO_ITEMS_H

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

void ii_setup(image_t *image);
void show_data(int ix, const char *data, int len);
void show_urgent();
void hide_urgent();

#endif