#include "windowinput.h"

void WindowInput::update(SDL_Event &event) {
    if(event.type == SDL_WINDOWEVENT) {
        if(event.window.event == SDL_WINDOWEVENT_CLOSE)
            mRunning = false;
    }
}
