#ifndef CAMERA_H
#define CAMERA_H

#include <map>
#include <memory>
#include "OpenGLTools/Input/keyboardinput.h"
#include "OpenGLTools/Input/mouseinput.h"
#include "OpenGLTools/glm.h"

enum CameraKeyMap{RIGHT, LEFT, FORWARD, BACKWARD};

/**
    * @brief A FreeFly Camera like FPS Games
    */
class CameraFPS
{
public:
    CameraFPS(glm::vec3 const &pos,
              float speed, float sensitivity,
              std::shared_ptr<MouseInput> mouseInput,
              std::shared_ptr<KeyboardInput> keyboardInput);

    void setSpeed(float speed) {mSpeed = speed;};

    void setSensitivity(float sensitivity) {mSensitivity = sensitivity;}

    glm::mat4 view() const {
        return glm::lookAt(mPos, mLook, mUp);
    }

	glm::vec3 position() const {
		return mPos;
	}

	glm::vec3 getForwardVector() const {
		return mForward;
	}

	void setPos(glm::vec3 pos)
	{
		mPos = pos;
	}

    virtual void update(void);

protected:
    glm::vec3 mPos;
    glm::vec3 mLook, mUp; //!< lookAt

    std::shared_ptr<MouseInput> mMouseInput;
    std::shared_ptr<KeyboardInput> mKeyboardInput;
    std::map<CameraKeyMap, SDL_Keycode> mKeyMap; //!< KeyMapping

    glm::vec3 mForward, mLeft; //!< vector forward and left for deplacement

    float mPhi, mTheta; //!< Angle for spherical coordinate

    float mSpeed, mSensitivity; //!< Variable for speed

    /**
        * @brief Compute the forward vector
        */
    void mComputeForwardVector(void);
};

#endif // CAMERA_H
