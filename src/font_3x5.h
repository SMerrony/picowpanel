/**
 * SPDX-FileCopyrightText: 2023,2024 Stephen Merrony
 * SPDX-License-Identifier: BSD-3-Clause
 */

#pragma once

#include <stdint.h>

const uint8_t font_3x5 [128][3] = {
    { 0, 0, 0 }, // 0
    { 0x02, 0x05, 0x02 }, // 1 - degree symbol
    { 0, 0, 0 }, // 2
    { 0, 0, 0 }, // 3
    { 0, 0, 0 }, // 4
    { 0, 0, 0 }, // 5
    { 0, 0, 0 }, // 6
    { 0, 0, 0 }, // 7
    { 0, 0, 0 }, // 8
    { 0, 0, 0 }, // 9
    { 0, 0, 0 }, // 10
    { 0, 0, 0 }, // 11
    { 0, 0, 0 }, // 12
    { 0, 0, 0 }, // 13
    { 0, 0, 0 }, // 14
    { 0, 0, 0 }, // 15
    { 0, 0, 0 }, // 16
    { 0, 0, 0 }, // 17
    { 0, 0, 0 }, // 18
    { 0, 0, 0 }, // 19
    { 0, 0, 0 }, // 20
    { 0, 0, 0 }, // 21
    { 0, 0, 0 }, // 22
    { 0, 0, 0 }, // 23
    { 0, 0, 0 }, // 24
    { 0, 0, 0 }, // 25
    { 0, 0, 0 }, // 26
    { 0, 0, 0 }, // 27
    { 0, 0, 0 }, // 28
    { 0, 0, 0 }, // 29
    { 0, 0, 0 }, // 30
    { 0, 0, 0 }, // 31
    { 0x00, 0x00, 0x00 },
    { 0x00, 0x2e, 0x00 }, //  !
    { 0x06, 0x00, 0x06 }, //  "
    { 0x3e, 0x14, 0x3e }, //  #
    { 0x0c, 0x36, 0x18 }, //  $
    { 0x32, 0x08, 0x26 }, //  %
    { 0x14, 0x2a, 0x34 }, //  &
    { 0x00, 0x06, 0x00 }, //  '
    { 0x00, 0x1c, 0x22 }, //  (
    { 0x22, 0x1c, 0x00 }, //  )
    { 0x14, 0x08, 0x14 }, //  *
    { 0x08, 0x1c, 0x08 }, //  +
    { 0x40, 0x60, 0x00 }, //  ,
    { 0x08, 0x08, 0x08 }, //  -
    { 0x00, 0x20, 0x00 }, //  .
    { 0x60, 0x18, 0x06 }, //  /
    { 0x3e, 0x22, 0x3e }, //  0
    { 0x24, 0x3e, 0x20 }, //  1
    { 0x3a, 0x2a, 0x2e }, //  2
    { 0x22, 0x2a, 0x3e }, //  3
    { 0x0e, 0x08, 0x3e }, //  4
    { 0x2e, 0x2a, 0x3a }, //  5
    { 0x3e, 0x2a, 0x3a }, //  6
    { 0x02, 0x02, 0x3e }, //  7
    { 0x3e, 0x2a, 0x3e }, //  8
    { 0x2e, 0x2a, 0x3e }, //  9
    { 0x00, 0x14, 0x00 }, //  :
    { 0x40, 0x64, 0x00 }, //  ;
    { 0x08, 0x14, 0x22 }, //  <
    { 0x14, 0x14, 0x14 }, //  =
    { 0x22, 0x14, 0x08 }, //  >
    { 0x02, 0x2a, 0x06 }, //  ?
    { 0x3e, 0x22, 0x2e }, //  @
    { 0x3e, 0x0a, 0x3e }, //  A
    { 0x3e, 0x2a, 0x14 }, //  B
    { 0x3e, 0x22, 0x22 }, //  C
    { 0x3e, 0x22, 0x1c }, //  D
    { 0x3e, 0x2a, 0x22 }, //  E
    { 0x3e, 0x0a, 0x02 }, //  F
    { 0x3e, 0x22, 0x3a }, //  G
    { 0x3e, 0x08, 0x3e }, //  H
    { 0x22, 0x3e, 0x22 }, //  I
    { 0x30, 0x20, 0x3e }, //  J
    { 0x3e, 0x08, 0x36 }, //  K
    { 0x3e, 0x20, 0x20 }, //  L
    { 0x3e, 0x04, 0x3e }, //  M
    { 0x3c, 0x08, 0x1e }, //  N
    { 0x3e, 0x22, 0x3e }, //  O
    { 0x3e, 0x0a, 0x0e }, //  P
    { 0x3e, 0x22, 0x7e }, //  Q
    { 0x3e, 0x0a, 0x34 }, //  R
    { 0x2e, 0x2a, 0x3a }, //  S
    { 0x02, 0x3e, 0x02 }, //  T
    { 0x3e, 0x20, 0x3e }, //  U
    { 0x1e, 0x20, 0x1e }, //  V
    { 0x3e, 0x10, 0x3e }, //  W
    { 0x36, 0x08, 0x36 }, //  X
    { 0x06, 0x38, 0x06 }, //  Y
    { 0x32, 0x2a, 0x26 }, //  Z
    { 0x00, 0x3e, 0x22 }, //  [
    { 0x02, 0x1c, 0x60 }, //  "\"
    { 0x22, 0x3e, 0x00 }, //  ]
    { 0x04, 0x02, 0x04 }, //  ^
    { 0x40, 0x40, 0x40 }, //  _
    { 0x00, 0x02, 0x00 }, //  `
    { 0x34, 0x34, 0x3c }, //  a
    { 0x3e, 0x24, 0x3c }, //  b
    { 0x3c, 0x24, 0x24 }, //  c
    { 0x3c, 0x24, 0x3e }, //  d
    { 0x3c, 0x2c, 0x2c }, //  e
    { 0x08, 0x3e, 0x0a }, //  f
    { 0x2e, 0x2a, 0x3e }, //  g
    { 0x3e, 0x08, 0x38 }, //  h
    { 0x00, 0x3a, 0x00 }, //  i
    { 0x30, 0x20, 0x3a }, //  j
    { 0x3e, 0x08, 0x34 }, //  k
    { 0x00, 0x3e, 0x00 }, //  l
    { 0x3c, 0x08, 0x3c }, //  m
    { 0x3c, 0x04, 0x3c }, //  n
    { 0x3c, 0x24, 0x3c }, //  o
    { 0x3c, 0x14, 0x08 }, //  p
    { 0x08, 0x14, 0x3c }, //  q
    { 0x3c, 0x04, 0x04 }, //  r
    { 0x2c, 0x2a, 0x1a }, //  s
    { 0x3e, 0x28, 0x20 }, //  t
    { 0x3c, 0x20, 0x3c }, //  u
    { 0x1c, 0x20, 0x1c }, //  v
    { 0x3c, 0x10, 0x3c }, //  w
    { 0x24, 0x18, 0x24 }, //  x
    { 0x2c, 0x28, 0x3c }, //  y
    { 0x34, 0x2c, 0x2c }, //  z
    { 0x08, 0x3e, 0x22 }, //  {
    { 0x00, 0x7e, 0x00 }, //  |
    { 0x22, 0x3e, 0x08 }, //  }
    { 0x02, 0x06, 0x04 }, //  ~
    { 0, 0, 0}
};
