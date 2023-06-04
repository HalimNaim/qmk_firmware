#include QMK_KEYBOARD_H

enum layers {
    _BL,
    _WNUM,
    _WSYM,
    _WFN,
    _WNAV,
};

// home row mods
#define WM_LGUI LGUI_T(KC_A)
#define WM_LALT LALT_T(KC_R)
#define WM_LCTL LCTL_T(KC_S)
#define WM_LSFT LSFT_T(KC_T)

#define WM_RGUI LGUI_T(KC_O)
#define WM_RALT LALT_T(KC_I)
#define WM_RCTL LCTL_T(KC_E)
#define WM_RSFT LSFT_T(KC_N)

#define ESC_CTL LCTL_T(KC_ESC)

#define WNUM LT(_WNUM, KC_BSPC)
#define WSYM LT(_WSYM, KC_ENT)
#define WFN  LT(_WFN , KC_DEL)
#define WNAV LT(_WNAV, KC_SPC)
#define WMS LT(_WMS, KC_TAB)

enum custom_keycodes {
    WM_TOGG = SAFE_RANGE,
    WM_COPY,
    WM_PAST,
    WM_UNDO,
    WM_REDO,
    WM_HOME,
    WM_PGDN,
    WM_PGUP,
    WM_END
};

bool mac_mode = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case WM_TOGG:
        if (record->event.pressed) {
          mac_mode = !mac_mode;
        } else {
            // when keycode is released
        }
        break;
    case WM_COPY:
        if (record->event.pressed) {
          if (mac_mode) {
            SEND_STRING(SS_LGUI("c"));
          } else {
            SEND_STRING(SS_LCTL("c"));
          }
        } else {
         // when keycode is released
        }
        break;
    case WM_PAST:
        if (record->event.pressed) {
          if (mac_mode) {
            SEND_STRING(SS_LGUI("v"));
          } else {
            SEND_STRING(SS_LCTL("v"));
          }
        } else {
            // when keycode is released
        }
        break;
    case WM_UNDO:
        if (record->event.pressed) {
          if (mac_mode) {
            SEND_STRING(SS_LGUI("z"));
          } else {
            SEND_STRING(SS_LCTL("z"));
          }
        } else {
            // when keycode is released
        }
        break;
    case WM_REDO:
        if (record->event.pressed) {
          if (mac_mode) {
            SEND_STRING(SS_LGUI(SS_LSFT("z")));
          } else {
            SEND_STRING(SS_LCTL("y"));
          }
        } else {
            // when keycode is released
        }
        break;
    case WM_HOME:
        if (record->event.pressed) {
          if (mac_mode) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI));
          } else {
            SEND_STRING(SS_TAP(X_HOME));
          }
        } else {
            // when keycode is released
        }
        break;
    case WM_END:
        if (record->event.pressed) {
          if (mac_mode) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI));
          } else {
            SEND_STRING(SS_TAP(X_END));
          }
        } else {
            // when keycode is released
        }
        break;
    case WM_PGDN:
        if (record->event.pressed) {
          if (mac_mode) {
            SEND_STRING(SS_TAP(X_PGDN));
          } else {
            SEND_STRING(SS_TAP(X_PGDN));
          }
        } else {
            // when keycode is released
        }
        break;
    case WM_PGUP:
        if (record->event.pressed) {
          if (mac_mode) {
            SEND_STRING(SS_TAP(X_PGUP));
          } else {
            SEND_STRING(SS_TAP(X_PGUP));
          }
        } else {
            // when keycode is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT(
     KC_GRV , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                                     KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, XXXXXXX,
     ESC_CTL, WM_LGUI, WM_LALT, WM_LCTL, WM_LSFT, KC_G   ,                                     KC_M   , WM_RSFT, WM_RCTL, WM_RALT, WM_RGUI, KC_QUOT,
     WM_TOGG, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , WM_COPY, WM_PAST, WM_REDO, WM_UNDO, KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
                                XXXXXXX, XXXXXXX, KC_ESC , WNAV   , KC_TAB , WSYM   , WNUM   , WFN    , XXXXXXX, XXXXXXX
   ),
   [_WNUM] = LAYOUT(
     XXXXXXX, KC_LBRC, KC_7   , KC_8   , KC_9   , KC_RBRC,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, KC_SCLN, KC_4   , KC_5   , KC_6   , KC_EQL ,                                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
     XXXXXXX, KC_GRV , KC_1   , KC_2   , KC_3   , KC_NUBS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                XXXXXXX, XXXXXXX, KC_DOT , KC_0   , KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
   ),
   [_WSYM] = LAYOUT(
     XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, KC_COLN, KC_DLR , KC_PERC, KC_CIRC, KC_PLUS,                                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
     XXXXXXX, KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_UNDS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
   ),
   [_WFN] = LAYOUT(
     XXXXXXX, KC_F12 , KC_F7  , KC_F8  , KC_F9  , XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, KC_F11 , KC_F4  , KC_F5  , KC_F6  , XXXXXXX,                                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
     XXXXXXX, KC_F10 , KC_F1  , KC_F2  , KC_F3  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
   ),
   [_WNAV] = LAYOUT(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                     KC_CAPS, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, WM_HOME, WM_PGDN, WM_PGUP, WM_END , XXXXXXX,
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
