/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    NUMB,  // numbers
    MOUSE,  // media keys
};

enum combos {
  JK_ESC,
  TO_MOUSE,
  TO_DEFAULT,
};

const uint16_t PROGMEM jk_combo[] = {RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM mouse_combo[] = {LT(NUMB, KC_RGHT), OSL(SYMB), COMBO_END};
const uint16_t PROGMEM default_combo[] = {LCTL(KC_RGHT), KC_VOLU, COMBO_END};

combo_t key_combos[] = {
  [JK_ESC] = COMBO(jk_combo, KC_ESC),
  [TO_MOUSE] = COMBO(mouse_combo, TO(MOUSE)),
  [TO_DEFAULT] = COMBO(default_combo, TO(BASE)),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,           XXXXXXX,
        XXXXXXX, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,    XXXXXXX,             XXXXXXX,    KC_Y, KC_U,           KC_I,           KC_O,           KC_P,              XXXXXXX,
        XXXXXXX, LALT_T(KC_A), LGUI_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,    XXXXXXX,             XXXXXXX,    KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RGUI_T(KC_L), RALT_T(KC_SCLN), XXXXXXX,
        XXXXXXX, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                     KC_N, KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,           XXXXXXX,
        XXXXXXX, XXXXXXX,        XXXXXXX,        KC_LEFT,        LT(NUMB, KC_RGHT),       XXXXXXX,             XXXXXXX,          OSL(SYMB),      KC_DOWN,        XXXXXXX,        XXXXXXX,           XXXXXXX,
                                                                 KC_SPC,         XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, KC_ENT
    ),

    [SYMB] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______,  _______, _______,
        _______, KC_GRV,  KC_AMPR, KC_LPRN, KC_RPRN, KC_DLR,  _______,             _______, KC_AT,   KC_CIRC, KC_ASTR, KC_UNDS,  KC_TILD, _______,
        _______, KC_QUOT, KC_PIPE, KC_LCBR, KC_RCBR, KC_PERC, _______,             _______, _______, KC_PLUS, KC_EQL,  KC_MINUS, KC_PLUS, _______,
        _______, KC_DQT,  KC_EXLM, KC_LBRC, KC_RBRC, KC_HASH,                               _______, KC_UP,   KC_LT,   KC_GT,    KC_BSLS, _______,
        _______, _______, _______, _______, OSL(NUMB),        _______,             _______,         TO(BASE), _______, _______,  _______, _______,
                                            _______, _______, _______,             _______,_______, _______
    ),

    [NUMB] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______,   _______,         _______, _______, _______, _______, _______, _______,  _______,
        _______, _______, _______,   _______, _______, _______, _______,           _______, CW_TOGG,   KC_7,    KC_8,    KC_9,    _______, _______,
        _______, _______, _______,  _______, _______, _______,  _______,           _______, KC_0,      KC_4,    KC_5,    KC_6,    KC_BSPC, _______,
        _______, _______, _______, _______, _______, _______,                             _______,     KC_1,    KC_2,    KC_3,    KC_TAB, _______,
        _______,  _______, _______, _______, _______,          _______,           _______,          _______, _______,  _______,    KC_EQL,  _______,
                                            _______, _______, _______,            _______,_______, _______
    ),

    [MOUSE] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______,  _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_VAI,   _______, _______, _______, DT_UP,    _______,        _______, _______, KC_PGUP, LGUI(KC_EQL), LGUI(KC_MINUS), _______, _______,
        _______, RGB_VAD, KC_MPLY, KC_PGDN, _______, DT_PRNT, _______,           _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
        _______, _______, KC_F12,  _______, _______, DT_DOWN,                             KC_MNXT, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, LCTL(KC_LEFT), LCTL(KC_RGHT),_______,         _______,         KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            TO(BASE), _______, _______,          _______, KC_BTN2, KC_BTN1
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_J):
        case LSFT_T(KC_F):
            return TAPPING_TERM - 5;
        case RCTL_T(KC_K):
        case LCTL_T(KC_D):
            return TAPPING_TERM + 10;
        case LGUI_T(KC_S):
        case RGUI_T(KC_L):
        case RALT_T(KC_SCLN):
        case LALT_T(KC_A):
            return TAPPING_TERM + 40;
        default:
            return TAPPING_TERM;
    }
}

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     switch(get_highest_layer(layer_state|default_layer_state)) {
//         case 3:
//             rgb_matrix_set_color_all(RGB_BLUE);
//             break;
//         case 2:
//             rgb_matrix_set_color_all(RGB_RED);
//             break;
//         case 1:
//             rgb_matrix_set_color_all(RGB_PURPLE);
//             break;
//         default:
//             rgb_matrix_set_color_all(RGB_WHITE);
//             break;
//     }
//     return false;
// }
