#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define GAME 3
#define RGB  4

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  TAP_ANIM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT( \
    KC_ESC,   KC_Q,          KC_W,        KC_E,    KC_R,    KC_T,     KC_LBRC,      /*|*/ KC_RBRC,      KC_Y,     KC_U,     KC_I,    KC_O,     KC_P,     KC_MINS, \
    KC_TAB,   KC_A,          KC_S,        KC_D,    KC_F,    KC_G,     KC_LPRN,      /*|*/ KC_RPRN,      KC_H,     KC_J,     KC_K,    KC_L,     KC_SCLN,  KC_QUOT, \
    KC_LSFT,  KC_Z,          KC_X,        KC_C,    KC_V,    KC_B,     TO(META),     /*|*/ LALT(KC_GRV), KC_N,     KC_M,     KC_COMM, KC_DOT,   KC_UP,    KC_SLSH, \
    KC_LCTL,  MO(SYMB),      MO(META),    KC_LALT, KC_DEL,  KC_SPACE, KC_UNDS,      /*|*/ KC_BSPC,      KC_SPACE, KC_SPACE, KC_ENT,  KC_LEFT,  KC_DOWN,  KC_RIGHT  \
  ),

  [META] = LAYOUT( \
    KC_ESC,   KC_1,      KC_2,      KC_3,    KC_4,    KC_5,     KC_PSCR,  /*|*/ KC_6,      KC_7,    KC_8,    KC_9,     KC_0,     KC_PMNS, KC_PPLS, \
    KC_TAB,   KC_A,      KC_S,      KC_D,    KC_F,    KC_G,     KC_LBRC,  /*|*/ KC_RBRC,   KC_4,    KC_5,    KC_6,     XXXXXXX,  KC_PSLS, KC_PAST, \
    KC_LSFT,  KC_Z,      KC_X,      KC_C,    KC_V,    KC_B,     TO(BASE), /*|*/ KC_DOT,    KC_1,    KC_2,    KC_3,     XXXXXXX,  KC_UP,   KC_BSLS, \
    _______,  _______,   _______,   _______, _______, _______,  _______,  /*|*/ _______,   KC_0,    KC_0,    KC_ENT,   KC_LEFT,  KC_DOWN, KC_RIGHT \
  ),

  [SYMB] = LAYOUT( \
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,  /*|*/ XXXXXXX,     KC_F7,    KC_F8,   KC_F9,      KC_F10,        KC_F11,  KC_F12,  \
    RGB_TOG,  RGB_RST, RGB_HUI, RGB_SAI, RGB_VAI, TAP_ANIM, XXXXXXX,  /*|*/ XXXXXXX,     KC_F4,    KC_F5,   KC_F6,      XXXXXXX,       XXXXXXX, XXXXXXX, \
    XXXXXXX,  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,  XXXXXXX,  /*|*/ XXXXXXX,     KC_F1,    KC_F2,   KC_F3,      XXXXXXX,       XXXXXXX, XXXXXXX, \
    XXXXXXX,  _______, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  /*|*/ XXXXXXX,     XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX,       XXXXXXX, KC_RGUI  \
  ),

  [RGB] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, TAP_ANIM,XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUI, RGB_SAD, RGB_VAD, RGB_RST, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
  )

};

bool isTapAnim = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_MOD:
      if (record->event.pressed) {
        isTapAnim = false;
      }
      break;
    case RGB_RST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
    case TAP_ANIM:
      if (record->event.pressed) {
        isTapAnim = !isTapAnim;
      }
      break;
  }

  if (isTapAnim) {
    rgblight_mode_noeeprom(1);
    uint16_t hue = (rgblight_config.hue + 5) % 360;
    rgblight_sethsv_noeeprom(hue, rgblight_config.sat, rgblight_config.val);
  }

  return true;
}
