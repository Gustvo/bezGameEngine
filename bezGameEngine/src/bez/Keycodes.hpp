#ifndef KEYCODE_HPP
#define KEYCODE_HPP

// Stolen from SDL2

enum Keycode {
  BEZ_KEYCODE_UNKNOWN = 0,

  /**
   *  \name Usage page 0x07
   *
   *  These values are from usage page 0x07 (USB keyboard page).
   */
  /* @{ */

  BEZ_KEYCODE_A = 4,
  BEZ_KEYCODE_B = 5,
  BEZ_KEYCODE_C = 6,
  BEZ_KEYCODE_D = 7,
  BEZ_KEYCODE_E = 8,
  BEZ_KEYCODE_F = 9,
  BEZ_KEYCODE_G = 10,
  BEZ_KEYCODE_H = 11,
  BEZ_KEYCODE_I = 12,
  BEZ_KEYCODE_J = 13,
  BEZ_KEYCODE_K = 14,
  BEZ_KEYCODE_L = 15,
  BEZ_KEYCODE_M = 16,
  BEZ_KEYCODE_N = 17,
  BEZ_KEYCODE_O = 18,
  BEZ_KEYCODE_P = 19,
  BEZ_KEYCODE_Q = 20,
  BEZ_KEYCODE_R = 21,
  BEZ_KEYCODE_S = 22,
  BEZ_KEYCODE_T = 23,
  BEZ_KEYCODE_U = 24,
  BEZ_KEYCODE_V = 25,
  BEZ_KEYCODE_W = 26,
  BEZ_KEYCODE_X = 27,
  BEZ_KEYCODE_Y = 28,
  BEZ_KEYCODE_Z = 29,

  BEZ_KEYCODE_1 = 30,
  BEZ_KEYCODE_2 = 31,
  BEZ_KEYCODE_3 = 32,
  BEZ_KEYCODE_4 = 33,
  BEZ_KEYCODE_5 = 34,
  BEZ_KEYCODE_6 = 35,
  BEZ_KEYCODE_7 = 36,
  BEZ_KEYCODE_8 = 37,
  BEZ_KEYCODE_9 = 38,
  BEZ_KEYCODE_0 = 39,

  BEZ_KEYCODE_RETURN = 40,
  BEZ_KEYCODE_ESCAPE = 41,
  BEZ_KEYCODE_BACKSPACE = 42,
  BEZ_KEYCODE_TAB = 43,
  BEZ_KEYCODE_SPACE = 44,

  BEZ_KEYCODE_MINUS = 45,
  BEZ_KEYCODE_EQUALS = 46,
  BEZ_KEYCODE_LEFTBRACKET = 47,
  BEZ_KEYCODE_RIGHTBRACKET = 48,
  BEZ_KEYCODE_BACKSLASH = 49, /**< Located at the lower left of the return
                                *   key on ISO keyboards and at the right end
                                *   of the QWERTY row on ANSI keyboards.
                                *   Produces REVERSE SOLIDUS (backslash) and
                                *   VERTICAL LINE in a US layout, REVERSE
                                *   SOLIDUS and VERTICAL LINE in a UK Mac
                                *   layout, NUMBER SIGN and TILDE in a UK
                                *   Windows layout, DOLLAR SIGN and POUND SIGN
                                *   in a Swiss German layout, NUMBER SIGN and
                                *   APOSTROPHE in a German layout, GRAVE
                                *   ACCENT and POUND SIGN in a French Mac
                                *   layout, and ASTERISK and MICRO SIGN in a
                                *   French Windows layout.
                                */
  BEZ_KEYCODE_NONUSHASH = 50, /**< ISO USB keyboards actually use this code
                                *   instead of 49 for the same key, but all
                                *   OSes I've seen treat the two codes
                                *   identically. So, as an implementor, unless
                                *   your keyboard generates both of those
                                *   codes and your OS treats them differently,
                                *   you should generate BEZ_KEYCODE_BACKSLASH
                                *   instead of this code. As a user, you
                                *   should not rely on this code because SDL
                                *   will never generate it with most (all?)
                                *   keyboards.
                                */
  BEZ_KEYCODE_SEMICOLON = 51,
  BEZ_KEYCODE_APOSTROPHE = 52,
  BEZ_KEYCODE_GRAVE = 53, /**< Located in the top left corner (on both ANSI
                            *   and ISO keyboards). Produces GRAVE ACCENT and
                            *   TILDE in a US Windows layout and in US and UK
                            *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                            *   and NOT SIGN in a UK Windows layout, SECTION
                            *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                            *   layouts on ISO keyboards, SECTION SIGN and
                            *   DEGREE SIGN in a Swiss German layout (Mac:
                            *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                            *   DEGREE SIGN in a German layout (Mac: only on
                            *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
                            *   French Windows layout, COMMERCIAL AT and
                            *   NUMBER SIGN in a French Mac layout on ISO
                            *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                            *   SIGN in a Swiss German, German, or French Mac
                            *   layout on ANSI keyboards.
                            */
  BEZ_KEYCODE_COMMA = 54,
  BEZ_KEYCODE_PERIOD = 55,
  BEZ_KEYCODE_SLASH = 56,

