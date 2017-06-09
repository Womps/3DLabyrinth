#include "program.h"
#include <string>
#include <stdexcept>

Program::Program()
{
    mId = glCreateProgram();
}

void Program::attach(GLuint shader) {
    glAttachShader(mId, shader);
}

void Program::link() {
    glLinkProgram(mId);

    int statLink;

    glGetProgramiv(mId, GL_LINK_STATUS, &statLink);

    if(statLink != true) {
        glGetProgramiv(mId, GL_INFO_LOG_LENGTH, &statLink);
        std::string log(statLink, 0);
        glGetProgramInfoLog(mId, statLink, &statLink, &log[0]);
        throw std::runtime_error(log);
    }
}

Program::~Program() {
    glDeleteProgram(mId);
}
