#include QMK_KEYBOARD_H

enum layers {
    _BS,
    _NM,
    _FN,
    _CP
};

// home row mods
#define WM_LSFT LSFT_T(KC_A)
#define WM_LCTL LCTL_T(KC_R)
#define WM_LALT LALT_T(KC_S)
#define WM_LGUI LGUI_T(KC_T)

#define WM_RGUI LGUI_T(KC_N)
#define WM_RALT LALT_T(KC_E)
#define WM_RCTL LCTL_T(KC_I)
#define WM_RSFT LSFT_T(KC_O)

// Number Layer
#define NM_LSFT LSFT_T(KC_QUOT)
#define NM_LCTL LCTL_T(KC_4)
#define NM_LALT LALT_T(KC_5)
#define NM_LGUI LGUI_T(KC_6)

#define NM_RGUI LGUI_T(KC_LEFT)
#define NM_RALT LALT_T(KC_DOWN)
#define NM_RCTL LCTL_T(KC_UP)
#define NM_RSFT LSFT_T(KC_RGHT)

// Control Esc
#define CT_ESC LCTL_T(KC_ESC)

// Copy / Paste Layer
#define Z_CP LT(_CP , KC_Z)
#define GRV_CP LT(_CP, KC_GRV)

// Vim Tags
#define CT_RBRC LCTL(KC_RBRC)
#define CT_T    LCTL(KC_T)

enum custom_keycodes {
    WM_TOGG = SAFE_RANGE,
    ESC_BS,
    WM_COPY,
    WM_PAST,
    WM_CUT,
    WM_UNDO,
    WM_REDO,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool mac_mode = true;

    switch (keycode) {
    case WM_TOGG:
        if (record->event.pressed) {
          mac_mode = !mac_mode;
        } else {
            // when keycode is released
        }
        break;
    case ESC_BS:
        if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_ESC));
        } else {
          // Do this on key release, because if I switch layers
          // on keypress, then when I release I activate the key
          // on that layer. `q` in this case
          layer_move(_BS);
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
    case WM_CUT:
        if (record->event.pressed) {
          if (mac_mode) {
            SEND_STRING(SS_LGUI("x"));
          } else {
            SEND_STRING(SS_LCTL("x"));
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
    default:
        // do nothing
        break;
    }

    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BS] = LAYOUT(
     KC_EQL , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                                     KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_MINS,
     CT_ESC , WM_LSFT, WM_LCTL, WM_LALT, WM_LGUI, KC_G   ,                                     KC_M   , WM_RGUI, WM_RALT, WM_RCTL, WM_RSFT, KC_QUOT,
     KC_GRV , Z_CP   , KC_X   , KC_C   , KC_D   , KC_V   , KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, KC_BSLS,
                                KC_LEFT, KC_RGHT, CT_T   , KC_BSPC, TO(_NM), KC_ENT , KC_SPC , CT_RBRC, KC_DOWN, KC_UP
   ),
   [_NM] = LAYOUT(
     _______, ESC_BS , KC_7   , KC_8   , KC_9   , KC_0   ,                                     KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_BSLS, _______,
     _______, NM_LSFT, NM_LCTL, NM_LALT, NM_LGUI, KC_MINS,                                     KC_TAB , NM_RGUI, NM_RALT, NM_RCTL, NM_RSFT, _______,
     _______, GRV_CP , KC_1   , KC_2   , KC_3   , KC_EQL , _______, _______, _______, _______, CW_TOGG, KC_UNDS, _______, _______, TG(_FN), _______,
                                _______, _______, _______, _______, _______, TO(_BS), _______, _______, _______, _______
   ),
   [_FN] = LAYOUT(
     _______, XXXXXXX, KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
     _______, XXXXXXX, KC_F4  , KC_F5  , KC_F6  , KC_F11 ,                                     XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,
     _______, _______, KC_F1  , KC_F2  , KC_F3  , KC_F12 , _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                _______, _______, _______, _______, _______, TO(_BS), _______, _______, _______, _______
   ),
   [_CP] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, WM_UNDO, WM_REDO, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, WM_CUT , WM_COPY, WM_PAST, WM_TOGG, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______, _______, _______, _______, TO(_BS), _______, _______, _______, _______
    ),
};

// /*
//  * Layer template
//    [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
//    [_LAYERINDEX] = LAYOUT(
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
//     ),