  BEZ_KEYCODE_CAPSLOCK = 57,

  BEZ_KEYCODE_F1 = 58,
  BEZ_KEYCODE_F2 = 59,
  BEZ_KEYCODE_F3 = 60,
  BEZ_KEYCODE_F4 = 61,
  BEZ_KEYCODE_F5 = 62,
  BEZ_KEYCODE_F6 = 63,
  BEZ_KEYCODE_F7 = 64,
  BEZ_KEYCODE_F8 = 65,
  BEZ_KEYCODE_F9 = 66,
  BEZ_KEYCODE_F10 = 67,
  BEZ_KEYCODE_F11 = 68,
  BEZ_KEYCODE_F12 = 69,

  BEZ_KEYCODE_PRINTSCREEN = 70,
  BEZ_KEYCODE_SCROLLLOCK = 71,
  BEZ_KEYCODE_PAUSE = 72,
  BEZ_KEYCODE_INSERT = 73, /**< insert on PC, help on some Mac keyboards (but
                                 does send code 73, not 117) */
  BEZ_KEYCODE_HOME = 74,
  BEZ_KEYCODE_PAGEUP = 75,
  BEZ_KEYCODE_DELETE = 76,
  BEZ_KEYCODE_END = 77,
  BEZ_KEYCODE_PAGEDOWN = 78,
  BEZ_KEYCODE_RIGHT = 79,
  BEZ_KEYCODE_LEFT = 80,
  BEZ_KEYCODE_DOWN = 81,
  BEZ_KEYCODE_UP = 82,

  BEZ_KEYCODE_NUMLOCKCLEAR = 83, /**< num lock on PC, clear on Mac keyboards
                                   */
  BEZ_KEYCODE_KP_DIVIDE = 84,
  BEZ_KEYCODE_KP_MULTIPLY = 85,
  BEZ_KEYCODE_KP_MINUS = 86,
  BEZ_KEYCODE_KP_PLUS = 87,
  BEZ_KEYCODE_KP_ENTER = 88,
  BEZ_KEYCODE_KP_1 = 89,
  BEZ_KEYCODE_KP_2 = 90,
  BEZ_KEYCODE_KP_3 = 91,
  BEZ_KEYCODE_KP_4 = 92,
  BEZ_KEYCODE_KP_5 = 93,
  BEZ_KEYCODE_KP_6 = 94,
  BEZ_KEYCODE_KP_7 = 95,
  BEZ_KEYCODE_KP_8 = 96,
  BEZ_KEYCODE_KP_9 = 97,
  BEZ_KEYCODE_KP_0 = 98,
  BEZ_KEYCODE_KP_PERIOD = 99,

