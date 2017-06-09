#include "material.h"
#include <iostream>

Material::Material(aiMaterial *mtl, TextureRepository &textureManager,
                   const std::string &globalPath) {
    aiString texPath;

	// Si il y a une texture
    if(mtl->GetTexture(aiTextureType_DIFFUSE, 0, &texPath) == AI_SUCCESS) {
        std::string path = texPath.C_Str();

        if(path[0] == '.')
            path.erase(0, 1);

        if(path[0] == '/' || path[0] == '\\')
            path.erase(0, 1);

        for(auto &v : path)
            if(v == '\\')
                v = '/';
        path = globalPath + path; // On ajoute le chemin de la texture au chemin du dossier
        texture = textureManager.image2D(path);
        useTexture = true;
    }

	else {
		aiColor3D color;
		// Si couleur diffuse
		if (mtl->Get(AI_MATKEY_COLOR_DIFFUSE, color) == AI_SUCCESS)
			this->color = glm::vec3(color.r, color.g, color.b);
	}
}
