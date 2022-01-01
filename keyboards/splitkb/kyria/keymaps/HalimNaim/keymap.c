#include QMK_KEYBOARD_H

enum layers {
    _BL,
    _MBL,
    _WNUM,
    _WSYM,
    _WFN,
    _WNAV,
    _WMS,
    _MNAV,
};

// home row mods
#define WM_LGUI LGUI_T(KC_A)
#define WM_LALT LALT_T(KC_O)
#define WM_LCTL LCTL_T(KC_E)
#define WM_LSFT LSFT_T(KC_U)

#define WM_RGUI LGUI_T(KC_S)
#define WM_RALT LALT_T(KC_N)
#define WM_RCTL LCTL_T(KC_T)
#define WM_RSFT LSFT_T(KC_H)

#define WNUM LT(_WNUM, KC_BSPC)
#define WSYM LT(_WSYM, KC_ENT)
#define WFN  LT(_WFN , KC_DEL)
#define WNAV LT(_WNAV, KC_SPC)
#define WMS LT(_WMS, KC_TAB)

// Mac
#define MBL TG(_MBL)
#define MNAV LT(_MNAV, KC_SPC)

#define M_HOME LCMD(KC_LEFT)
#define M_END LCMD(KC_RGHT)

enum custom_keycodes {
    TO_MAC = SAFE_RANGE,
    TO_WIN,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TO_MAC:
        if (record->event.pressed) {
            // from 1/quantum/process_keycode/process_magic.c
            keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
            layer_on(_MBL);
        } else {
            // when keycode is released
        }
        break;
    case TO_WIN:
        if (record->event.pressed) {
            keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;
            layer_off(_MBL);
        } else {
            // when keycode is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT(
     KC_GRV , KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   ,                                     KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_SLSH,
     KC_ESC , WM_LGUI, WM_LALT, WM_LCTL, WM_LSFT, KC_I   ,                                     KC_D   , WM_RSFT, WM_RCTL, WM_RALT, WM_RGUI, KC_MINS,
     XXXXXXX, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , XXXXXXX, KC_CAPS, XXXXXXX, XXXXXXX, KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , XXXXXXX,
                                XXXXXXX, KC_ESC , WNAV   , WMS    , TO_MAC , XXXXXXX, WSYM   , WNUM   , WFN    , XXXXXXX
   ),
   [_MBL] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, MNAV   , _______, TO_WIN , _______, _______, _______, _______, _______
   ),

   [_WNUM] = LAYOUT(
     XXXXXXX, KC_LBRC, KC_7   , KC_8   , KC_9   , KC_RBRC,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, KC_SCLN, KC_4   , KC_5   , KC_6   , KC_EQL ,                                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
     XXXXXXX, KC_GRV , KC_1   , KC_2   , KC_3   , KC_NUBS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                XXXXXXX, KC_DOT , KC_0   , KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
   ),
   [_WSYM] = LAYOUT(
     XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, KC_COLN, KC_DLR , KC_PERC, KC_CIRC, KC_PLUS,                                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
     XXXXXXX, KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                XXXXXXX, KC_LPRN, KC_RPRN, KC_UNDS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
   ),
   [_WFN] = LAYOUT(
     XXXXXXX, KC_F12 , KC_F7  , KC_F8  , KC_F9  , XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, KC_F11 , KC_F4  , KC_F5  , KC_F6  , XXXXXXX,                                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
     XXXXXXX, KC_F10 , KC_F1  , KC_F2  , KC_F3  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
   ),
   [_WNAV] = LAYOUT(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX,
                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
   ),
   [_WMS] = LAYOUT(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                     XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN2, KC_BTN1, KC_BTN3, XXXXXXX
   ),
   [_MNAV] = LAYOUT(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, M_HOME , KC_PGDN, KC_PGUP, M_END  , XXXXXXX,
                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
   ),
};
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
