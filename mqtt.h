/**
 * SPDX-FileCopyrightText: 2023 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MQTT_H
#define MQTT_H

#include "lwip/apps/mqtt.h"

#define CLIENT_ID "PicowClock1"
#define BROKER_HOST "192.168.1.10"
#define BROKER_PORT 1883
#define BROKER_KEEPALIVE 60
#define TOPIC         "rgbmatrix/#"         // <== This is what we subscribe to
#define URGENT_TOPIC  "rgbmatrix/urgent"
#define CONTROL_TOPIC "rgbmatrix/control4"

// User topics are matched to IDs 0 .. n
#define ID_UNKNOWN -1
#define ID_CONTROL 998
#define ID_URGENT 999

void mqtt_setup_client();
void mqtt_connect();

#endif