#ifndef PROGRAM_H
#define PROGRAM_H

#include "tools.h"

class Program : public GLResource
{
public:
    Program();

    void attach(GLuint shader);

    void link();

    ~Program();
};

#endif // PROGRAM_H
