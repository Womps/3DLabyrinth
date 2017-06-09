#include "framebuffer.h"

static GLenum attachments[] = {GL_COLOR_ATTACHMENT0,
                               GL_COLOR_ATTACHMENT1,
                               GL_COLOR_ATTACHMENT2,
                               GL_COLOR_ATTACHMENT3,
                               GL_COLOR_ATTACHMENT4,
                               GL_COLOR_ATTACHMENT5,
                               GL_COLOR_ATTACHMENT6,
                               GL_COLOR_ATTACHMENT7,
                               GL_COLOR_ATTACHMENT8,
                               GL_COLOR_ATTACHMENT9,
                               GL_COLOR_ATTACHMENT10,
                               GL_COLOR_ATTACHMENT11,
                               GL_COLOR_ATTACHMENT12,
                               GL_COLOR_ATTACHMENT13,
                               GL_COLOR_ATTACHMENT14,
                               GL_COLOR_ATTACHMENT15
                              };

Framebuffer::Framebuffer()
{
    glGenFramebuffers(1, &mId);
}

void Framebuffer::addColorRenderTarget(std::shared_ptr<Texture> const &colorBuffer) {
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, mId);
    glFramebufferTexture(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + mColorBuffers.size(),
                         *colorBuffer, 0);

    mColorBuffers.push_back(colorBuffer);

    glDrawBuffers(mColorBuffers.size(), attachments);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
}

void Framebuffer::changeDepthBuffer(std::shared_ptr<Texture> const &depthBuffer) {
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, mId);
    glFramebufferTexture(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
                         *depthBuffer, 0);

    mDepthBuffer = depthBuffer;

    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
}

GLuint Framebuffer::nameColor(std::size_t i) {
    return *mColorBuffers[i];
}

GLuint Framebuffer::nameDepth() {
    return *mDepthBuffer;
}

Framebuffer::~Framebuffer() {
    glDeleteFramebuffers(1, &mId);
}
