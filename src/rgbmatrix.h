/**
 * SPDX-FileCopyrightText: 2023 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef RGBMATRIX_H
#define RGBMATRIX_H

#include <stdbool.h>

#include "graphics.h"

image_t * core1_setup();
void core1_entry();
void set_blank_display(bool blank);

#endif