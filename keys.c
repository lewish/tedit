#include <stdio.h>

#include "keys.h"

//
// Keyboard functions
//

int getkey() {
	int ch, shift, ctrl;

	ch = getchar();
	if (ch < 0)
		return ch;

	switch (ch) {
	case 0x08:
		return KEY_BACKSPACE;
	case 0x09:
		return KEY_TAB;
	case 0x0D:
		return KEY_ENTER;
	case 0x0A:
		return KEY_ENTER;
	case 0x1B:
		ch = getchar();
		switch (ch) {
		case 0x1B:
			return KEY_ESC;
		case 0x4F:
			ch = getchar();
			switch (ch) {
			case 0x46:
				return KEY_END;
			case 0x48:
				return KEY_HOME;
			case 0x50:
				return KEY_F1;
			case 0x52:
				return KEY_F3;
			case 0x54:
				return KEY_F5;
			default:
				return KEY_UNKNOWN;
			}
			break;

		case 0x5B:
			shift = ctrl = 0;
			ch = getchar();
			if (ch == 0x31) {
				ch = getchar();
				if (ch != 0x3B)
					return KEY_UNKNOWN;
				ch = getchar();
				if (ch == 0x32)
					shift = 1;
				if (ch == 0x35)
					ctrl = 1;
				if (ch == 0x36)
					shift = ctrl = 1;
				ch = getchar();
			}

			switch (ch) {
			case 0x31:
				return getchar() == 0x7E ? KEY_HOME : KEY_UNKNOWN;
			case 0x32:
				return getchar() == 0x7E ? KEY_INS : KEY_UNKNOWN;
			case 0x33:
				return getchar() == 0x7E ? KEY_DEL : KEY_UNKNOWN;
			case 0x34:
				return getchar() == 0x7E ? KEY_END : KEY_UNKNOWN;
			case 0x35:
				return getchar() == 0x7E ? KEY_PGUP : KEY_UNKNOWN;
			case 0x36:
				return getchar() == 0x7E ? KEY_PGDN : KEY_UNKNOWN;

			case 0x41:
				if (shift && ctrl)
					return KEY_SHIFT_CTRL_UP;
				if (shift)
					return KEY_SHIFT_UP;
				if (ctrl)
					return KEY_CTRL_UP;
				return KEY_UP;
			case 0x42:
				if (shift && ctrl)
					return KEY_SHIFT_CTRL_DOWN;
				if (shift)
					return KEY_SHIFT_DOWN;
				if (ctrl)
					return KEY_CTRL_DOWN;
				return KEY_DOWN;
			case 0x43:
				if (shift && ctrl)
					return KEY_SHIFT_CTRL_RIGHT;
				if (shift)
					return KEY_SHIFT_RIGHT;
				if (ctrl)
					return KEY_CTRL_RIGHT;
				return KEY_RIGHT;
			case 0x44:
				if (shift && ctrl)
					return KEY_SHIFT_CTRL_LEFT;
				if (shift)
					return KEY_SHIFT_LEFT;
				if (ctrl)
					return KEY_CTRL_LEFT;
				return KEY_LEFT;
			case 0x46:
				if (shift && ctrl)
					return KEY_SHIFT_CTRL_END;
				if (shift)
					return KEY_SHIFT_END;
				if (ctrl)
					return KEY_CTRL_END;
				return KEY_END;
			case 0x48:
				if (shift && ctrl)
					return KEY_SHIFT_CTRL_HOME;
				if (shift)
					return KEY_SHIFT_HOME;
				if (ctrl)
					return KEY_CTRL_HOME;
				return KEY_HOME;
			case 0x5A:
				return KEY_SHIFT_TAB;

			default:
				return KEY_UNKNOWN;
			}
			break;

		default:
			return KEY_UNKNOWN;
		}
		break;

	case 0x00:
	case 0xE0:
		ch = getchar();
		switch (ch) {
		case 0x0F:
			return KEY_SHIFT_TAB;
		case 0x3B:
			return KEY_F1;
		case 0x3D:
			return KEY_F3;
		case 0x3F:
			return KEY_F5;
		case 0x47:
			return KEY_HOME;
		case 0x48:
			return KEY_UP;
		case 0x49:
			return KEY_PGUP;
		case 0x4B:
			return KEY_LEFT;
		case 0x4D:
			return KEY_RIGHT;
		case 0x4F:
			return KEY_END;
		case 0x50:
			return KEY_DOWN;
		case 0x51:
			return KEY_PGDN;
		case 0x52:
			return KEY_INS;
		case 0x53:
			return KEY_DEL;
		case 0x73:
			return KEY_CTRL_LEFT;
		case 0x74:
			return KEY_CTRL_RIGHT;
		case 0x75:
			return KEY_CTRL_END;
		case 0x77:
			return KEY_CTRL_HOME;
		case 0x8D:
			return KEY_CTRL_UP;
		case 0x91:
			return KEY_CTRL_DOWN;
		case 0x94:
			return KEY_CTRL_TAB;
		case 0xB8:
			return KEY_SHIFT_UP;
		case 0xB7:
			return KEY_SHIFT_HOME;
		case 0xBF:
			return KEY_SHIFT_END;
		case 0xB9:
			return KEY_SHIFT_PGUP;
		case 0xBB:
			return KEY_SHIFT_LEFT;
		case 0xBD:
			return KEY_SHIFT_RIGHT;
		case 0xC0:
			return KEY_SHIFT_DOWN;
		case 0xC1:
			return KEY_SHIFT_PGDN;
		case 0xDB:
			return KEY_SHIFT_CTRL_LEFT;
		case 0xDD:
			return KEY_SHIFT_CTRL_RIGHT;
		case 0xD8:
			return KEY_SHIFT_CTRL_UP;
		case 0xE0:
			return KEY_SHIFT_CTRL_DOWN;
		case 0xD7:
			return KEY_SHIFT_CTRL_HOME;
		case 0xDF:
			return KEY_SHIFT_CTRL_END;

		default:
			return KEY_UNKNOWN;
		}
		break;

	case 0x7F:
		return KEY_BACKSPACE;

	default:
		return ch;
	}
}
