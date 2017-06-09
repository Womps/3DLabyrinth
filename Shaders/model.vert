#version 330

// Données entrantes depuis le VAO
layout(location = 0) in vec3 inPos;
layout(location = 2) in vec2 inTextureCoordinate;

// Données sortantes vers le Fragment Shader
out vec2 textureCoordinate;

// Définit le type de matrices
#define WORLD 0
#define VIEW 1
#define PROJ 2

// Tableau des 3 matrices
uniform mat4 matrices[3];

void main(void) {
    gl_Position = matrices[PROJ] * matrices[VIEW] * matrices[WORLD] * vec4(inPos, 1);
    textureCoordinate = inTextureCoordinate;
}
