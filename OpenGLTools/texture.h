#ifndef TEXTURE_H
#define TEXTURE_H

#include <memory>
#include <string>
#include <SDL2/SDL_image.h>
#include "tools.h"

class Texture : public GLResource
{
public:
    Texture();

    ~Texture();

public:
    static std::unique_ptr<Texture> loadImage2D(std::string const &path);
    static std::shared_ptr<Texture> texture2D(GLuint w, GLuint h, GLenum internalFormat);

private:
    static void getFormats(SDL_Surface *img, GLenum &internalFormat, GLenum &format);
};

#endif // TEXTURE_H
