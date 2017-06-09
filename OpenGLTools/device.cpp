#include <iostream>
#include <utility>
#include <cassert>
#include <GL/glew.h>
#include <GL/gl.h>
#include "device.h"

void callback(GLenum, GLenum, GLuint, GLenum,
              GLsizei, GLchar const *message, void const*) {
    std::cerr << message << std::endl;
}

Device::Device(int width, int height, std::string name, int major, int minor, bool debug) :
    mContextInitializer(std::make_unique<ContextInitializer>(major, minor, debug)),
    mWindowName(std::move(name)) {

    mMainWindow = SDL_CreateWindow(mWindowName.c_str(),
                                   SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                   width, height,
                                   SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if(mMainWindow == nullptr)
        throw std::runtime_error(std::string("Unable to create window : ") + SDL_GetError());

    mContext = SDL_GL_CreateContext(mMainWindow);

    assert(mContext);

    glewExperimental = true;
    assert(glewInit() == GLEW_OK);

    if(debug) {
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        //glDebugMessageCallback((GLDEBUGPROC)callback, nullptr);
        //glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, true);
    }

    mWidth = width;
    mHeight = height;
}

void Device::assignInput(std::shared_ptr<AbstractInput> input) {
    mInputs.emplace_back(std::move(input));
}

void Device::swapBuffers() {
    SDL_GL_SwapWindow(mMainWindow);
}

bool Device::updateInputs() {
    SDL_Event event;
    bool updated = false;

    while(SDL_PollEvent(&event)) {
        for(auto &input : mInputs)
            input->update(event);
        updated = true;
    }

    return updated;
}

void Device::showCursor() {
    SDL_ShowCursor(true);
    SDL_SetWindowGrab(mMainWindow, SDL_FALSE);
    SDL_SetRelativeMouseMode(SDL_FALSE);
}

void Device::hideCursor() {
    SDL_ShowCursor(false);
    SDL_SetWindowGrab(mMainWindow, SDL_TRUE);
    SDL_SetRelativeMouseMode(SDL_TRUE);
}

Device::~Device() {
    SDL_GL_DeleteContext(mContext);
    SDL_DestroyWindow(mMainWindow);
	SDL_Quit();
}
