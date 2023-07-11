/**
 * SPDX-FileCopyrightText: 2023 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "info_items.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "display.h"
#include "mqtt.h"

static image_t *ii_image;
static bool showing_image;
const int INFO_ITEM_COUNT = 4;

info_item_t info_items[] = {
    {"rgbmatrix/time_hhmmss", "", "", 1, 0, "YELLOW", "BLACK", "3x5", 2},
    {"rgbmatrix/time_date", "", "", 2, 12, "MAGENTA", "BLACK", "5x7", 1},
    {"rgbmatrix/music_temp", "", "C", 0, 22, "CYAN", "BLACK", "3x5", 2},
    {"rgbmatrix/music_hum", "", "%", 42, 22, "BLUE", "BLACK", "3x5", 2}
};

void ii_setup(image_t *image) {
    ii_image = image;
    showing_image = true;
}

uint32_t getTotalHeap(void) {
   extern char __StackLimit, __bss_end__;
   return &__StackLimit  - &__bss_end__;
}

uint32_t getFreeHeap(void) {
   struct mallinfo m = mallinfo();
   return getTotalHeap() - m.uordblks;
}

void show_data(int id, const char *data, int len) {
    if ((id < INFO_ITEM_COUNT) && showing_image) { // handle msg on a subscribed topic
        char info[WIDTH] = "";
        if (strlen(info_items[id].prefix) > 0) strcpy(info_items[id].prefix, info);
        strncat(info, data, len);
        if (strlen(info_items[id].suffix) > 0) strcat(info, info_items[id].suffix);
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
            show_5x7_string(*ii_image, 
                            info, 
                            info_items[id].x, 
                            info_items[id].y, 
                            string2rgb(info_items[id].fg), 
                            string2rgb(info_items[id].bg)
                            );
        }
        return;
    } 
    if (id == ID_CONTROL) {
        if (strcmp(data, "Off") == 0) {
            showing_image = false;
            clear_to_black(*ii_image);
        }
        if (strcmp(data, "On") == 0) {
            showing_image = true;
        }
        if (strcmp(data, "Memory") == 0) {
            printf("INFO: Free memory: %lu\n", getFreeHeap());
        }
        return;
    }
    if (id == ID_URGENT) {
        // TODO
        return;
    }
    
    // shouldn't get here unless we're not displaying info ("Off" control message received)
    if (showing_image) {
        printf("WARNING: Unexpected info item, not handled (in info_items.c)\n");
    }
}