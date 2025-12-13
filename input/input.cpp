#include "input.h"

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

namespace input {

// ================= ASCII MAPPING =================
static key mapAscii(int c) {
    if (c >= 'a' && c <= 'z')
        return key(c - 'a' + (int)key::A);

    if (c >= 'A' && c <= 'Z')
        return key(c - 'A' + (int)key::A);

    if (c >= '0' && c <= '9')
        return key(c - '0' + (int)key::Num0);

    switch (c) {
        case ' ':  return key::Space;
        case '\n':
        case '\r': return key::Enter;
        case '\t': return key::Tab;
        case 8:
        case 127:  return key::Backspace;
        case 27:   return key::Escape;
        default:   return key::Unknown;
    }
}

#ifdef _WIN32
// ================= WINDOWS =================
bool pollEvent(event& e) {
    if (!_kbhit())
        return false;

    int ch = _getch();

    // Arrow keys
    if (ch == 0 || ch == 224) {
        ch = _getch();
        switch (ch) {
            case 72: e.keycode = key::Up;    break;
            case 80: e.keycode = key::Down;  break;
            case 75: e.keycode = key::Left;  break;
            case 77: e.keycode = key::Right; break;
            default: e.keycode = key::Unknown;
        }
    }
    else {
        // IMPORTANT: handle Enter FIRST
        key k = mapAscii(ch);

        if (k != key::Unknown) {
            e.keycode = k;
        }
        // Ctrl + A to Z (1–26)
        else if (ch >= 1 && ch <= 26) {
            e.keycode = key((ch - 1) + (int)key::A);
        }
        else {
            e.keycode = key::Unknown;
        }
    }

    e.pressed = true;
    return true;
}

#else
// ================= LINUX =================
bool pollEvent(event& e) {
    static bool init = false;
    static termios oldt;

    if (!init) {
        termios newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
        init = true;
    }

    int ch = getchar();
    if (ch == EOF)
        return false;

    // Escape sequence (arrows)
    if (ch == 27) {
        int a = getchar();
        int b = getchar();

        if (a == '[') {
            switch (b) {
                case 'A': e.keycode = key::Up;    break;
                case 'B': e.keycode = key::Down;  break;
                case 'C': e.keycode = key::Right; break;
                case 'D': e.keycode = key::Left;  break;
                default:  e.keycode = key::Unknown;
            }
        } else {
            e.keycode = key::Escape;
        }
    }
    else {
        e.keycode = mapAscii(ch);
    }

    e.pressed = true;
    return true;
}
#endif

} // namespace input
