#pragma once
#include <string>
#include <unordered_map>
#include "Scene.h"

// Cette scène permet de charger une scène à partir d'une image PNG
class SceneLoader
{
public:
	SceneLoader();

	Scene load(std::string const &path,
			   std::unordered_map<unsigned, SceneBlock> colorType,
			   float scale);

	Scene load(std::string const &path) const;

private:
	std::unordered_map<std::string, Scene> mScenes;
};

