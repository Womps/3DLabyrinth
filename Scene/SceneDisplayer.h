#pragma once
#include <unordered_map>
#include "Scene.h"
#include "../OpenGLTools/Model/modelrenderer.h"
#include "../OpenGLTools/program.h"
#include "../OpenGLTools/shaderrepository.h"

// Cette classe permet d'afficher une Sc�ne � l'�cran
class SceneDisplayer
{
public:
	/* ShaderRepository,    Un type de block est associ� � un mod�le 3D */
	SceneDisplayer(ShaderRepository &shaderRepository, std::unordered_map<SceneBlock, std::shared_ptr<ModelRenderer>> modelRenderers);

	void draw(Scene const & scene, glm::mat4 const &camera, glm::mat4 const &perspective);

private:
	std::unordered_map<SceneBlock, std::shared_ptr<ModelRenderer>> mModelRenderers;
	Program mModelProgram;
	GLint mMatricesLocation;
	GLint mUseTextureLocation;
	GLint mTextureLocation;
	GLint mColorLocation;
};

