#include "mouseinput.h"

MouseInput::MouseInput()
{
    mButtons.fill(false);
}

void MouseInput::update(SDL_Event &event) {
    if(event.type == SDL_MOUSEMOTION) {
        mX = event.motion.x;
        mXRel = event.motion.xrel;
        mY = event.motion.y;
        mYRel = event.motion.yrel;
    }

    if(event.type == SDL_MOUSEBUTTONDOWN)
        mButtons[event.button.button] = true;

    if(event.type == SDL_MOUSEBUTTONUP)
        mButtons[event.button.button] = false;
}

void MouseInput::resetRelative() {
    mYRel = mXRel = 0;
}
