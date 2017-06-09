#ifndef MESH_H
#define MESH_H

#include <vector>
#include <assimp/mesh.h>
#include <GL/glew.h>
#include "../glm.h"

/* La structure Vertex représente un sommet
	Un sommet est représenté par
		Une position dans l'espace à 3 dimensions 
		Une normal dans l'espace à 3 dimensions et est de norme 1
		Une coordonnée de texture dans l'espace à 2 dimensions */
struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoord;
};

/* La structure Mesh prend en construction un aiMesh et construit 
	Un tableau de sommets,
	Un tableau d'indices lié à ces sommets
	Le matériel avec lequel le mesh est construit (pour faire simple, la couleur du mesh) */
struct Mesh
{
    Mesh(aiMesh const *mesh);

    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    unsigned materialIndex;
};

#endif // MESH_H
