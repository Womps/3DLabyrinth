#ifndef SHADER_H
#define SHADER_H

#include "tools.h"
#include <string>

class Shader : public GLResource
{
public:
    Shader(std::string const &path, GLenum type);

    ~Shader();

private:
    void compile(std::string const &src);
    std::string getSource(std::string const &path);
};

#endif // SHADER_H
