# PicowPanel
An MQTT-driven Pico W-based information panel using a HUB75 RGB LED matrix display.

The code has been tested with both 64x64 and 64x32 panels.

A lot of the code is shared with my similar PicowTFTPanel project.

```mermaid
---
title: Typical HA Setup
---
flowchart LR
    I[Internet] --- | | R[Node-Red / HomeAssistant]
    L[LAN] --- R
    Z[Zigbee2MQTT] --- M
    R ---| |M((MQTT Broker))
    M ---| |P[PicowPanel]
    M ---| |PT[PicowTFTPanel]
```

## Configuration

Rename the `dummy_wifi_config.h` to `wifi_config.h` and edit it to suit your WiFi setup.

* `config.h` has some basic definitions used throughout the code
* `info_items.h` has the specific display items and their MQTT topics
* `mqtt.h` contains the high-level MQTT connection details
* `rgb_led_config.h` includes the pin connections and dimensions of the display

## Build

The usual process for CMake...

* mkdir build
* cd build
* cmake ..
* make
 
Only the last step is required after the first build.

## Deploy

Either restart the Pico in BOOTSEL mode and drag-and-drop the picowpanel.uf2 file to it, or, 
from a command line: `sudo picotool load -f picowpanel.uf2`

