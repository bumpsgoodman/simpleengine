#pragma once

class InputManager final
{
public:
	InputManager() = default;
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;
	~InputManager() = default;	
	
	static InputManager* GetInstance();

	inline bool IsPressedKey(unsigned char key) { return mbPressedKeys[key]; }
	
	void KeyUp(unsigned char key);
	void KeyDown(unsigned char key);
	
	void ReleaseKey();
	
private:
	enum eMAX_KEY { MAX_KEY = 256 };
	bool mbPressedKeys[MAX_KEY] = { 0, };
	unsigned char mLastPressedKey = 0;
};