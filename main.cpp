#include "OpenGLTools/device.h"
#include "OpenGLTools/Input/windowinput.h"
#include "OpenGLTools/Input/mouseinput.h"
#include "OpenGLTools/Input/keyboardinput.h"
#include "OpenGLTools/shaderrepository.h"
#include "OpenGLTools/program.h"
#include "OpenGLTools/glm.h"
#include "OpenGLTools/texturerepository.h"
#include "OpenGLTools\Model\modelrenderer.h"
#include "camera.h"
#include <iostream>
#include <GL/glew.h>

#include "Scene\SceneLoader.h"
#include "Scene\SceneDisplayer.h"

using namespace std;

int main(int argc, char *argv[])
{
	/* Initialisation du Contexte OpenGL en version 3.3 */
    Device device(800, 600, "OpenGL", 3, 3, true);

	// Ajout de la gestion des événements
    auto windowInput(std::make_shared<WindowInput>());
	auto mouseInput(std::make_shared<MouseInput>());
	auto keyboardInput(std::make_shared<KeyboardInput>());
    device.assignInput(windowInput);
	device.assignInput(mouseInput);
	device.assignInput(keyboardInput);

	// On cache le curseur et on l'emprisonne dans la fenêtre.
	device.hideCursor();

	// Classes permettant de gérer les shaders et programs
	ShaderRepository shaderRepository;

	// Classe permettant de charger les textures
	TextureRepository textureRepository;

	glEnable(GL_DEPTH_TEST); // On active le test de profondeur

	// On crée notre caméra
	CameraFPS camera(glm::vec3(0, 1, 0.1), 0.01f, 1.f, mouseInput, keyboardInput);

	SceneLoader sceneLoader;

	// On charge la scène dans le loader
	sceneLoader.load("../Models/map.png",
	{ std::make_pair(0, SceneBlock::MUR), // couleur noir représente un mur
	  std::make_pair(0xffffff, SceneBlock::SOL) }, // Couleur blanche représente le sol
	1.f);

	SceneDisplayer displayer(shaderRepository,
	{ std::make_pair(SceneBlock::SOL, std::make_shared<ModelRenderer>("../Models/sol.obj", textureRepository)),
	 std::make_pair(SceneBlock::MUR, std::make_shared<ModelRenderer>("../Models/mur.obj", textureRepository)) });

	auto scene = sceneLoader.load("../Models/map.png");

    while(windowInput->isRunning())
	{
		if (!device.updateInputs())
			mouseInput->resetRelative();

		// On récupère la position de la caméra, avant de la mettre à jour. Pour sauvegarder l'ancienne position.
		glm::vec3 previousPos = camera.position();

		// On update la caméra
		camera.update();

		// On récupère la nouvelle position de la caméra, après l'avoir mise à jour.
		glm::vec3 newPos = camera.position();

		// On créée une "box", avec un léger agrandissement sur x et z, pour pouvoir détecter les objets d'un peu plus loin.
		glm::vec3 objectPosRight = glm::vec3(newPos.x, newPos.y, (newPos.z + 0.1));
		glm::vec3 objectPosLeft = glm::vec3(newPos.x, newPos.y, (newPos.z - 0.1));
		glm::vec3 objectPosFront = glm::vec3((newPos.x + 0.1), newPos.y, newPos.z);
		glm::vec3 objectPosBehind = glm::vec3((newPos.x - 0.1), newPos.y, newPos.z);

		// On récupère les objets proches, grâce aux "box" créées précédemment
		SceneBlock objectNearPosRight = scene.get(objectPosRight);
		SceneBlock objectNearPosLeft = scene.get(objectPosLeft);
		SceneBlock objectNearPosFront = scene.get(objectPosFront);
		SceneBlock objectNearPosBehind = scene.get(objectPosBehind);

		bool posHasChanged = false;

		float xDirectionMovement = newPos.x - previousPos.x;
		float zDirectionMovement = newPos.z - previousPos.z;

		//kif((objectNearPosRight == SceneBlock::MUR) && (objectNearPosFront == SceneBlock::MUR))
			// angle mur à droite


		// Si les objets proches sont des murs, on replace la caméra à l'ancienne position sauvegardée au préalable.
		if (objectNearPosRight == SceneBlock::MUR || objectNearPosLeft == SceneBlock::MUR)
		{
			previousPos = glm::vec3((previousPos.x + xDirectionMovement), previousPos.y, previousPos.z);
			posHasChanged = true;
		}
		
		if (objectNearPosFront == SceneBlock::MUR || objectNearPosBehind == SceneBlock::MUR)
		{
			previousPos = glm::vec3(previousPos.x, previousPos.y, (previousPos.z + zDirectionMovement));
			posHasChanged = true;
		}

		if (posHasChanged)
		{
			camera.setPos(previousPos);
		}

		// Efface l'écran et le depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// On l'affiche
		displayer.draw(scene, camera.view(), glm::perspective(glm::radians(70.f), (float)device.width() / device.height(), 0.01f, 500.f));

		device.swapBuffers();
    }

    return 0;
}