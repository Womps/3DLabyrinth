#include "SceneDisplayer.h"

SceneDisplayer::SceneDisplayer(ShaderRepository &shaderRepository,
							   std::unordered_map<SceneBlock, std::shared_ptr<ModelRenderer>> modelRenderers) :
	mModelRenderers(std::move(modelRenderers))
{
	static TextureRepository repository;
	mModelProgram.attach(shaderRepository.shader("../Shaders/model.vert", GL_VERTEX_SHADER));
	mModelProgram.attach(shaderRepository.shader("../Shaders/model.frag", GL_FRAGMENT_SHADER));
	mModelProgram.link();

	/* Récupère les locations */
	mMatricesLocation = glGetUniformLocation(mModelProgram, "matrices");
	mTextureLocation = glGetUniformLocation(mModelProgram, "diffuseTexture");
	mColorLocation = glGetUniformLocation(mModelProgram, "diffuseColor");
	mUseTextureLocation = glGetUniformLocation(mModelProgram, "useTexture");
}

void SceneDisplayer::draw(Scene const &scene, glm::mat4 const &camera, glm::mat4 const &perspective) {
	glUseProgram(mModelProgram);

	glUniform1i(mTextureLocation, 0);

#define WORLD 0
#define VIEW 1
#define PROJ 2

	glm::mat4 matrices[3];
	matrices[PROJ] = perspective;
	matrices[VIEW] = camera;

	for (int z = 0; z < scene.getHeight(); ++z) {
		for (int x = 0; x < scene.getWidth(); ++x) {
			matrices[WORLD] = glm::scale(glm::translate(glm::mat4(1.f), glm::vec3(x * scene.getScale(), 0, z * scene.getScale())),
									   	 glm::vec3(scene.getScale()));

			glUniformMatrix4fv(mMatricesLocation, 3, false, glm::value_ptr(matrices[0]));

			mModelRenderers[scene.get(x, z)]->draw(true, mColorLocation, mUseTextureLocation);
		}
	}
}