/**
 * SPDX-FileCopyrightText: 2023 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "info_items.h"

#include <stdio.h>
#include <string.h>

#include "display.h"
#include "mqtt.h"

static image_t *ii_image;
const int INFO_ITEM_COUNT = 4;

info_item_t info_items[] = {
    {"rgbmatrix/time_hhmmss", "", "", 1, 0, "YELLOW", "BLACK", "3x5", 2},
    {"rgbmatrix/time_date", "", "", 2, 12, "MAGENTA", "BLACK", "5x7", 1},
    {"rgbmatrix/music_temp", "", "C", 0, 22, "CYAN", "BLACK", "3x5", 2},
    {"rgbmatrix/music_hum", "", "%", 42, 22, "BLUE", "BLACK", "3x5", 2}
};

void ii_setup(image_t *image) {
    ii_image = image;
}

void show_data(int id, const char *data, int len) {
    if (id < INFO_ITEM_COUNT) { // handle msg on a subscribed topic
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
        // TODO
        return;
    }
    if (id == ID_URGENT) {
        // TODO
        return;
    }

    printf("WARNING: Unexpected info item, not handled (in info_items.c)\n");
}