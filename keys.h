//
// Key codes
//

#define KEY_BACKSPACE        0x101
#define KEY_ESC              0x102
#define KEY_INS              0x103
#define KEY_DEL              0x104
#define KEY_LEFT             0x105
#define KEY_RIGHT            0x106
#define KEY_UP               0x107
#define KEY_DOWN             0x108
#define KEY_HOME             0x109
#define KEY_END              0x10A
#define KEY_ENTER            0x10B
#define KEY_TAB              0x10C
#define KEY_PGUP             0x10D
#define KEY_PGDN             0x10E

#define KEY_CTRL_LEFT        0x10F
#define KEY_CTRL_RIGHT       0x110
#define KEY_CTRL_UP          0x111
#define KEY_CTRL_DOWN        0x112
#define KEY_CTRL_HOME        0x113
#define KEY_CTRL_END         0x114
#define KEY_CTRL_TAB         0x115

#define KEY_SHIFT_LEFT       0x116
#define KEY_SHIFT_RIGHT      0x117
#define KEY_SHIFT_UP         0x118
#define KEY_SHIFT_DOWN       0x119
#define KEY_SHIFT_PGUP       0x11A
#define KEY_SHIFT_PGDN       0x11B
#define KEY_SHIFT_HOME       0x11C
#define KEY_SHIFT_END        0x11D
#define KEY_SHIFT_TAB        0x11E

#define KEY_SHIFT_CTRL_LEFT  0x11F
#define KEY_SHIFT_CTRL_RIGHT 0x120
#define KEY_SHIFT_CTRL_UP    0x121
#define KEY_SHIFT_CTRL_DOWN  0x122
#define KEY_SHIFT_CTRL_HOME  0x123
#define KEY_SHIFT_CTRL_END   0x124

#define KEY_F1               0x125
#define KEY_F3               0x126
#define KEY_F5               0x127

#define KEY_UNKNOWN          0xFFF

#define ctrl(c) ((c) - 0x60)

//
// Keyboard functions
//

int getkey();
