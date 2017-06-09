#ifndef SHADERREPOSITORY_H
#define SHADERREPOSITORY_H

#include "shader.h"
#include <memory>
#include <unordered_map>

class ShaderRepository {
public:
    GLuint shader(std::string const &path, GLenum type);

private:
    std::unordered_map<std::string, std::unique_ptr<Shader>> mShaders;
};

#endif // SHADERREPOSITORY_H