  BEZ_KEYCODE_NONUSBACKSLASH = 100, /**< This is the additional key that ISO
                                      *   keyboards have over ANSI ones,
                                      *   located between left shift and Y.
                                      *   Produces GRAVE ACCENT and TILDE in a
                                      *   US or UK Mac layout, REVERSE SOLIDUS
                                      *   (backslash) and VERTICAL LINE in a
                                      *   US or UK Windows layout, and
                                      *   LESS-THAN SIGN and GREATER-THAN SIGN
                                      *   in a Swiss German, German, or French
                                      *   layout. */
  BEZ_KEYCODE_APPLICATION = 101,    /**< windows contextual menu, compose */
  BEZ_KEYCODE_POWER = 102, /**< The USB document says this is a status flag,
                             *   not a physical key - but some Mac keyboards
                             *   do have a power key. */
  BEZ_KEYCODE_KP_EQUALS = 103,
  BEZ_KEYCODE_F13 = 104,
  BEZ_KEYCODE_F14 = 105,
  BEZ_KEYCODE_F15 = 106,
  BEZ_KEYCODE_F16 = 107,
  BEZ_KEYCODE_F17 = 108,
  BEZ_KEYCODE_F18 = 109,
  BEZ_KEYCODE_F19 = 110,
  BEZ_KEYCODE_F20 = 111,
  BEZ_KEYCODE_F21 = 112,
  BEZ_KEYCODE_F22 = 113,
  BEZ_KEYCODE_F23 = 114,
  BEZ_KEYCODE_F24 = 115,
  BEZ_KEYCODE_EXECUTE = 116,
  BEZ_KEYCODE_HELP = 117,
  BEZ_KEYCODE_MENU = 118,
  BEZ_KEYCODE_SELECT = 119,
  BEZ_KEYCODE_STOP = 120,
  BEZ_KEYCODE_AGAIN = 121, /**< redo */
  BEZ_KEYCODE_UNDO = 122,
  BEZ_KEYCODE_CUT = 123,
  BEZ_KEYCODE_COPY = 124,
  BEZ_KEYCODE_PASTE = 125,
  BEZ_KEYCODE_FIND = 126,
  BEZ_KEYCODE_MUTE = 127,
  BEZ_KEYCODE_VOLUMEUP = 128,
  BEZ_KEYCODE_VOLUMEDOWN = 129,
  /* not sure whether there's a reason to enable these */
  /*     BEZ_KEYCODE_LOCKINGCAPSLOCK = 130,  */
  /*     BEZ_KEYCODE_LOCKINGNUMLOCK = 131, */
  /*     BEZ_KEYCODE_LOCKINGSCROLLLOCK = 132, */
  BEZ_KEYCODE_KP_COMMA = 133,
  BEZ_KEYCODE_KP_EQUALSAS400 = 134,

  BEZ_KEYCODE_INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
                                          footnotes in USB doc */
  BEZ_KEYCODE_INTERNATIONAL2 = 136,
  BEZ_KEYCODE_INTERNATIONAL3 = 137, /**< Yen */
  BEZ_KEYCODE_INTERNATIONAL4 = 138,
  BEZ_KEYCODE_INTERNATIONAL5 = 139,
  BEZ_KEYCODE_INTERNATIONAL6 = 140,
  BEZ_KEYCODE_INTERNATIONAL7 = 141,
  BEZ_KEYCODE_INTERNATIONAL8 = 142,
  BEZ_KEYCODE_INTERNATIONAL9 = 143,
  BEZ_KEYCODE_LANG1 = 144, /**< Hangul/English toggle */
  BEZ_KEYCODE_LANG2 = 145, /**< Hanja conversion */
  BEZ_KEYCODE_LANG3 = 146, /**< Katakana */
  BEZ_KEYCODE_LANG4 = 147, /**< Hiragana */
  BEZ_KEYCODE_LANG5 = 148, /**< Zenkaku/Hankaku */
  BEZ_KEYCODE_LANG6 = 149, /**< reserved */
  BEZ_KEYCODE_LANG7 = 150, /**< reserved */
  BEZ_KEYCODE_LANG8 = 151, /**< reserved */
  BEZ_KEYCODE_LANG9 = 152, /**< reserved */

