#ifndef ABSTRACTINPUT_H
#define ABSTRACTINPUT_H

#include <SDL2/SDL.h>

class AbstractInput
{
    friend class Device;
public:
    virtual ~AbstractInput() = default;

private:
    virtual void update(SDL_Event &event) = 0;
};

#endif // ABSTRACTINPUT_H
