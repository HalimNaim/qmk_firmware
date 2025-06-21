// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define CT_ESC LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *
     * ┌───┬───┬───┬───┬───┬───┐    ┌───┬───┬───┬───┬───┬───┬───┐    ┌───┬───┬───┬───┬───┬───┐
     * │ X │ X │ X │ X │ X │ X │    │ X │ X │ X │ X │ X │ X │ X │    │ X │ X │ X │ X │ X │ X │
     * ├───┼───┼───┼───┤───┼───┤    ├───┼───┼───┼───┤───┤───┼───┤    ├───┼───┼───┼───┤───┼───┤
     * │ X │ X │ X │ X │ X │ X │    │ X │ X │ X │ X │ X │ X │ X │    │ X │ X │ X │ X │ X │ X │
     * │───│───│───│───│───│───│    │───│───│───│───│───│───│───│    │───│───│───│───│───│───│
     * │ X │ X │ X │ X │ X │ X │    │ X │ X │ X │ X │ X │ X │ X │    │ X │ X │ X │ X │ X │ X │
     * ├───┼───┼───┼───┤───┼───┤    ├───┼───┼───┼───┤───┤───┼───┤    ├───┼───┼───┼───┤───┼───┤
     * │ X │ X │ X │ X │ X │ X │    │ X │ X │ X │ X │ X │ X │ X │    │ X │ X │ X │ X │ X │ X │
     * ├───┼───┼───┼───┤───┼───┤    └───┴───┴───┴───┴───┴───┴───┘    ├───┼───┼───┼───┤───┼───┤
     * │   │ X │ X │ X │ X │ X │                                     │ X │ X │ X │ X │ X │   │
     * │ X │───┼───┼───┤───┼───┘                                     └───┼───┼───┼───┼───┼ X ┤
     * │   │ X │ X │ X │ X │                                             │ X │ X │ X │ X │   │
     * └───┴───┴───┴───┴───┘                                             └───┴───┴───┴───┴───┘
     *
     *                              ┌───┬───┬───┐   ┌───┬───┬───┐
     *                              │ X │ X │ X │   │ X │ X │ X │
     *                              ├───┼───┼───┤   ├───┼───┼───┤
     *                              │   │ X │ X │   │ X │ X │   │
     *                              │ X ├───┼───┤   ├───┼───┤ X │
     *                              │   │ X │ X │   │ X │ X │   │
     *                              └───┴───┴───┘   └───┴───┴───┘
     */
    [0] = LAYOUT(
          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    QK_BOOT,    KC_0,    KC_0,    KC_0,    KC_0,    KC_0,    KC_0,      KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
         KC_EQL,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
         KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_2,    KC_2,    KC_2,    KC_2,    KC_2,    KC_2,    KC_2,       KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSLS,
         KC_ESC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,       KC_3,    KC_3,    KC_3,    KC_3,    KC_3,    KC_3,    KC_3,       KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                                                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_LSFT,
                  KC_GRV, KC_BSLS, KC_LEFT, KC_RGHT,                                                                                          KC_UP, KC_DOWN, KC_LBRC, KC_RBRC,         
                                                                 KC_LGUI, KC_LALT, KC_LCTL,   KC_NO, KC_LCTL, KC_LALT, KC_LGUI,
                                                                 KC_BSPC, KC_LPRN,    KC_7,   KC_NO,    KC_7, KC_RPRN,  KC_SPC,
                                                                          CW_TOGG,    KC_8,             KC_8,  KC_ENT          
    )
};
