#include "input.h"

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

namespace Input {

static Key mapAscii(char c) {
    if (c >= 'a' && c <= 'z')
        return Key(c - 'a' + (int)Key::A);

    if (c >= 'A' && c <= 'Z')
        return Key(c - 'A' + (int)Key::A);

    if (c >= '0' && c <= '9')
        return Key(c - '0' + (int)Key::Num0);

    switch (c) {
        case ' ': return Key::Space;
        case '\n': return Key::Enter;
        case '\t': return Key::Tab;
        case 27:   return Key::Escape;
        case 8:    return Key::Backspace;
        default:   return Key::Unknown;
    }
}

bool pollEvent(Event& e) {
#ifdef _WIN32

    if (!_kbhit()) return false;

    int ch = _getch();

    if (ch == 0 || ch == 224) {
        ch = _getch();
        switch (ch) {
            case 72: e.key = Key::Up;    break;
            case 80: e.key = Key::Down;  break;
            case 75: e.key = Key::Left;  break;
            case 77: e.key = Key::Right; break;
            default: e.key = Key::Unknown;
        }
    } else {
        e.key = mapAscii((char)ch);
    }

    e.pressed = true;
    return true;

#else 

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
    if (ch == EOF) return false;

    if (ch == 27) {
        if (getchar() == '[') {
            switch (getchar()) {
                case 'A': e.key = Key::Up;    break;
                case 'B': e.key = Key::Down;  break;
                case 'D': e.key = Key::Left;  break;
                case 'C': e.key = Key::Right; break;
                default:  e.key = Key::Unknown;
            }
        }
    } else {
        e.key = mapAscii((char)ch);
    }

    e.pressed = true;
    return true;
#endif
}}
