#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE   0
#define META   1
#define KATATE 2
#define SYMB   3
#define GAME   4
#define RGB    5

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  TAP_ANIM,
  KATATE_A,
  KATATE_K,
  KATATE_S,
  KATATE_T,
  KATATE_N,
  KATATE_H,
  KATATE_M,
  KATATE_Y,
  KATATE_R,
  KATATE_W,
  KATATE_TEN,
  KATATE_NIGORI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT( \
    KC_ESC,   KC_Q,          KC_W,        KC_E,    KC_R,    KC_T,     KC_LBRC,      /*|*/ KC_RBRC,      KC_Y,     KC_U,     KC_I,    KC_O,     KC_P,     KC_MINS, \
    KC_TAB,   KC_A,          KC_S,        KC_D,    KC_F,    KC_G,     KC_LPRN,      /*|*/ KC_RPRN,      KC_H,     KC_J,     KC_K,    KC_L,     KC_SCLN,  KC_QUOT, \
    KC_LSFT,  KC_Z,          KC_X,        KC_C,    KC_V,    KC_B,     TO(META),     /*|*/ LALT(KC_GRV), KC_N,     KC_M,     KC_COMM, KC_DOT,   KC_UP,    KC_SLSH, \
    KC_LCTL,  MO(SYMB),      MO(META),    KC_LALT, KC_DEL,  KC_SPACE, KC_UNDS,      /*|*/ KC_BSPC,      KC_SPACE, KC_SPACE, KC_ENT,  KC_LEFT,  KC_DOWN,  KC_RIGHT  \
  ),

  [META] = LAYOUT( \
    KC_ESC,   KC_1,      KC_2,      KC_3,    KC_4,    KC_5,     KC_PSCR,    /*|*/ KC_6,      KC_7,    KC_8,    KC_9,     KC_0,     KC_PMNS, KC_PPLS, \
    KC_TAB,   KC_A,      KC_S,      KC_D,    KC_F,    KC_G,     KC_LBRC,    /*|*/ KC_RBRC,   KC_4,    KC_5,    KC_6,     XXXXXXX,  KC_PSLS, KC_PAST, \
    KC_LSFT,  KC_Z,      KC_X,      KC_C,    KC_V,    KC_B,     TO(KATATE), /*|*/ KC_DOT,    KC_1,    KC_2,    KC_3,     XXXXXXX,  KC_UP,   KC_BSLS, \
    _______,  _______,   _______,   _______, _______, _______,  _______,    /*|*/ _______,   KC_0,    KC_0,    KC_ENT,   KC_LEFT,  KC_DOWN, KC_RIGHT \
  ),

  [KATATE] = LAYOUT( \
    KC_ESC,   KC_1,      KATATE_A,      KATATE_K, KATATE_S,   KC_5,     KC_PSCR,  /*|*/ KC_6,      KC_7,    KC_8,    KC_9,     KC_0,     KC_PMNS, KC_PPLS, \
    KC_TAB,   KC_A,      KATATE_T,      KATATE_N, KATATE_H,   KC_G,     KC_LBRC,  /*|*/ KC_RBRC,   KC_4,    KC_5,    KC_6,     XXXXXXX,  KC_PSLS, KC_PAST, \
    KC_LSFT,  KC_Z,      KATATE_M,      KATATE_Y, KATATE_R,   KC_B,     TO(BASE), /*|*/ KC_DOT,    KC_1,    KC_2,    KC_3,     XXXXXXX,  KC_UP,   KC_BSLS, \
    _______,  _______,   KATATE_NIGORI, KATATE_W, KATATE_TEN, _______,  _______,  /*|*/ _______,   KC_0,    KC_0,    KC_ENT,   KC_LEFT,  KC_DOWN, KC_RIGHT \
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

const char HIRAGANA[20][5][4] = {
  { "a", "i", "u", "e", "o" },
  { "ka", "ki", "ku", "ke", "ko" },
  { "sa", "si", "su", "se", "so" },
  { "ta", "ti", "tu", "te", "to" },
  { "na", "ni", "nu", "ne", "no" },
  { "ha", "hi", "hu", "he", "ho" },
  { "ma", "mi", "mu", "me", "mo" },
  { "ya", "yu", "yo" },
  { "ra", "ri", "ru", "re", "ro" },
  { "wa", "wo", "nn" },
  { ",", ".", "!", "?" },
  { "ga", "gi", "gu", "ge", "go" },
  { "za", "zi", "zu", "ze", "zo" },
  { "da", "di", "du", "de", "do" },
  { "ba", "bi", "bu", "be", "bo" },
  { "pa", "pi", "pu", "pe", "po" },
  { "la", "li", "lu", "le", "lo" },
  { "", "", "ltu" },
  { "lya", "lyu", "lyo" },
  { "lwa" },
};
int previousHiraganaRow = -1;
int previousHiraganaColumn = -1;

int convertKeycode2HiraganaRow(int pressedKeycode) {
  if(pressedKeycode == KATATE_NIGORI) {
    switch(previousHiraganaRow) {
      // a -> la
      case 0:
        return 16;
      // la -> a
      case 16:
        return 0;
      // ka -> ga
      case 1:
        return 11;
      // ga -> ka
      case 11:
        return 1;
      // sa -> za
      case 2:
        return 12;
      // za -> sa
      case 12:
        return 2;
      // ta -> da
      case 3:
        return 13;
      // da -> ta or du -> ltu
      case 13:
        return previousHiraganaColumn == 2 ? 17 : 3;
      // ltu -> tu
      case 17:
        return 3;
      // ha -> ba
      case 5:
        return 14;
      // ba -> pa
      case 14:
        return 15;
      // pa -> ha
      case 15:
        return 5;
      // ya -> lya
      case 7:
        return 18;
      // lya -> ya
      case 18:
        return 7;
      // wa -> lwa
      case 9:
        if (previousHiraganaColumn == 0) { return 19; }
      // lwa -> wa
      case 19:
        return 9;
      default:
        return previousHiraganaRow;
    }
  }

  switch(pressedKeycode) {
    case KATATE_A:
      return 0;
    case KATATE_K:
      return 1;
    case KATATE_S:
      return 2;
    case KATATE_T:
      return 3;
    case KATATE_N:
      return 4;
    case KATATE_H:
      return 5;
    case KATATE_M:
      return 6;
    case KATATE_Y:
      return 7;
    case KATATE_R:
      return 8;
    case KATATE_W:
      return 9;
    case KATATE_TEN:
      return 10;
    default:
      return 0;
  }
}

int convertKeycode2HiraganaColumn(int pressedKeycode) {
  // NIGORI の場合は column が同じままトグルされる
  if (pressedKeycode == KATATE_NIGORI) {
    return previousHiraganaColumn;
  }

  int rowLength =
    // 「や」行と「わ」行は 3 文字だけ
    (pressedKeycode == KATATE_Y || pressedKeycode == KATATE_W) ? 3 :
    // 句読点と !?
    pressedKeycode == KATATE_TEN ? 4 :
    // それ以外は 5 文字
    5;

  return convertKeycode2HiraganaRow(pressedKeycode) == previousHiraganaRow ? (previousHiraganaColumn + 1) % rowLength : 0;
}

void katate_emulator(int pressedKeycode) {
  int currentHiraganaRow = convertKeycode2HiraganaRow(pressedKeycode);
  int currentHiraganaColumn = convertKeycode2HiraganaColumn(pressedKeycode);

  // guard
  if (currentHiraganaRow < 0 || currentHiraganaColumn < 0) return;

  if (previousHiraganaRow != -1 && (pressedKeycode == KATATE_NIGORI || currentHiraganaRow == previousHiraganaRow)) {
    SEND_STRING("\b");
  }
  send_string(HIRAGANA[currentHiraganaRow][currentHiraganaColumn]);

  previousHiraganaRow = currentHiraganaRow;
  previousHiraganaColumn = currentHiraganaColumn;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_MOD:
      if (record->event.pressed) {
        isTapAnim = false;
        previousHiraganaRow = -1;
      }
      break;
    case RGB_RST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          previousHiraganaRow = -1;
        }
      #endif
      break;
    case TAP_ANIM:
      if (record->event.pressed) {
        isTapAnim = !isTapAnim;
        previousHiraganaRow = -1;
      }
      break;
    case KATATE_A:
    case KATATE_K:
    case KATATE_S:
    case KATATE_T:
    case KATATE_N:
    case KATATE_H:
    case KATATE_M:
    case KATATE_Y:
    case KATATE_R:
    case KATATE_W:
    case KATATE_TEN:
    case KATATE_NIGORI:
      if (record->event.pressed) { katate_emulator(keycode); }
      break;
    default:
      previousHiraganaRow = -1;
  }

  if (isTapAnim) {
    rgblight_mode_noeeprom(1);
    uint16_t hue = (rgblight_config.hue + 5) % 360;
    rgblight_sethsv_noeeprom(hue, rgblight_config.sat, rgblight_config.val);
  }

  return true;
}
