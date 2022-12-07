
#pragma once

#include "config_common.h"

#define EE_HANDS
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

#define TAPPING_TERM 200

#define PERMISSIVE_HOLD

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

