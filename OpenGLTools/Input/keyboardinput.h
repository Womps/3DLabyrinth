#ifndef KEYBOARDINPUT_H
#define KEYBOARDINPUT_H

#include <array>
#include "abstractinput.h"

class KeyboardInput : public AbstractInput
{
public:
    KeyboardInput();

    bool key(int key) const {
        return mKeys[key];
    }
private:
    std::array<bool, SDL_NUM_SCANCODES> mKeys;

    void update(SDL_Event &event);
};

#endif // KEYBOARDINPUT_H
