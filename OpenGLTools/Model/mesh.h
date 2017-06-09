#ifndef MESH_H
#define MESH_H

#include <vector>
#include <assimp/mesh.h>
#include <GL/glew.h>
#include "../glm.h"

/* La structure Vertex repr�sente un sommet
	Un sommet est repr�sent� par
		Une position dans l'espace � 3 dimensions 
		Une normal dans l'espace � 3 dimensions et est de norme 1
		Une coordonn�e de texture dans l'espace � 2 dimensions */
struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoord;
};

/* La structure Mesh prend en construction un aiMesh et construit 
	Un tableau de sommets,
	Un tableau d'indices li� � ces sommets
	Le mat�riel avec lequel le mesh est construit (pour faire simple, la couleur du mesh) */
struct Mesh
{
    Mesh(aiMesh const *mesh);

    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    unsigned materialIndex;
};

#endif // MESH_H
