/**
 * SPDX-FileCopyrightText: 2023 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * ==========================================================================================
 * RENAME THIS FILE TO "wifi_config.h" AND CHANGE THE CONNECTION DETAILS TO SUIT YOUR NETWORK
 * ==========================================================================================
 */

#ifndef WIFI_CONFIG_H
#define WIFI_CONFIG_H

#include "pico/cyw43_arch.h"

#define WIFI_SSID "<YOUR WiFi SSID>"
#define WIFI_PASS "<YOUR WiFi PASSWORD>"
#define WIFI_COUNTRY CYW43_COUNTRY_FRANCE
#define WIFI_TIMEOUT_MS 10000

#endif