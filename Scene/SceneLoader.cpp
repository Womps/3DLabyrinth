#include <SDL2\SDL_image.h>
#include "SceneLoader.h"

SceneLoader::SceneLoader() {

}

Scene SceneLoader::load(std::string const &path,
	std::unordered_map<unsigned, SceneBlock> colorType, float scale) {
	SDL_Surface *surface = IMG_Load(path.c_str());

	if (surface == nullptr)
		throw std::runtime_error("unable to open " + path);

	unsigned *pixels = (unsigned*)surface->pixels;

	std::vector<std::vector<SceneBlock>> scene;

	for (int i = 0; i < surface->h; ++i) {
		std::vector<SceneBlock> line;
		for (int j = 0; j < surface->w; ++j) {
			unsigned color = pixels[i * surface->w + j];
			line.emplace_back(colorType[color & 0xffffff]);
		}
		scene.emplace_back(line);
	}

	SDL_FreeSurface(surface);

	mScenes[path] = Scene(scene, scale);

	return Scene(scene, scale);
}

Scene SceneLoader::load(std::string const & path) const
{
	auto it = mScenes.find(path);
	assert(it != mScenes.end());
	return it->second;
}
