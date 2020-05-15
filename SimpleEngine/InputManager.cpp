#include "InputManager.h"

InputManager* InputManager::GetInstance()
{
	static InputManager instance;
	return &instance;
}

void InputManager::KeyUp(unsigned char key)
{
	mbPressedKeys[key] = false;
}

void InputManager::KeyDown(unsigned char key)
{
	mbPressedKeys[key] = true;
}

void InputManager::ReleaseKey()
{
	for (int i = 0; i < MAX_KEY; i++)
	{
		mbPressedKeys[i] = false;
	}
}
