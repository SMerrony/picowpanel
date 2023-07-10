/**
 * SPDX-FileCopyrightText: 2023 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef INFO_ITEMS_H
#define INFO_ITEMS_H

#include "display.h"

typedef struct {
    char topic[64];     // full MQTT topic for this item
    char prefix[16];    // string to display before item
    char suffix[16];    // string to display after item
    int x;              // left x ordinate to start drawing
    int y;              // top y ordinate to start drawing
    char fg[12];        // foreground colour name
    char bg[12];        // background colour name    
    char font[12];      // font name - only "3x5" or "5x7"
    int scale;          // scale factor for font - only 1 or 2 supported ATM
} info_item_t;

extern const int INFO_ITEM_COUNT;

extern info_item_t info_items[];

void ii_setup(image_t *image);
void show_data(int ix, const char *data, int len);

#endif