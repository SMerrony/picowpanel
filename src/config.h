/**
 * SPDX-FileCopyrightText: 2023,2024,2026 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#pragma once

// PANEL_SIZE should be 6464 or 6432 i.e. 64x64 or 64x32 LEDs
// #define PANEL_SIZE 6464
#define PANEL_SIZE 6432

#define BLINK_PERIOD_MS 1000 // Rate of blink (used for Urgent msgs etc.)

// Define ONE of the following (see also info_items.c)
// #define CLOCK_MUSIC // Music Room
// #define CLOCK2 // Actually used by picotftpanel 
// #define CLOCK_BATHROOM 
#define CLOCK_KITCHEN 

#ifdef CLOCK_MUSIC
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
#ifdef CLOCK_KITCHEN
    #define MQTT_CLIENT_ID "PicowClock5"
    #define MQTT_CONTROL_TOPIC "rgbmatrix/control_kitchen"
#endif
#ifdef INFOPANEL1
    #define MQTT_CLIENT_ID "PicowPanel1"
    #define MQTT_CONTROL_TOPIC "rgbmatrix/control1"
#endif

// Do not define this if not incorporating a DHT Temp/Hum sensor
#define USE_DHT

#ifdef USE_DHT
    #define DHT_PIN 17            // GPIO17 - physical pin 22
    #define DHT_SAMPLE_PERIOD 120 // multiply by BLINK_PERIOD_MS to get real period
    #define DHT_TEMP_OFFSET -0.3  // Some units need calibration and an offset applied
    #define DHT_HUM_OFFSET 0
#endif
