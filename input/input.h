#pragma once
#include <cstdint>

namespace Input {

    enum class Key : uint16_t {
        None = 0,

        A, B, C, D, E, F, G, H, I, J,
        K, L, M, N, O, P, Q, R, S, T,
        U, V, W, X, Y, Z,

        Num0, Num1, Num2, Num3, Num4,
        Num5, Num6, Num7, Num8, Num9,

        Space, Enter, Escape, Tab, Backspace,

        Up, Down, Left, Right,

        F1, F2, F3, F4, F5, F6,
        F7, F8, F9, F10, F11, F12,

        Unknown
    };

    struct Event {
        Key key;
        bool pressed;
    };

    bool pollEvent(Event& e);
}
