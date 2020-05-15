#pragma once

class WindowManager final
{
public:
	WindowManager() = default;
	WindowManager(const WindowManager&) = delete;
	WindowManager& operator=(const WindowManager&) = delete;
	~WindowManager() = default;
	
	static WindowManager* GetInstance();
	
	void CreateConsoleWindow(unsigned int windowWidth, unsigned int windowHeight);
	
	void Draw();
	void Clear();
	
	int GetWindowWidth() const { return mWindowWidth; }
	int GetWindowHeight() const { return mWindowHeight; }
	char* GetBuffer() const { return mBuffer[mBufferIndex]; }
	
private:
	void hideCursor();
	void gotoXY(unsigned int x, unsigned int y);
	
private:
	int mWindowWidth = 30;
	int mWindowHeight = 15;
	char* mBuffer[2] = { nullptr, };
	int mBufferIndex = 0;
};

#define gWindowManager WindowManager::GetInstance()
