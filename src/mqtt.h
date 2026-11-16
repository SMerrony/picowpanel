/**
 * SPDX-FileCopyrightText: 2023-2026 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#pragma once

#include "lwip/apps/mqtt.h"

#include "config.h"

#define BROKER_HOST "192.168.1.11"
#define BROKER_PORT 1883
#define BROKER_USER "mqtt"
#define BROKER_PASS "mqtt"
#define BROKER_KEEPALIVE 60
#define TOPIC          "rgbmatrix/#"         // <== This is what we subscribe to
#define URGENT_TOPIC   "rgbmatrix/urgent"
#define TEMP_TOPIC     "rgbmatrix/Kitchen/temperature"
#define HUMIDITY_TOPIC "rgbmatrix/Kitchen/humidity"

// User topics are matched to IDs 0 .. n
#define ID_UNKNOWN -1
#define ID_CONTROL 998
#define ID_URGENT 999

void mqtt_setup_client();
void mqtt_connect();
bool mqtt_connected();

#ifdef USE_DHT
void publish_sensors(float temp, float hum);
#endif