/**
 * SPDX-FileCopyrightText: 2023 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/multicore.h"

#include "rgbmatrix.h"
#include "rgb_led_config.h"

#include "hub75.pio.h"

const PIO PIO_0 = pio0;
const uint SM_DATA = 0;
const uint SM_ROW = 1;
static uint data_prog_offs;
static image_t disp_image;

/* Set up the PIO stuff for the task running on the second core.
   Returns a pointer to the display image matrix. */
image_t * core1_setup() {
    data_prog_offs = pio_add_program(PIO_0, &hub75_data_rgb888_program);
    uint row_prog_offs = pio_add_program(PIO_0, &hub75_row_program);
    hub75_data_rgb888_program_init(PIO_0, SM_DATA, data_prog_offs, DATA_BASE_PIN, CLK_PIN);
    hub75_row_program_init(PIO_0, SM_ROW, row_prog_offs, ROWSEL_BASE_PIN, ROWSEL_N_PINS, STROBE_PIN);
    return &disp_image;
}

void set_blank_display(bool blank) {
    if (blank) {
        multicore_fifo_push_blocking(1);
    } else {
        multicore_fifo_push_blocking(0);
    }
}

void core1_entry() {
    static bool is_blanked = false;

    while (1) {
        for (int rowsel = 0; rowsel < SCAN; ++rowsel) {
            for (int bit = 0; bit < 8; ++bit) {
                hub75_data_rgb888_set_shift(PIO_0, data_prog_offs, bit);
                if (is_blanked) {
                    for (int x = 0; x < WIDTH; ++x) {
                        pio_sm_put_blocking(PIO_0, SM_DATA, 0);
                        pio_sm_put_blocking(PIO_0, SM_DATA, 0);                 
                    }
                } else {
                    for (int x = 0; x < WIDTH; ++x) {
                        pio_sm_put_blocking(PIO_0, SM_DATA, disp_image[x][rowsel]);
                        pio_sm_put_blocking(PIO_0, SM_DATA, disp_image[x][rowsel+SCAN]);                 
                    }
                }
                // Dummy pixel per lane
                pio_sm_put_blocking(PIO_0, SM_DATA, 0);
                pio_sm_put_blocking(PIO_0, SM_DATA, 0);
                // SM is finished when it stalls on empty TX FIFO
                hub75_wait_tx_stall(PIO_0, SM_DATA);
                // Also check that previous OEn pulse is finished, else things can get out of sequence
                hub75_wait_tx_stall(PIO_0, SM_ROW);
                // Latch row data, pulse output enable for new row.
                pio_sm_put_blocking(PIO_0, SM_ROW, rowsel | (100u * (1u << bit) << 5));
            }
        }
        // busy_wait_ms(1);
        if (multicore_fifo_rvalid()) {
            if (multicore_fifo_pop_blocking() == 1) {
                is_blanked = true;
            } else {
                is_blanked = false;
            }
        }
    }
}