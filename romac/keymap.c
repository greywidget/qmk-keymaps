/* Copyright 2018 Jack Humbert
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

#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
	LOWER = SAFE_RANGE,
	RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
	//┌────────┬────────┬────────┐
	   KC_7,    KC_8,    KC_9,
	//├────────┼────────┼────────┼
	   KC_4,    KC_5,    KC_6,
	//├────────┼────────┼────────┼
	   KC_1,    KC_2,    KC_3,
	//├────────┼────────┼────────┼
	   LOWER,   KC_0,    RAISE
	//└────────┴────────┴────────┘
	),

	[_LOWER] = LAYOUT(
	//┌────────┬────────┬────────┐
	   KC_A,    KC_B,    KC_C,
	//├────────┼────────┼────────┼
	   KC_D,    KC_E,    KC_F,
	//├────────┼────────┼────────┼
	   KC_G,    KC_H,    KC_I,
	//├────────┼────────┼────────┼
	   LOWER,   KC_ENT,  RAISE
	//└────────┴────────┴────────┘
	),

	[_RAISE] = LAYOUT(
	//┌────────┬────────┬────────┐
	   KC_7,    KC_8,    KC_9,
	//├────────┼────────┼────────┼
	   KC_4,    KC_5,    KC_6,
	//├────────┼────────┼────────┼
	   KC_LEFT, KC_UP,   KC_RGHT,
	//├────────┼────────┼────────┼
	   LOWER,   KC_DOWN, RAISE
	//└────────┴────────┴────────┘
	),

	[_ADJUST] = LAYOUT(
	//┌────────┬────────┬────────┐
	   KC_TRNS, KC_HOME, KC_PGUP,
	//├────────┼────────┼────────┼
	   KC_TRNS, KC_END,  KC_PGDN,
	//├────────┼────────┼────────┼
	   KC_TRNS, KC_TRNS, KC_TRNS,
	//├────────┼────────┼────────┼
	   LOWER,   KC_0,    RAISE
	//└────────┴────────┴────────┘
	)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    // case ADJUST:
    //   if (record->event.pressed) {
    //     layer_on(_ADJUST);
    //   } else {
    //     layer_off(_ADJUST);
    //   }
    //   return false;
    //   break;
  }
  return true;
}