// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku
// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 2 of the License, or (at your option)
// any later version. This program is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
// Public License for more details. You should have received a copy of the GNU
// General Public License along with this program. If not, see
// <http://www.gnu.org/licenses/>.

#pragma once

// LAYOUT_miryoku — maps Miryoku's 36-key layout onto the Iris Rev8 (56 keys).
//
// The Iris has 6 columns per side; Miryoku uses the inner 5.  The outer
// pinky column on each side is filled with KC_NO.  Row 3 (the Iris's extra
// bottom alpha row) is not used by Miryoku and is also filled with KC_NO.
//
// Physical LAYOUT order (from keyboards/keebio/iris/rev8/keyboard.json):
//
//   Row 0 (12): [0,0] [0,1] [0,2] [0,3] [0,4] [0,5]  [5,5] [5,4] [5,3] [5,2] [5,1] [5,0]
//   Row 1 (12): [1,0] [1,1] [1,2] [1,3] [1,4] [1,5]  [6,5] [6,4] [6,3] [6,2] [6,1] [6,0]
//   Row 2 (12): [2,0] [2,1] [2,2] [2,3] [2,4] [2,5]  [7,5] [7,4] [7,3] [7,2] [7,1] [7,0]
//   Row 3 ( 7): [3,0] [3,1] [3,2] [3,3] [3,4] [3,5] [4,5]   (left side, includes extra thumb)
//   Row 3 ( 7): [9,5] [8,5] [8,4] [8,3] [8,2] [8,1] [8,0]   (right side)
//   Thumb L(3): [4,2] [4,3] [4,4]
//   Thumb R(3): [9,4] [9,3] [9,2]
//
// Miryoku key → Iris physical key:
//   L00-L04  →  [0,1]-[0,5]   (left  row 0, inner 5 of 6 cols, L→R)
//   R00-R04  →  [5,5]-[5,1]   (right row 0, inner 5 of 6 cols, L→R)
//   L10-L14  →  [1,1]-[1,5]
//   R10-R14  →  [6,5]-[6,1]
//   L20-L24  →  [2,1]-[2,5]
//   R20-R24  →  [7,5]-[7,1]
//   L30-L32  →  [4,2] [4,3] [4,4]   (left  thumb, outer→inner)
//   R30-R32  →  [9,4] [9,3] [9,2]   (right thumb, inner→outer)

// clang-format off
#define LAYOUT_miryoku( \
    L00, L01, L02, L03, L04,   R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14,   R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24,   R20, R21, R22, R23, R24, \
    L30, L31, L32,             R30, R31, R32             \
) \
LAYOUT( \
    KC_NO, L00,   L01,   L02,   L03,   L04,   R00,   R01,   R02,   R03,   R04,   KC_NO, \
    KC_NO, L10,   L11,   L12,   L13,   L14,   R10,   R11,   R12,   R13,   R14,   KC_NO, \
    KC_NO, L20,   L21,   L22,   L23,   L24,   R20,   R21,   R22,   R23,   R24,   KC_NO, \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    L30,   L31,   L32,                                                     R30,   R31,   R32    \
)
// clang-format on
