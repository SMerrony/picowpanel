/**
 * SPDX-FileCopyrightText: 2023 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>

#include "rgb_led_config.h"

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_t;

extern const rgb_t BLACK, RED, GREEN, BLUE, WHITE, CYAN, MAGENTA, YELLOW;

typedef uint32_t image_t[WIDTH][HEIGHT];

rgb_t string2rgb(char *s);

void clear_to_black (image_t img);
void show_3x5_char  (image_t img, unsigned char c, rgb_t fg, rgb_t bg, uint8_t x, uint8_t y);
void show_5x7_char  (image_t img, unsigned char c, rgb_t fg, rgb_t bg, uint8_t x, uint8_t y);
void show_6x10_char (image_t img, unsigned char c, rgb_t fg, rgb_t bg, uint8_t x, uint8_t y);
void show_3x5_string (image_t img, char msg[], uint8_t x, uint8_t y, rgb_t fg, rgb_t bg);
void show_5x7_string (image_t img, char msg[], uint8_t x, uint8_t y, rgb_t fg, rgb_t bg);
void show_6x10_string (image_t img, char msg[], uint8_t x, uint8_t y, rgb_t fg, rgb_t bg);

void dim (image_t img, int div);

#endif // DISPLAY_H