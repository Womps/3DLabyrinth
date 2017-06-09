#include "keyboardinput.h"

KeyboardInput::KeyboardInput() {
    mKeys.fill(false);
}

void KeyboardInput::update(SDL_Event &event) {
    if(event.type == SDL_KEYDOWN)
        mKeys[event.key.keysym.scancode] = true;

    if(event.type == SDL_KEYUP)
        mKeys[event.key.keysym.scancode] = false;
}

