#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <vector>
#include "texture.h"

class Framebuffer : public GLResource
{
public:
    Framebuffer();

    void addColorRenderTarget(std::shared_ptr<Texture> const &colorBuffer);
    void changeDepthBuffer(std::shared_ptr<Texture> const &depthBuffer);

    GLuint nameColor(std::size_t i);
    GLuint nameDepth();

    ~Framebuffer();
private:
    std::vector<std::shared_ptr<Texture>> mColorBuffers;
    std::shared_ptr<Texture> mDepthBuffer;
};

#endif // FRAMEBUFFER_H
