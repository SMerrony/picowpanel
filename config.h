/**
 * SPDX-FileCopyrightText: 2023 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CONFIG_H
#define CONFIG_H

// PANEL_SIZE should be 6464 or 6432
#define PANEL_SIZE 6432
// #define PANEL_SIZE 6464

// Define ONE of the following (see also info_items.c)
#define CLOCK1
// #define CLOCK2
// #define INFOPANEL1

#ifdef CLOCK1
    #define MQTT_CLIENT_ID "PicowClock1"
    #define MQTT_CONTROL_TOPIC "rgbmatrix/control4"
#endif
#ifdef CLOCK2
    #define MQTT_CLIENT_ID "PicowClock2"
    #define MQTT_CONTROL_TOPIC "rgbmatrix/control2"
#endif
#ifdef INFOPANEL1
    #define MQTT_CLIENT_ID "PicowPanel1"
    #define MQTT_CONTROL_TOPIC "rgbmatrix/control1"
#endif

#endif