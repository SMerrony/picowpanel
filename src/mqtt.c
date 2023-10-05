/**
 * SPDX-FileCopyrightText: 2023 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mqtt.h"

#include "string.h"
#include "pico/cyw43_arch.h"
#include "pico/time.h"

#include "info_items.h"

mqtt_client_t *client;
ip_addr_t broker_addr;

void mqtt_setup_client() {
    client = mqtt_client_new();
    if (client == NULL) {
        printf("ERROR: Could not allocation new MQTT client\n");
    }
}

int inpub_id;

static void mqtt_incoming_publish_cb( __attribute__((unused)) void *arg, 
                                      const char *topic, 
                                      __attribute__((unused)) u32_t tot_len) {
    inpub_id = ID_UNKNOWN;
    if(strcmp(topic, URGENT_TOPIC) == 0) {
        inpub_id = ID_URGENT;
        return;
    } 
    for (int i = 0; i < INFO_ITEM_COUNT; ++i) {
        if (strcmp(topic, info_items[i].topic) == 0) {
            inpub_id = i;
            // printf("DEBUG: Matched topic >>>%s<<< ID: %d\n", info_items[i].topic, inpub_id);
            return;
        }
    }
    if(strcmp(topic, MQTT_CONTROL_TOPIC) == 0) {
        inpub_id = ID_CONTROL;
        return;
    } 
    // printf("DEBUG: Unmatched topic >>>%s<<< - ignoring\n", topic);
}

static void mqtt_incoming_data_cb(__attribute__((unused)) void *arg, const u8_t *data, u16_t len, u8_t flags) {
    char payload[MQTT_VAR_HEADER_BUFFER_LEN];
    // printf("DEBUG: Incoming data payload with length %d, flags %u\n", len, (unsigned int)flags);
    if (inpub_id != ID_UNKNOWN) {
        if(flags & MQTT_DATA_FLAG_LAST) {
            /* Last fragment of payload received (or whole part if payload fits receive buffer
               See MQTT_VAR_HEADER_BUFFER_LEN)  */
            strncpy((char *)&payload, (const char *)data, (size_t) len);
            payload[len] = '\0';
            show_data(inpub_id, payload, len);
            // printf("DEBUG: Payload: %s\n", payload); 
        } else {
            printf("WARNING: Received fragmented MQTT payload - ignoring it\n");
        }
    } 
}

static void mqtt_sub_request_cb(__attribute__((unused)) void *arg, err_t result) {
    printf("DEBUG: Subscribe result: %d\n", result);
}

static void mqtt_connection_cb(mqtt_client_t *client, void *arg, mqtt_connection_status_t status) {
    err_t err;
    if(status == MQTT_CONNECT_ACCEPTED) {
        printf("DEBUG: mqtt_connection_cb: Successfully connected\n");
        /* Setup callback for incoming publish requests */
        mqtt_set_inpub_callback(client, mqtt_incoming_publish_cb, mqtt_incoming_data_cb, arg);

        cyw43_arch_lwip_begin(); /* start section for to lwIP access */
        err = mqtt_subscribe(client, TOPIC, 0, mqtt_sub_request_cb, arg);
        cyw43_arch_lwip_end(); /* end section accessing lwIP */

        if(err != ERR_OK) {
            printf("ERROR: mqtt_subscribe return: %d\n", err);
        }
    } else {
        printf("ERROR: MQTT connection CB got code %d - will retry in 10s\n", status);
        busy_wait_ms(10000);    // wait 10s and retry
        mqtt_connect();
    }
}

void mqtt_connect() {
    struct mqtt_connect_client_info_t ci;
    err_t err;
  
    /* Setup an empty client info structure */
    memset(&ci, 0, sizeof(ci));

    ci.client_id = MQTT_CLIENT_ID;
    ci.keep_alive = BROKER_KEEPALIVE;

    if (!ip4addr_aton(BROKER_HOST, &broker_addr)) {
        printf("ERROR: Could not resolve MQTT Broker address\n");
        return;
    }
    cyw43_arch_lwip_begin(); /* start section for to lwIP access */
    err = mqtt_client_connect(client, &broker_addr, BROKER_PORT, mqtt_connection_cb, 0, &ci);
    cyw43_arch_lwip_end(); /* end section accessing lwIP */

    if(err == ERR_OK) {
        printf("DEBUG: mqtt_connect OK\n");
    } else {
        printf("ERROR: mqtt_connect return %d\n", err);
        sleep_ms(10000);    // wait 10s and retry
        mqtt_connect();
    }
}

bool mqtt_connected() {
    if (mqtt_client_is_connected(client) == 1)
        return true;
    else
        return false;
}