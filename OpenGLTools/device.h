#ifndef DEVICE_H
#define DEVICE_H

#include <SDL2/SDL.h>
#include <string>
#include <memory>
#include <vector>
#include "contextinitializer.h"
#include "Input/abstractinput.h"


class Device
{
public:
    Device(int width, int height, std::string name,
           int major = 3, int minor = 0,
           bool debug = false);

    void assignInput(std::shared_ptr<AbstractInput> input);
    bool updateInputs();

	int width() const {
		return mWidth;
	}
	
	int height() const {
		return mHeight;
	}

    void swapBuffers();

    void showCursor();
    void hideCursor();

    ~Device();

private:
    std::unique_ptr<ContextInitializer> mContextInitializer;
    std::string mWindowName;
    std::vector<std::shared_ptr<AbstractInput>> mInputs;
    int mWidth;
    int mHeight;
    SDL_Window *mMainWindow;
    SDL_GLContext mContext;
};

#endif // DEVICE_H
