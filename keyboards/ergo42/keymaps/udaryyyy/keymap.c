#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layers {
  BASE_JP,
  BASE_EN,
  SHIFT_NUM,
  NUMERIC,
  WITH_FUNC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE_JP] = LAYOUT( \
    KC_ESC,   KC_Q,          KC_W,        KC_E,    KC_R,    KC_T,     TO(NUMERIC),  /*|*/ XXXXXXX,      KC_Y,    KC_U,   KC_I,        KC_O,          KC_P,    KC_MINS, \
    KC_TAB,   KC_A,          KC_S,        KC_D,    KC_F,    KC_G,     KC_LBRC,      /*|*/ KC_RBRC,      KC_H,    KC_J,   KC_K,        KC_L,          KC_SCLN, KC_QUOT, \
    KC_LSFT,  KC_Z,          KC_X,        KC_C,    KC_V,    KC_B,     LALT(KC_GRV), /*|*/ LALT(KC_GRV), KC_N,    KC_M,   KC_COMM,     KC_DOT,        KC_SLSH, KC_BSLS, \
    KC_LCTL,  MO(WITH_FUNC), MO(NUMERIC), KC_LALT, KC_DEL,  KC_SPACE, KC_BSPC,      /*|*/ KC_BSPC,     KC_SPACE, KC_ENT, TG(BASE_EN), MO(SHIFT_NUM), XXXXXXX, KC_RGUI \
  ),

  [BASE_EN] = LAYOUT( \
    KC_ESC,   KC_Q,          KC_W,        KC_E,    KC_R,    KC_T,     _______,      /*|*/ XXXXXXX,      KC_Y,    KC_U,   KC_I,        KC_O,          KC_P,    KC_MINS, \
    KC_TAB,   KC_A,          KC_S,        KC_D,    KC_F,    KC_G,     KC_LPRN,      /*|*/ KC_RPRN,      KC_H,    KC_J,   KC_K,        KC_L,          KC_SCLN, KC_QUOT, \
    KC_LSFT,  KC_Z,          KC_X,        KC_C,    KC_V,    KC_B,     KC_LCBR,      /*|*/ KC_RCBR,      KC_N,    KC_M,   KC_COMM,     KC_DOT,        KC_SLSH, KC_BSLS, \
    _______,  _______,       _______,     _______, _______, _______,  _______,      /*|*/ _______,     _______, _______, _______,     _______,       _______, _______ \
  ),

  [SHIFT_NUM] = LAYOUT( \
    KC_ESC,   S(KC_1),       S(KC_2),     S(KC_3), S(KC_4), S(KC_5),  XXXXXXX,      /*|*/ XXXXXXX,      S(KC_6), S(KC_7), S(KC_8),    S(KC_9),       S(KC_0), XXXXXXX, \
    KC_TAB,   XXXXXXX,       XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      /*|*/ XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,       XXXXXXX, XXXXXXX, \
    KC_LSFT,  XXXXXXX,       XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      /*|*/ XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,       XXXXXXX, XXXXXXX, \
    _______,  _______,       _______,     _______, _______, _______,  _______,      /*|*/ _______,     _______,  _______, XXXXXXX,    _______,       _______, _______ \
  ),

  [NUMERIC] = LAYOUT( \
    KC_ESC,   XXXXXXX,       XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,  TO(BASE_EN),  /*|*/ KC_PSCR,      KC_7,    KC_8,    KC_9,       XXXXXXX,       KC_PMNS, KC_PPLS, \
    KC_TAB,   KC_A,          KC_S,        KC_D,    KC_F,    KC_G,     KC_LBRC,      /*|*/ KC_RBRC,      KC_4,    KC_5,    KC_6,       XXXXXXX,       KC_PSLS, KC_PAST, \
    KC_LSFT,  KC_Z,          KC_X,        KC_C,    KC_V,    KC_B,     LALT(KC_GRV), /*|*/ KC_DOT,       KC_1,    KC_2,    KC_3,       XXXXXXX,       KC_UP,   XXXXXXX, \
    _______,  _______,       _______,     _______, _______, _______,  _______,      /*|*/ _______,      KC_0,    KC_ENT,  XXXXXXX,    KC_LEFT,       KC_DOWN, KC_RIGHT \
  ),

  [WITH_FUNC] = LAYOUT( \
    XXXXXXX,  XXXXXXX,       XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      /*|*/ KC_PSCR,     KC_F7,    KC_F8,   KC_F9,      KC_F10,        KC_F11,  KC_F12, \
    XXXXXXX,  XXXXXXX,       XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      /*|*/ XXXXXXX,     KC_F4,    KC_F5,   KC_F6,      XXXXXXX,       XXXXXXX, XXXXXXX, \
    XXXXXXX,  XXXXXXX,       XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      /*|*/ XXXXXXX,     KC_F1,    KC_F2,   KC_F3,      XXXXXXX,       XXXXXXX, XXXXXXX, \
    XXXXXXX,  _______,       XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      /*|*/ XXXXXXX,     XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX,       XXXXXXX, XXXXXXX \
  )

};

