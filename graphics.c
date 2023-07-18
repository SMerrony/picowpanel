/**
 * SPDX-FileCopyrightText: 2023 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <string.h>

#include "graphics.h"
#include "font_3x5.h"
#include "font_5x7.h"

const rgb_t BLACK   = {0, 0, 0};
const rgb_t RED   = {127, 0, 0};
const rgb_t GREEN = {0, 127, 0};
const rgb_t BLUE  = {0, 0, 127};
const rgb_t WHITE = {127, 127, 127};
const rgb_t CYAN = {0, 127, 127};
const rgb_t MAGENTA = {127, 0, 127};
const rgb_t YELLOW = {127, 127, 0};

uint32_t rgb2bgr32(rgb_t rgb) {
    uint32_t col = (rgb.g<<16 | rgb.b<<8 | rgb.r);
    return col;
}

rgb_t bgr322rgb(uint32_t bgr) {
    rgb_t rgb;
    rgb.r = bgr & 0x000000ff;
    rgb.b = (bgr >> 8) & 0x000000ff;
    rgb.g = (bgr >> 16) & 0x000000ff;
    return rgb; 
}

rgb_t string2rgb(char *s) {
    if (strcmp("BLACK", s) == 0) return BLACK;
    if (strcmp("RED", s) == 0) return RED;
    if (strcmp("GREEN", s) == 0) return GREEN;
    if (strcmp("BLUE", s) == 0) return BLUE;
    if (strcmp("WHITE", s) == 0) return WHITE;
    if (strcmp("CYAN", s) == 0) return CYAN;
    if (strcmp("MAGENTA", s) == 0) return MAGENTA;
    if (strcmp("YELLOW", s) == 0) return YELLOW;
    // failsafe
    return WHITE;
}

void clear_to_black (image_t img) {
    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            img[x][y] = 0;
        }
    }
}

void show_3x5_char (image_t img, unsigned char c, rgb_t fg, rgb_t bg, uint8_t x, uint8_t y) {
    uint8_t col = 0;
    uint32_t fg_gbr = rgb2bgr32(fg);
    uint32_t bg_gbr = rgb2bgr32(bg);
    if ((x < (WIDTH - 3)) && (y < (HEIGHT - 4))) { // Don't draw outside bounds
        while (col < 3) {
            img[x + col][y + 4] = ((font_3x5[c][col] & 0b00100000) != 0) ? fg_gbr : bg_gbr;
            img[x + col][y + 3] = ((font_3x5[c][col] & 0b00010000) != 0) ? fg_gbr : bg_gbr;
            img[x + col][y + 2] = ((font_3x5[c][col] & 0b00001000) != 0) ? fg_gbr : bg_gbr;
            img[x + col][y + 1] = ((font_3x5[c][col] & 0b00000100) != 0) ? fg_gbr : bg_gbr;
            img[x + col][y]     = ((font_3x5[c][col] & 0b00000010) != 0) ? fg_gbr : bg_gbr;
            ++col;
        }
    }
}

void show_5x7_char (image_t img, unsigned char c, rgb_t fg, rgb_t bg, uint8_t x, uint8_t y) {
    uint8_t col = 0;
    uint32_t fg_gbr = rgb2bgr32(fg);
    uint32_t bg_gbr = rgb2bgr32(bg);
    if ((x < (WIDTH - 5)) && (y < (HEIGHT - 7))) { // Don't draw outside bounds
        while (col < 5) {
            img[x + col][y + 6] = ((font_5x7[c][col] & 0b01000000) != 0) ? fg_gbr : bg_gbr;
            img[x + col][y + 5] = ((font_5x7[c][col] & 0b00100000) != 0) ? fg_gbr : bg_gbr;
            img[x + col][y + 4] = ((font_5x7[c][col] & 0b00010000) != 0) ? fg_gbr : bg_gbr;
            img[x + col][y + 3] = ((font_5x7[c][col] & 0b00001000) != 0) ? fg_gbr : bg_gbr;
            img[x + col][y + 2] = ((font_5x7[c][col] & 0b00000100) != 0) ? fg_gbr : bg_gbr;
            img[x + col][y + 1] = ((font_5x7[c][col] & 0b00000010) != 0) ? fg_gbr : bg_gbr;
            img[x + col][y]     = ((font_5x7[c][col] & 0b00000001) != 0) ? fg_gbr : bg_gbr;
            ++col;
        }
    }
}

void show_6x10_char (image_t img, unsigned char c, rgb_t fg, rgb_t bg, uint8_t x, uint8_t y) {
    uint8_t col = 0;
    uint32_t fg_gbr = rgb2bgr32(fg);
    uint32_t bg_gbr = rgb2bgr32(bg);
    if ((x < (WIDTH - 3)) && (y < (HEIGHT - 4))) { // Don't draw outside bounds
        while (col < 3) {
            img[x + (col * 2)][y + 8]     = ((font_3x5[c][col] & 0b00100000) != 0) ? fg_gbr : bg_gbr;
            img[x + (col * 2)][y + 9]     = ((font_3x5[c][col] & 0b00100000) != 0) ? fg_gbr : bg_gbr;
            img[x + 1 + (col * 2)][y + 8] = ((font_3x5[c][col] & 0b00100000) != 0) ? fg_gbr : bg_gbr;
            img[x + (1 + col * 2)][y + 9] = ((font_3x5[c][col] & 0b00100000) != 0) ? fg_gbr : bg_gbr;

            img[x + (col * 2)][y + 6]     = ((font_3x5[c][col] & 0b00010000) != 0) ? fg_gbr : bg_gbr;
            img[x + (col * 2)][y + 7]     = ((font_3x5[c][col] & 0b00010000) != 0) ? fg_gbr : bg_gbr;
            img[x + 1 + (col * 2)][y + 6] = ((font_3x5[c][col] & 0b00010000) != 0) ? fg_gbr : bg_gbr;
            img[x + (1 + col * 2)][y + 7] = ((font_3x5[c][col] & 0b00010000) != 0) ? fg_gbr : bg_gbr;

            img[x + (col * 2)][y + 4]     = ((font_3x5[c][col] & 0b00001000) != 0) ? fg_gbr : bg_gbr;
            img[x + (col * 2)][y + 5]     = ((font_3x5[c][col] & 0b00001000) != 0) ? fg_gbr : bg_gbr;
            img[x + 1 + (col * 2)][y + 4] = ((font_3x5[c][col] & 0b00001000) != 0) ? fg_gbr : bg_gbr;
            img[x + (1 + col * 2)][y + 5] = ((font_3x5[c][col] & 0b00001000) != 0) ? fg_gbr : bg_gbr;

            img[x + (col * 2)][y + 2]     = ((font_3x5[c][col] & 0b00000100) != 0) ? fg_gbr : bg_gbr;
            img[x + (col * 2)][y + 3]     = ((font_3x5[c][col] & 0b00000100) != 0) ? fg_gbr : bg_gbr;
            img[x + 1 + (col * 2)][y + 2] = ((font_3x5[c][col] & 0b00000100) != 0) ? fg_gbr : bg_gbr;
            img[x + (1 + col * 2)][y + 3] = ((font_3x5[c][col] & 0b00000100) != 0) ? fg_gbr : bg_gbr;

            img[x + (col * 2)][y]         = ((font_3x5[c][col] & 0b00000010) != 0) ? fg_gbr : bg_gbr;
            img[x + (col * 2)][y + 1]     = ((font_3x5[c][col] & 0b00000010) != 0) ? fg_gbr : bg_gbr;
            img[x + 1 + (col * 2)][y]     = ((font_3x5[c][col] & 0b00000010) != 0) ? fg_gbr : bg_gbr;
            img[x + 1 + (col * 2)][y + 1] = ((font_3x5[c][col] & 0b00000010) != 0) ? fg_gbr : bg_gbr;
            ++col;
        }
    }
}

void show_block (image_t img, uint8_t x, uint8_t y, uint8_t width, uint8_t height, rgb_t col) {
    for (int ix = x; ix < x + width; ++ix) {
        for (int iy = y; iy < y + height; ++iy) {
            if ((iy < HEIGHT) && (ix < WIDTH)) img[ix][iy] = rgb2bgr32(col);
        }
    }
}

void show_3x5_string (image_t img, char msg[], uint8_t x, uint8_t y, rgb_t fg, rgb_t bg) {
    // clear background
    int w = strlen(msg) * 4; // 1 pixel gap between chars
    show_block(img, x, y, w, 5, bg);
    for (unsigned int ix = 0; ix < strlen(msg); ++ix) {
        show_3x5_char(img, msg[ix], fg, bg, x + (ix * 4), y);
    }
}

void show_5x7_string (image_t img, char msg[], uint8_t x, uint8_t y, rgb_t fg, rgb_t bg) {
    // clear background
    int w = strlen(msg) * 6; // 1 pixel gap between chars
    show_block(img, x, y, w, 7, bg);
    for (unsigned int ix = 0; ix < strlen(msg); ++ix) {
        show_5x7_char(img, msg[ix], fg, bg, x + (ix * 6), y);
    }
}

void show_6x10_string (image_t img, char msg[], uint8_t x, uint8_t y, rgb_t fg, rgb_t bg) {
    // clear background
    int w = strlen(msg) * 8; // 2 pixel gap between chars
    show_block(img, x, y, w, 10, bg);
    for (unsigned int ix = 0; ix < strlen(msg); ++ix) {
        show_6x10_char(img, msg[ix], fg, bg, x + (ix * 8), y);
    }
}

void dim (image_t img, int div) {
    rgb_t rgb;
    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            rgb = bgr322rgb(img[x][y]);
            rgb.r /= div;
            rgb.g /= div;
            rgb.b /= div;
            img[x][y] = rgb2bgr32(rgb);
        }
    }
}