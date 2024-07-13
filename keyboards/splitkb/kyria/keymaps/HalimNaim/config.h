#pragma once

// From Miryoku
#undef TAPPING_TERM
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
// Now default. Error to have it.
// #define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD

// Auto Shift
// To use home row mods, can't have Auto shift on the Alphas
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT 150
#define AUTO_SHIFT_NO_SETUP
// #define ONESHOT_TAP_TOGGLE 2

// Mouse key speed and acceleration.
// #undef MOUSEKEY_DELAY
// #define MOUSEKEY_DELAY          0
// #undef MOUSEKEY_INTERVAL
// #define MOUSEKEY_INTERVAL       16
// #undef MOUSEKEY_MOVE_DELTA
// #define MOUSEKEY_MOVE_DELTA     5
// #undef MOUSEKEY_WHEEL_DELAY
// #define MOUSEKEY_WHEEL_DELAY    0
// #undef MOUSEKEY_MAX_SPEED
// #define MOUSEKEY_MAX_SPEED      6
// #undef MOUSEKEY_TIME_TO_MAX
// #define MOUSEKEY_TIME_TO_MAX    64
// #undef MOUSEKEY_WHEEL_MAX_SPEED
// #define MOUSEKEY_WHEEL_MAX_SPEED 8
// #undef MOUSEKEY_WHEEL_TIME_TO_MAX
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 40
// #undef MOUSEKEY_WHEEL_DELTA
// #define MOUSEKEY_WHEEL_DELTA 1
// #undef MOUSEKEY_WHEEL_INTERVAL
// #define MOUSEKEY_WHEEL_INTERVAL 120
