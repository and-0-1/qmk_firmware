#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _SYMB = 1,
    _NUMB = 2,
    _MOUSE = 3,
};


const uint16_t PROGMEM jk_combo[] = {RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM mouse_combo[] = {LT(_NUMB, KC_RGHT), OSL(_SYMB), COMBO_END};
const uint16_t PROGMEM mouse_esc_combo[] = {KC_MS_D, KC_MS_U, COMBO_END};
const uint16_t PROGMEM default_combo[] = {LCTL(KC_RGHT), KC_BTN1, COMBO_END};

combo_t key_combos[] = {
    COMBO(jk_combo, KC_ESC),
    COMBO(mouse_esc_combo, TO(_BASE)),
    COMBO(mouse_combo, TO(_MOUSE)),
    COMBO(default_combo, TO(_BASE)),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                      KC_Y,   KC_U,         KC_I,         KC_O,         KC_P,
        LALT_T(KC_A), LGUI_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,                      KC_H,   RSFT_T(KC_J), RCTL_T(KC_K), RGUI_T(KC_L), RALT_T(KC_SCLN),
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,                      KC_N,   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                                                  KC_LEFT,   LT(_NUMB, KC_RGHT), KC_SPC,    KC_ENT, OSL(_SYMB), KC_DOWN
    ),
    [_SYMB] = LAYOUT_split_3x5_3(
         KC_GRV,  KC_AMPR, KC_LPRN, KC_RPRN, KC_DLR,                         KC_AT,   KC_CIRC, KC_ASTR, KC_UNDS,  KC_TILD,
         KC_QUOT, KC_PIPE, KC_LCBR, KC_RCBR, KC_PERC,                        _______, KC_PLUS, KC_EQL,  KC_MINUS, KC_PLUS,
         KC_DQT,  KC_EXLM, KC_LBRC, KC_RBRC, KC_HASH,                        KC_UP, _______,   KC_LT,   KC_GT,    KC_BSLS,
                                    _______, TO(_BASE), _______,    _______, TO(_BASE), _______
    ),
    [_NUMB] = LAYOUT_split_3x5_3(
         _______,   _______, _______, _______, _______,                     CW_TOGG,   KC_7,    KC_8,    KC_9,    KC_BSLS,
         _______,  _______, _______, _______,  _______,                     KC_0,      KC_4,    KC_5,    KC_6,    KC_BSPC,
         _______, _______, _______, _______,   _______,                     _______,     KC_1,    KC_2,    KC_3,    KC_TAB,
                                    _______, _______, _______,      _______,_______, _______
    ),

    [_MOUSE] = LAYOUT_split_3x5_3(
         _______,   _______, _______, KC_VOLU, DT_UP,                       _______, _______, LGUI(KC_EQL), LGUI(KC_MINUS), KC_MPRV,
         _______, KC_MPLY, _______, KC_VOLD, DT_PRNT,                       _______, TO(_BASE), TO(_BASE), _______, _______,
         _______, KC_F12,  _______, _______, DT_DOWN,                       KC_MNXT, KC_MUTE, _______, _______, _______,
                            _______, _______,TO(_BASE),             _______, _______, _______
    ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NUMB, KC_RGHT):
        case OSL(_SYMB):
            return TAPPING_TERM - 30;
        case RSFT_T(KC_J):
        case LSFT_T(KC_F):
            return TAPPING_TERM - 20;
        default:
            return TAPPING_TERM;
    }
}
