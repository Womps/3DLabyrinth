#include "modelimporter.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

ModelImporter::ModelImporter(const std::string &path, TextureRepository &texManager) {
    Assimp::Importer imp;

    std::string globalPath;
    std::size_t last = path.find_last_of('/');

	// On récupère le chemin global
    if(last != std::string::npos) {
        globalPath = path;
        globalPath.erase(last);
        globalPath += "/";
    }

    else
        globalPath = "./";

	// On charge la scène
    aiScene const *scene = imp.ReadFile(path, aiProcessPreset_TargetRealtime_Fast | aiProcess_FlipUVs);

    if(scene == nullptr)
        throw std::runtime_error(path + " does not opened");

	// Pour chaque mesh
    for(unsigned i = 0; i < scene->mNumMeshes; ++i)
        meshes.emplace_back(scene->mMeshes[i]);

	// Pour chaque materiel
    for(unsigned i = 0; i < scene->mNumMaterials; ++i)
        materials.emplace_back(scene->mMaterials[i], texManager, globalPath);
}
