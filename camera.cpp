#include "camera.h"

CameraFPS::CameraFPS(glm::vec3 const &pos,
                     float speed, float sensitivity,
                     std::shared_ptr<MouseInput> mouseInput,
                     std::shared_ptr<KeyboardInput> keyboardInput) :
    mPos(pos), mLook(0.0, 0.0, 0.0), mUp(glm::vec3(0.0, 1.0, 0.0)),
    mMouseInput(mouseInput),
    mKeyboardInput(keyboardInput),
    mPhi(0.0), mTheta(0.0),
    mSpeed(speed), mSensitivity(sensitivity)
{
	// Z, S, Q, D : Qwerty way
    mKeyMap[FORWARD] = SDL_SCANCODE_W;
    mKeyMap[BACKWARD] = SDL_SCANCODE_S;
    mKeyMap[LEFT] = SDL_SCANCODE_A;
    mKeyMap[RIGHT] = SDL_SCANCODE_D;
}

void CameraFPS::mComputeForwardVector(void)
{
	// Calcul du vecteur de direction en fonction des coordonnées sphériques
	float phiRad = mPhi * M_PI / 180.0f;
	float thetaRad = mTheta * M_PI / 180.0f;

	float cPhi = cos(phiRad);
	float cTheta = cos(thetaRad);
	//float sPhi = sin(phiRad);
	float sTheta = sin(thetaRad);

	//mForward.y = sPhi;
	mForward.z = cPhi * cTheta;
	mForward.x = cPhi * sTheta;
}

void CameraFPS::update(void)
{
    // Mouse
	//mPhi -= mMouseInput->yRel() * mSensitivity;
	mTheta -= mMouseInput->xRel() * mSensitivity;

	if (mPhi > 89.0f)
		mPhi = 89.0f;

	else if (mPhi < -89.0f)
		mPhi = -89.0f;

	if (mTheta > 360.0f)
		mTheta = 0.0f;

	else if (mTheta < -360.0f)
		mTheta = 0.0f;

	mComputeForwardVector();

    // KeyBoard

    if(mKeyboardInput->key(mKeyMap[FORWARD]) == true)
        mPos += glm::vec3(mForward * mSpeed);

    if(mKeyboardInput->key(mKeyMap[BACKWARD]) == true)
        mPos -= glm::vec3(mForward * mSpeed);

    if(mKeyboardInput->key(mKeyMap[LEFT]) == true)
        mPos += glm::vec3(mLeft * mSpeed);

    if(mKeyboardInput->key(mKeyMap[RIGHT]) == true)
        mPos -= glm::vec3(mLeft * mSpeed);

    mLeft = glm::normalize(cross(mUp, mForward));

    mLook = mPos.xyz() + mForward;
}
