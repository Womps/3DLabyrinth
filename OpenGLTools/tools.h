#ifndef TOOLS_H
#define TOOLS_H

#include <GL/glew.h>

struct NonCopyable {
public:
    NonCopyable() = default;
    NonCopyable(NonCopyable const&) = delete;
    NonCopyable &operator=(NonCopyable const &) = delete;

    virtual ~NonCopyable() = default;
};

class GLResource : NonCopyable {
public:
    operator GLuint() {
        return mId;
    }

    virtual ~GLResource() = default;

protected:
    GLuint mId = 0;
};

#endif // TOOLS_H
