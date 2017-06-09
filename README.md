# 3DLabyrinth
3D Labyrinth developed by Romain EPIARD, with OpenGL library, in C++

The executable looks for `../Models/` directory to generate the labyrinth, and to use 3D Models and textures.

When you started the executable, you have to press `ALT + F4` to quit the executable. No menu have been implemented yet (sorry, it will come).

## Installation
To work on this project, you have to install some libraries. Here are the steps to follow :

- Clone this project
- Copy the content of `Libraries/lib` and `Libraries/include` directories. Paste these directories content into your C/C++ IDE system libraries `$SYSTEM_LIBRARIES/lib` and `$SYSTEM_LIBRARIES/include` (for example, with Visual Studio Community 2015 : `C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\lib` and `C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include`
- Copy the content of `Libraries/bin` and past it in the same directory as your executable file (`OpenGL.exe`).

## TODO

- Implement main menu, settings menu, and pause menu
- Implement Health, Skybox, rooms, traps...
