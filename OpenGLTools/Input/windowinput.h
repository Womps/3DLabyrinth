#ifndef WINDOWEVENT_H
#define WINDOWEVENT_H

#include "abstractinput.h"

class WindowInput : public AbstractInput
{
public:
    bool isRunning() const {
        return mRunning;
    }

private:
    bool mRunning = true;
    void update(SDL_Event &event);
};

#endif // WINDOWEVENT_H
