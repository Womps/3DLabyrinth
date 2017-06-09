#ifndef TEXTUREREPOSITORY_H
#define TEXTUREREPOSITORY_H

#include <unordered_map>
#include "texture.h"

class TextureRepository
{
public:
    GLuint image2D(std::string const &path);

private:
    std::unordered_map<std::string, std::unique_ptr<Texture>> mTextures;
};

#endif // TEXTUREREPOSITORY_H