  BEZ_KEYCODE_ALTERASE = 153, /**< Erase-Eaze */
  BEZ_KEYCODE_SYSREQ = 154,
  BEZ_KEYCODE_CANCEL = 155,
  BEZ_KEYCODE_CLEAR = 156,
  BEZ_KEYCODE_PRIOR = 157,
  BEZ_KEYCODE_RETURN2 = 158,
  BEZ_KEYCODE_SEPARATOR = 159,
  BEZ_KEYCODE_OUT = 160,
  BEZ_KEYCODE_OPER = 161,
  BEZ_KEYCODE_CLEARAGAIN = 162,
  BEZ_KEYCODE_CRSEL = 163,
  BEZ_KEYCODE_EXSEL = 164,

  BEZ_KEYCODE_KP_00 = 176,
  BEZ_KEYCODE_KP_000 = 177,
  BEZ_KEYCODE_THOUSANDSSEPARATOR = 178,
  BEZ_KEYCODE_DECIMALSEPARATOR = 179,
  BEZ_KEYCODE_CURRENCYUNIT = 180,
  BEZ_KEYCODE_CURRENCYSUBUNIT = 181,
  BEZ_KEYCODE_KP_LEFTPAREN = 182,
  BEZ_KEYCODE_KP_RIGHTPAREN = 183,
  BEZ_KEYCODE_KP_LEFTBRACE = 184,
  BEZ_KEYCODE_KP_RIGHTBRACE = 185,
  BEZ_KEYCODE_KP_TAB = 186,
  BEZ_KEYCODE_KP_BACKSPACE = 187,
  BEZ_KEYCODE_KP_A = 188,
  BEZ_KEYCODE_KP_B = 189,
  BEZ_KEYCODE_KP_C = 190,
  BEZ_KEYCODE_KP_D = 191,
  BEZ_KEYCODE_KP_E = 192,
  BEZ_KEYCODE_KP_F = 193,
  BEZ_KEYCODE_KP_XOR = 194,
  BEZ_KEYCODE_KP_POWER = 195,
  BEZ_KEYCODE_KP_PERCENT = 196,
  BEZ_KEYCODE_KP_LESS = 197,
  BEZ_KEYCODE_KP_GREATER = 198,
  BEZ_KEYCODE_KP_AMPERSAND = 199,
  BEZ_KEYCODE_KP_DBLAMPERSAND = 200,
  BEZ_KEYCODE_KP_VERTICALBAR = 201,
  BEZ_KEYCODE_KP_DBLVERTICALBAR = 202,
  BEZ_KEYCODE_KP_COLON = 203,
  BEZ_KEYCODE_KP_HASH = 204,
  BEZ_KEYCODE_KP_SPACE = 205,
  BEZ_KEYCODE_KP_AT = 206,
  BEZ_KEYCODE_KP_EXCLAM = 207,
  BEZ_KEYCODE_KP_MEMSTORE = 208,
  BEZ_KEYCODE_KP_MEMRECALL = 209,
  BEZ_KEYCODE_KP_MEMCLEAR = 210,
  BEZ_KEYCODE_KP_MEMADD = 211,
  BEZ_KEYCODE_KP_MEMSUBTRACT = 212,
  BEZ_KEYCODE_KP_MEMMULTIPLY = 213,
  BEZ_KEYCODE_KP_MEMDIVIDE = 214,
  BEZ_KEYCODE_KP_PLUSMINUS = 215,
  BEZ_KEYCODE_KP_CLEAR = 216,
  BEZ_KEYCODE_KP_CLEARENTRY = 217,
  BEZ_KEYCODE_KP_BINARY = 218,
  BEZ_KEYCODE_KP_OCTAL = 219,
  BEZ_KEYCODE_KP_DECIMAL = 220,
  BEZ_KEYCODE_KP_HEXADECIMAL = 221,

