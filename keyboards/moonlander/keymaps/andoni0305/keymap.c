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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,             XXXXXXX,    KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    XXXXXXX,
        XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX,             XXXXXXX,    KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, XXXXXXX,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                     KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_RGHT,          XXXXXXX,             XXXXXXX,         OSL(SYMB), KC_DOWN, XXXXXXX, XXXXXXX, XXXXXXX,
                                             KC_SPC, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, KC_ENT
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
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_SPC):
            return TAPPING_TERM + 1250;
        case LT(1, KC_GRV):
            return 130;
        default:
            return TAPPING_TERM;
    }
}
