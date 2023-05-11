#include QMK_KEYBOARD_H
#include "keymap_uk.h"


#define _COLEMAK_DH 0
#define _SYM 1
#define _NAV 2
#define _ADJUST 3

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT MT(MOD_LALT, KC_ENT)

// My Home Row Mods
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define CTL_S LCTL_T(KC_S)
#define SF_T LSFT_T(KC_T)

#define SFT_N RSFT_T(KC_N)
#define CTL_E RCTL_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O LGUI_T(KC_O) 

enum custom_keycodes {
  COLEMAK_DH = SAFE_RANGE,
  SYM,
  NAV,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK_DH] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     UK_ESC,  UK_1,    UK_2,    UK_3,    UK_4,    UK_5,                               UK_6,    UK_7,    UK_8,    UK_9,    UK_0,    UK_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     UK_TAB,  UK_Q,    UK_W,    UK_F,    UK_P,    UK_B,                               UK_J,    UK_L,    UK_U,    UK_Y,    UK_SCLN, UK_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     CTL_ESC, GUI_A,   ALT_R,   CTL_S,   SF_T,    UK_G,                               UK_M,    SFT_N,   CTL_E,   ALT_I,   GUI_O,   CTL_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     UK_LSFT, UK_Z,    UK_X,    UK_C,    UK_D,    UK_V,    UK_LBRC,          UK_RBRC, UK_K,    UK_H,    UK_COMM, UK_DOT,  UK_SLSH, UK_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    UK_LGUI, NAV,     UK_ENT,                    UK_SPC,  SYM,     UK_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RESET,   UK_EXLM, UK_AT,   UK_HASH, UK_DLR,  UK_PERC,                            UK_CIRC, UK_AMPR, UK_ASTR, UK_LPRN, UK_RPRN, UK_PGUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     UK_GRV,  UK_1,    UK_2,    UK_3,    UK_4,    UK_5,                               UK_6,    UK_7,    UK_8,    UK_9,    UK_0,    UK_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     UK_TILD, UK_EXLM, UK_DQUO, UK_HASH, UK_DLR,  UK_PERC,                            UK_CIRC, UK_AMPR, UK_ASTR, UK_LPRN, UK_RPRN, UK_PLUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     UK_PIPE, UK_BSLS, UK_COLN, UK_SCLN, UK_MINS, UK_BSLS, UK_LBRC,          UK_RBRC, UK_HASH, UK_UNDS, UK_COMM, UK_DOT,  UK_SLSH, UK_QUES,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     UK_F12,  UK_F1,   UK_F2,   UK_F3,   UK_F4,   UK_F5,                              UK_F6,   UK_F7,   UK_F8,   UK_F9,   UK_F10,  UK_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, UK_SLCK, KC_CAPS,                            UK_PGUP, UK_HOME, UK_UP,   UK_END,  KC_VOLU, UK_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, UK_LGUI, UK_LALT, UK_LCTL, UK_LSFT, _______,                            UK_PGDN, UK_LEFT, UK_DOWN, UK_RGHT, KC_VOLD, UK_INS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, KC_PAUSE,KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK_DH:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK_DH);
      }
      return false;
      break;
    case SYM:
      if (record->event.pressed) {
        layer_on(_SYM);
        update_tri_layer(_SYM, _NAV, _ADJUST);
      } else {
        layer_off(_SYM);
        update_tri_layer(_SYM, _NAV, _ADJUST);
      }
      return false;
      break;
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
        update_tri_layer(_SYM, _NAV, _ADJUST);
      } else {
        layer_off(_NAV);
        update_tri_layer(_SYM, _NAV, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
