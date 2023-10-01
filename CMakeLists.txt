# SPDX-FileCopyrightText: 2023 Stephen Merrony
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(
	picowpanel
	VERSION 0.1.0
	LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

set(PICO_BOARD pico_w)
pico_sdk_init()

add_executable(picowpanel ${SOURCES})

pico_generate_pio_header(picowpanel ${CMAKE_CURRENT_LIST_DIR}/src/hub75.pio)

target_sources(picowpanel PUBLIC
	${CMAKE_SOURCE_DIR}/src/graphics.c
	${CMAKE_SOURCE_DIR}/src/info_items.c
	${CMAKE_SOURCE_DIR}/src/rgbmatrix.c
	${CMAKE_SOURCE_DIR}/src/mqtt.c
	${CMAKE_SOURCE_DIR}/src/picowpanel.c
)


target_include_directories(picowpanel PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# target_compile_definitions(picowpanel PRIVATE
# 	PICO_DEFAULT_UART_TX_PIN=28
# 	PICO_DEFAULT_UART_RX_PIN=29
# )

target_compile_options(picowpanel PRIVATE -Werror -Wall -Wextra)

pico_enable_stdio_usb(picowpanel 1)

target_link_libraries(picowpanel 
	pico_cyw43_arch_lwip_threadsafe_background 

	pico_lwip_mqtt
	pico_stdlib 
	hardware_pio
	pico_multicore
)

pico_add_extra_outputs(picowpanel)
