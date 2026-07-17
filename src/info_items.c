/**
 * SPDX-FileCopyrightText: 2023,2024,2026 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "info_items.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "config.h"
#include "graphics.h"
#include "mqtt.h"
#include "rgbmatrix.h"

static image_t *ii_image;
static bool showing_urgent;
static bool showing_starting = true;
static char urgent_msg[MAX_URGENT_CHARS+1];

const info_item_t info_items[] = II_INIT;
const info_item_t urgent_item = UI_INIT;
const int INFO_ITEM_COUNT = II_COUNT_INIT;

void ii_setup(image_t *image) {

    ii_image = image;
    showing_urgent = false;
}

uint32_t getTotalHeap(void) {
   extern char __StackLimit, __bss_end__;
   return &__StackLimit  - &__bss_end__;
}

uint32_t getFreeHeap(void) {
   struct mallinfo m = mallinfo();
   return getTotalHeap() - m.uordblks;
}

void show_urgent() {
    if (showing_urgent) {
        show_6x10_string(*ii_image, 
                        urgent_msg, 
                        urgent_item.x, 
                        urgent_item.y, 
                        string2rgb(urgent_item.fg), 
                        string2rgb(urgent_item.bg)
                        );
    }
}

/* hide_urgent displays the urgent message black-on-black
   It is intended to be used for the blink effect. */
void hide_urgent() {
    if (showing_urgent) {
        show_6x10_string(*ii_image, 
                urgent_msg, 
                urgent_item.x, 
                urgent_item.y, 
                BLACK, 
                BLACK
                );
                
    }
}

void show_starting() {
    show_5x7_string(*ii_image,
                    "Starting...",
                    urgent_item.x,
                    urgent_item.y,
                    string2rgb(urgent_item.fg), 
                    string2rgb(urgent_item.bg)
                    );
}

void hide_starting() {
    show_5x7_string(*ii_image,
                    "Starting...",
                    urgent_item.x,
                    urgent_item.y,
                    BLACK,
                    BLACK
                    );
    showing_starting = false;
}

void show_data(int id, const char *data, int len) {
    if (id < INFO_ITEM_COUNT) { // handle msg on a subscribed topic
        char info[WIDTH] = "";
        if (strlen(info_items[id].prefix) > 0) strcpy(info, info_items[id].prefix);
        strncat(info, data, len);
        if (strlen(info_items[id].suffix) > 0) strcat(info, info_items[id].suffix);
        if (showing_starting) {
            hide_starting();
            showing_starting = false;
        }
        if (strcmp(info_items[id].font, "3x5") == 0) {
            if (info_items[id].scale == 1) {
                show_3x5_string(*ii_image, 
                                info, 
                                info_items[id].x, 
                                info_items[id].y, 
                                string2rgb(info_items[id].fg), 
                                string2rgb(info_items[id].bg)
                            );
            } else {
                show_6x10_string(*ii_image, 
                                info, 
                                info_items[id].x, 
                                info_items[id].y, 
                                string2rgb(info_items[id].fg), 
                                string2rgb(info_items[id].bg)
                                );
            }
        } else {
            if (info_items[id].scale == 1) {
                show_5x7_string(*ii_image, 
                                info, 
                                info_items[id].x, 
                                info_items[id].y, 
                                string2rgb(info_items[id].fg), 
                                string2rgb(info_items[id].bg)
                                );
            } else {
                    show_10x14_string(*ii_image, 
                                info, 
                                info_items[id].x, 
                                info_items[id].y, 
                                string2rgb(info_items[id].fg), 
                                string2rgb(info_items[id].bg)
                                );  
            }
        }
        return;
    } 
    if (id == ID_CONTROL) {
        if (strcmp(data, "Off") == 0) {
            set_blank_display(true);
        }
        if (strcmp(data, "On") == 0) {
            set_blank_display(false);
        }
        if (strcmp(data, "Memory") == 0) {
            printf("INFO: Free memory: %lu\n", getFreeHeap());
        }
        return;
    }
    if (id == ID_URGENT) {
        if (strlen(data) > 0) {
            showing_urgent = true;
            strncpy(urgent_msg, data, MAX_URGENT_CHARS);
            show_urgent();
        } else {
            hide_urgent();            
            showing_urgent = false;
        }
        return;
    }
    
    // shouldn't get here
    printf("WARNING: Unexpected info item, not handled (in info_items.c)\n");
}