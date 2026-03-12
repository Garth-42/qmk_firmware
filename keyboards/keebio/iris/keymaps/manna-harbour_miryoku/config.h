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

// LAYOUT_miryoku — maps Miryoku's 40-key layout onto the Iris Rev8 (56 keys).
//
// Miryoku uses a 4-row model (10 keys per row = 40 total):
//   Row 0  K00-K04 | K05-K09  → Iris row 1 (inner 5 cols each side; row 0 unused)
//   Row 1  K10-K14 | K15-K19  → Iris row 2
//   Row 2  K20-K24 | K25-K29  → Iris row 3
//   Row 3  N30 N31 K32 K33 K34 | K35 K36 K37 N38 N39
//             └──unused──┘ └─left thumb─┘ └─right thumb─┘ └unused┘
//
// Iris Rev8 LAYOUT order (56 keys, from keyboard.json):
//   Row 0 (12): [0,0-5]  [5,5-0]        ← all KC_NO (top row unused)
//   Row 1 (12): [1,0-5]  [6,5-0]        ← outer cols KC_NO, inner 5 = K00-K09
//   Row 2 (12): [2,0-5]  [7,5-0]        ← outer cols KC_NO, inner 5 = K10-K19
//   Row 3 (14): [3,0-5][4,5]  [9,5][8,5-0]  ← outer+extra-thumb KC_NO, inner 5 = K20-K29
//   Thumb  (6): [4,2][4,3][4,4]  [9,4][9,3][9,2]  → K32 K33 K34 | K35 K36 K37
//
// This macro is identical in structure to the one in miryoku_qmk for Iris
// rev6/rev7, which share the same 56-key physical layout as rev8.

// Compatibility aliases — Miryoku's userspace (from miryoku_qmk, an older QMK
// fork) still uses pre-rename keycodes.  Current QMK dropped the old aliases.
// Mouse: KC_BTN/KC_MS_/KC_WH_ → MS_*
#define KC_BTN1 MS_BTN1
#define KC_BTN2 MS_BTN2
#define KC_BTN3 MS_BTN3
#define KC_MS_U MS_UP
#define KC_MS_D MS_DOWN
#define KC_MS_L MS_LEFT
#define KC_MS_R MS_RGHT
#define KC_WH_U MS_WHLU
#define KC_WH_D MS_WHLD
#define KC_WH_L MS_WHLL
#define KC_WH_R MS_WHLR
// RGB: RGB_* → RM_*
#define RGB_TOG RM_TOGG
#define RGB_MOD RM_NEXT
#define RGB_HUI RM_HUEU
#define RGB_SAI RM_SATU
#define RGB_VAI RM_VALU

// Old Miryoku declares key_overrides as a pointer (const key_override_t **),
// but current QMK expects an array for ARRAY_SIZE().  The computed size (1)
// happens to be correct for Miryoku's single override, so suppress the warning.
#pragma GCC diagnostic ignored "-Wsizeof-pointer-div"

// clang-format off
#define XXX KC_NO

#define LAYOUT_miryoku(\
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09,\
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19,\
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29,\
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39\
)\
LAYOUT(\
XXX, XXX, XXX, XXX, XXX, XXX,                XXX, XXX, XXX, XXX, XXX, XXX,\
XXX, K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, XXX,\
XXX, K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, XXX,\
XXX, K20, K21, K22, K23, K24, XXX,      XXX, K25, K26, K27, K28, K29, XXX,\
                    K32, K33, K34,      K35, K36, K37\
)
// clang-format on
