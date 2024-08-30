/**
 * SPDX-FileCopyrightText: 2023,2024 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#pragma once

// PANEL_SIZE should be 6464 or 6432
// #define PANEL_SIZE 6432
#define PANEL_SIZE 6432

// Define ONE of the following (see also info_items.c)
// #define CLOCK1
// #define CLOCK2 // Actually used by picotftpanel 
#define CLOCK3
// #define INFOPANEL1

#ifdef CLOCK1
    #define MQTT_CLIENT_ID "PicowClock1"
    #define MQTT_CONTROL_TOPIC "rgbmatrix/control4"
#endif
#ifdef CLOCK2
    #define MQTT_CLIENT_ID "PicowClock2"
    #define MQTT_CONTROL_TOPIC "rgbmatrix/control2"
#endif
#ifdef CLOCK3
    #define MQTT_CLIENT_ID "PicowClock3"
    #define MQTT_CONTROL_TOPIC "rgbmatrix/control3"
#endif
#ifdef INFOPANEL1
    #define MQTT_CLIENT_ID "PicowPanel1"
    #define MQTT_CONTROL_TOPIC "rgbmatrix/control1"
#endif
