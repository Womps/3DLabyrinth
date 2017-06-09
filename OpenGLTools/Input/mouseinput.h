#ifndef MOUSEINPUT_H
#define MOUSEINPUT_H

#include <array>
#include "abstractinput.h"

class MouseInput : public AbstractInput
{
public:
    MouseInput();

    bool button(int button) const {
        return mButtons[button];
    }

    int x() const {
        return mX;
    }

    int y() const {
        return mY;
    }

    int xRel() const {
        return mXRel;
    }

    int yRel() const {
        return mYRel;
    }

    void resetRelative();

private:
    std::array<bool, 8> mButtons;
    int mX, mY, mXRel, mYRel;

    void update(SDL_Event &event);
};

#endif // MOUSEINPUT_H
