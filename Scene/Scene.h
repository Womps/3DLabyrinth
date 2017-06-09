#pragma once
#include <vector>
#include "../OpenGLTools/glm.h"

enum class SceneBlock {SOL, MUR, UNDEFINED};

class Scene {
public:
	Scene() = default;
	Scene(std::vector<std::vector<SceneBlock>> scene, float scale);

	SceneBlock get(glm::vec3 const &position) const;
	SceneBlock get(int x, int z) const;

	int getWidth() const;
	int getHeight() const;

	float getScale() const;

private:
	std::vector<std::vector<SceneBlock>> mBlocks;
	float mScale;
	int mWidth;
	int mHeight;
};