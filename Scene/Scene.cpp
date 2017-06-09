#include <utility>
#include "Scene.h"

Scene::Scene(std::vector<std::vector<SceneBlock>> scene, float scale) :
	mBlocks(std::move(scene)),
	mScale(scale),
	mWidth(mBlocks[0].size()),
	mHeight(mBlocks.size()) {

	for (auto line : mBlocks)
		assert(line.size() == mBlocks[0].size());
}

SceneBlock Scene::get(int x, int z) const {
	if (x >= 0 && z >= 0 && x < mWidth && z < mHeight)
		return mBlocks[z][x];
	else
		return SceneBlock::UNDEFINED;
}

SceneBlock Scene::get(glm::vec3 const &position) const {
	glm::vec3 posInArray = position / mScale;

	int x = roundf(posInArray.x);
	int z = roundf(posInArray.z);

	return get(x, z);
}

int Scene::getWidth() const {
	return mWidth;
}

int Scene::getHeight() const {
	return mHeight;
}

float Scene::getScale() const {
	return mScale;
}
