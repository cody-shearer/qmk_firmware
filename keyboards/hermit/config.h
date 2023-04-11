/*
 * Copyright 2020 Richard Titmuss <richard.titmuss@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define EE_HANDS
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

#define TAPPING_TERM 200

#define PERMISSIVE_HOLD

#define DIODE_DIRECTION COL2ROW
#define IGNORE_MOD_TAP_INTERRUPT

#define MATRIX_ROW_PINS { D4, C6, D7, E6, B6}
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3 }

#define USE_SERIAL
#define SOFT_SERIAL_PIN D2
#define DEBOUNCE 5
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 7
#define ENCODERS_PAD_A { B5 }
#define ENCODERS_PAD_B { B4 }

