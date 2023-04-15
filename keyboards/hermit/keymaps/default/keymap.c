/* Copyright 2020 Richard Titmuss (richard.titmuss@gmail.com)
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

#include QMK_KEYBOARD_H

enum custom_keycodes {
  _QWERTY,
  _SYMB,
  _NAV,
  _FKY,
  _GAME,
  _NUMB,
  _FNR
};

bool is_alt_tab_active = false; // ADD this near the begining of keymap.c
bool is_alt_shift_tab_active = false; // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT_split_4x6_encoder(
		KC_ESC,	KC_1,	  		KC_2,   		KC_3,   	KC_4,	  KC_5,		                KC_6,	  KC_7,	  KC_8, 	KC_9,	  KC_0,	  KC_F24,
		QK_GESC,KC_Q,	  		KC_W,	  		KC_F,	 	KC_P,	  KC_B,		                KC_J,	  KC_L,	  KC_U,	  KC_Y,	  KC_SCLN,KC_BSLS,
		KC_EQL,	KC_A,	  		KC_R,	 		KC_S,	  	KC_T,	  KC_G,		                KC_M,	  KC_N,	  KC_E,	  KC_I,	  KC_O,	  KC_QUOT,
		KC_UNDS,LGUI_T(KC_Z),	LCTL_T(KC_X),	LALT_T(KC_C),LSFT_T(KC_D),	    KC_V,   KC_MUTE,TG(_GAME),KC_K,LSFT_T(KC_H),LALT_T(KC_LT),LCTL_T(KC_GT),LGUI_T(KC_SLSH),KC_MINS,
		            LT(_FKY, KC_TAB), LT(_SYMB, KC_ENT),LT(_NAV, KC_DEL),                 LT(_NAV, KC_BSPC),LT(_SYMB, KC_SPC), CW_TOGG
	),

  [_SYMB] = LAYOUT_split_4x6_encoder(
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_GRV ,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,                KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_TRNS,
		KC_PLUS,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_TRNS,
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_LBRC,KC_RBRC,KC_TRNS,KC_TRNS,KC_LCBR,KC_RCBR,KC_LT  ,KC_GT  ,KC_TRNS,KC_TRNS,
								            KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS
    ),

  [_NAV] = LAYOUT_split_4x6_encoder(
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_PGUP,KC_LEFT,KC_UP  ,KC_RGHT,KC_TRNS,KC_TRNS,
		KC_TRNS,KC_LGUI,KC_LCTL,KC_LALT,KC_LSFT,KC_TRNS,KC_TRNS,KC_TRNS,KC_PGDN,KC_HOME,KC_DOWN,KC_END ,KC_TRNS,KC_TRNS,
							              KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS
    ),


  [_FKY] = LAYOUT_split_4x6_encoder(
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_TRNS,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_TRNS,                KC_SLEP,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_TRNS,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_TRNS,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
							            	KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS
    ),


  [_GAME] = LAYOUT_split_4x6_encoder(
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_ESC ,KC_3   ,KC_Q   ,KC_R   ,KC_E   ,KC_R   ,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_LSFT,KC_2   ,KC_A   ,KC_W   ,KC_D   ,KC_F   ,                KC_TRNS,KC_LEFT,KC_UP  ,KC_RGHT,KC_TRNS,KC_TRNS,
		KC_LCTL,KC_1   ,KC_Z   ,KC_S   ,KC_X   ,KC_C   ,KC_MUTE,TG(_GAME),KC_TRNS,KC_TRNS,KC_DOWN,KC_TRNS,KC_TRNS,KC_TRNS,
						            		KC_TAB ,KC_SPC ,KC_ENT ,                KC_TRNS,KC_TRNS,KC_TRNS
    ),


  [_NUMB] = LAYOUT_split_4x6_encoder(
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
								            KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS
    ),


  [_FNR] = LAYOUT_split_4x6_encoder(
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
		KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
								            KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS
    )
};


//ALT TAB Encoder Timer
void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active || is_alt_shift_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      unregister_code(KC_LSFT);
      is_alt_tab_active = false;
      is_alt_shift_tab_active = false;
    }
  }
};


bool encoder_update_user(uint8_t index, bool clockwise) {
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else if (index == 1) {
            if (clockwise) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
	                register_code(KC_LALT);
                }
                unregister_code(KC_LSFT);
                alt_tab_timer = timer_read();
                tap_code(KC_TAB);
            } else {
                if (!is_alt_shift_tab_active) {
                    is_alt_shift_tab_active = true;
	                register_code(KC_LALT);
                }
                register_code(KC_LSFT);
                alt_tab_timer = timer_read();
                tap_code(KC_TAB);
            }
        }
    return false;
};