  BEZ_KEYCODE_LCTRL = 224,
  BEZ_KEYCODE_LSHIFT = 225,
  BEZ_KEYCODE_LALT = 226, /**< alt, option */
  BEZ_KEYCODE_LSUPER = 227, /**< windows, command (apple), meta */
  BEZ_KEYCODE_RCTRL = 228,
  BEZ_KEYCODE_RSHIFT = 229,
  BEZ_KEYCODE_RSUPER = 230, /**< alt gr, option */
  BEZ_KEYCODE_RGUI = 231, /**< windows, command (apple), meta */

  BEZ_KEYCODE_MODE = 257, /**< I'm not sure if this is really not covered
                            *   by any of the above, but since there's a
                            *   special KMOD_MODE for it I'm adding it here
                            */

  /* @} */ /* Usage page 0x07 */

  /**
   *  \name Usage page 0x0C
   *
   *  These values are mapped from usage page 0x0C (USB consumer page).
   */
  /* @{ */

  BEZ_KEYCODE_AUDIONEXT = 258,
  BEZ_KEYCODE_AUDIOPREV = 259,
  BEZ_KEYCODE_AUDIOSTOP = 260,
  BEZ_KEYCODE_AUDIOPLAY = 261,
  BEZ_KEYCODE_AUDIOMUTE = 262,
  BEZ_KEYCODE_MEDIASELECT = 263,
  BEZ_KEYCODE_WWW = 264,
  BEZ_KEYCODE_MAIL = 265,
  BEZ_KEYCODE_CALCULATOR = 266,
  BEZ_KEYCODE_COMPUTER = 267,
  BEZ_KEYCODE_AC_SEARCH = 268,
  BEZ_KEYCODE_AC_HOME = 269,
  BEZ_KEYCODE_AC_BACK = 270,
  BEZ_KEYCODE_AC_FORWARD = 271,
  BEZ_KEYCODE_AC_STOP = 272,
  BEZ_KEYCODE_AC_REFRESH = 273,
  BEZ_KEYCODE_AC_BOOKMARKS = 274,

  /* @} */ /* Usage page 0x0C */

  /**
   *  \name Walther keys
   *
   *  These are values that Christian Walther added (for mac keyboard?).
   */
  /* @{ */

  BEZ_KEYCODE_BRIGHTNESSDOWN = 275,
  BEZ_KEYCODE_BRIGHTNESSUP = 276,
  BEZ_KEYCODE_DISPLAYSWITCH = 277, /**< display mirroring/dual display
                                         switch, video mode switch */
  BEZ_KEYCODE_KBDILLUMTOGGLE = 278,
  BEZ_KEYCODE_KBDILLUMDOWN = 279,
  BEZ_KEYCODE_KBDILLUMUP = 280,
  BEZ_KEYCODE_EJECT = 281,
  BEZ_KEYCODE_SLEEP = 282,

  BEZ_KEYCODE_APP1 = 283,
  BEZ_KEYCODE_APP2 = 284,

  /* @} */ /* Walther keys */

  /**
   *  \name Usage page 0x0C (additional media keys)
   *
   *  These values are mapped from usage page 0x0C (USB consumer page).
   */
  /* @{ */

  BEZ_KEYCODE_AUDIOREWIND = 285,
  BEZ_KEYCODE_AUDIOFASTFORWARD = 286,

  /* @} */ /* Usage page 0x0C (additional media keys) */

  /* Add any other keys here. */

  BEZ_NUM_KEYCODES = 512 /**< not a key, just marks the number of scancodes
                               for array bounds */
};

#endif // KEYCODE_HPP