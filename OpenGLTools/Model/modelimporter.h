#ifndef MODELIMPORTER_H
#define MODELIMPORTER_H

#include <string>
#include "mesh.h"
#include "material.h"

// Cette classe charge tous les mesh et matériaux dans les classes correspondantes
struct ModelImporter
{
    ModelImporter(std::string const &path, TextureRepository &textureRepository);
    ~ModelImporter() = default;

    std::vector<Mesh> meshes;
    std::vector<Material> materials;
};

#endif // MODELIMPORTER_H
