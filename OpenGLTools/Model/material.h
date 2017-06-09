#ifndef MATERIAL_H
#define MATERIAL_H

#include <assimp/material.h>
#include "../glm.h"
#include "../texturerepository.h"

/* La classe Material prend en argument un aiMaterial, le textureRepository
	et le path vers l'adresse du Dossier du Mesh
	
	Il construit une texture, et le cas échéant, il met la valeur useTexture à false et construit la variable color */
struct Material {
    Material(aiMaterial *mtl, TextureRepository &tr, std::string const &globalPath);

    glm::vec3 color;
    GLuint texture;
    bool useTexture = false;
};

#endif // MATERIAL_H
