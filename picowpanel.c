/**
 * SPDX-FileCopyrightText: 2023 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "pico/multicore.h"
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/gpio.h"
#include "hardware/pio.h"

#include "display.h"
#include "info_items.h"
#include "mqtt.h"
#include "rgbmatrix.h"
#include "wifi_config.h"

#include "rgb_led_config.h"


static image_t * image_ptr;

int main() {
    stdio_init_all();

    busy_wait_ms(5000); // DEBUGGING - time to connect terminal

    while (cyw43_arch_init_with_country(WIFI_COUNTRY) != 0) {
        printf("ERROR: WiFi failed to initialise - will retry in 5s\n");
        busy_wait_ms(5000);
    }
    
    cyw43_arch_enable_sta_mode();

    while (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASS, CYW43_AUTH_WPA2_AES_PSK, WIFI_TIMEOUT_MS) != 0) {
        printf("ERROR: Wifi failed to connect - will retry in 5s\n");
        busy_wait_ms(5000);
    }

    /* N.B. The following power management call is critical if you want to achieve smooth
            running w.r.t. MQTT message handling.  Without it, reception appears to stall
            approximately every 3 seconds. */
    int ps = cyw43_wifi_pm(&cyw43_state, cyw43_pm_value(CYW43_NO_POWERSAVE_MODE, 20, 1, 1, 1));
    printf("DEBUG: cyw43_wifi_pm returned: %d\n", ps);

    printf("DEBUG: Wifi connected\n");
    
    image_ptr = core1_setup();

    ii_setup(image_ptr);

    multicore_launch_core1(core1_entry);

    mqtt_setup_client();
    mqtt_connect();

    printf("DEBUG: Connected to MQTT broker\n");

    bool flash_toggle = false;
    while (1) {
        busy_wait_ms(1000);
        flash_toggle = !flash_toggle;
        if (flash_toggle) show_urgent(); else hide_urgent();
    }

}
