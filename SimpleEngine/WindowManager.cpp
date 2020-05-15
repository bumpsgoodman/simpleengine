#include <windows.h>
#include <string.h>

#include "WindowManager.h"

static HANDLE shBuffer[2];
static int snScreenIndex;

WindowManager* WindowManager::GetInstance()
{
	static WindowManager instance;
	return &instance;
}

void WindowManager::CreateConsoleWindow(unsigned int windowWidth, unsigned int windowHeight)
{
	mWindowWidth = windowWidth;
	mWindowHeight = windowHeight;
	
	mBuffer[0] = new char[windowWidth * windowHeight + 1];
	memset(mBuffer[0], ' ', windowWidth * windowHeight);
	mBuffer[0][windowWidth * windowHeight] = 0;
	
	mBuffer[1] = new char[windowWidth * windowHeight + 1];
	memset(mBuffer[1], ' ', windowWidth * windowHeight);
	mBuffer[1][windowWidth * windowHeight] = 0;
	
	COORD size = { (SHORT)windowWidth, (SHORT)windowHeight };
    SMALL_RECT rect;
    rect.Left = 0;
    rect.Right = (windowWidth - 1) * 2;
    rect.Top = 0;
    rect.Bottom = (windowHeight - 1) * 2;
	 
    shBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleScreenBufferSize(shBuffer[0], size);
    SetConsoleWindowInfo(shBuffer[0], TRUE, &rect);

    shBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleScreenBufferSize(shBuffer[1], size);
    SetConsoleWindowInfo(shBuffer[1], TRUE, &rect);

    snScreenIndex = 0;
    
    hideCursor();
    
    SetConsoleActiveScreenBuffer(shBuffer[0]);
}

void WindowManager::Draw()
{
	COORD Coor = { 0, 0 };
    DWORD dw;
    SetConsoleCursorPosition(shBuffer[snScreenIndex], Coor);
    FillConsoleOutputCharacter(shBuffer[snScreenIndex], ' ', mWindowWidth * mWindowHeight, Coor, &dw );
    
    for (int y = 0; y < mWindowHeight; ++y)
    {
    	WriteFile(shBuffer[snScreenIndex], &mBuffer[mBufferIndex][y * mWindowWidth], mWindowWidth, &dw, NULL);
    	WriteFile(shBuffer[snScreenIndex], "\n", 1, &dw, NULL);
    }

	SetConsoleActiveScreenBuffer(shBuffer[snScreenIndex]);
	snScreenIndex = !snScreenIndex;
	
	memset(mBuffer[mBufferIndex], ' ', mWindowWidth * mWindowHeight);
	mBuffer[mBufferIndex][mWindowWidth * mWindowHeight] = 0;
	mBufferIndex = !mBufferIndex;
}

void WindowManager::Clear()
{
	CloseHandle(shBuffer[0]);
	CloseHandle(shBuffer[1]);

    delete[] mBuffer[0];
    delete[] mBuffer[1];
}

void WindowManager::hideCursor()
{
    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(shBuffer[0], &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(shBuffer[0], &cursorInfo);
    
    GetConsoleCursorInfo(shBuffer[1], &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(shBuffer[1], &cursorInfo);
}

void WindowManager::gotoXY(unsigned int x, unsigned int y)
{
	COORD pos={(SHORT)x,(SHORT)y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}
