#pragma once

#include <assert.h>
#include <conio.h>
#include <Windows.h>

#include "Game.h"
#include "WindowManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Sokoban.h"

using namespace std;

int main(int argc, char* argv[])
{
	Game game;

	game.Start();
	game.Shutdown();

	return 0;
}

void Game::Start()
{
	init();
	
	int prevTime = GetTickCount();
	int fps = 0;

	while (1)
	{
		input();
		update();
		draw();

		int curTime = GetTickCount();
		if (curTime - prevTime >= 1000)
		{
			std::wstring fpsString = std::to_wstring(fps);
			SetConsoleTitle(fpsString.c_str());

			fps = 0;
			prevTime = curTime;
		}
		
		fps++;
	}
}

void Game::init()
{
	assert(SceneManager::GetInstance() != nullptr);
	assert(WindowManager::GetInstance() != nullptr);
	assert(InputManager::GetInstance() != nullptr);

	WindowManager::GetInstance()->CreateConsoleWindow(30, 20);

	SceneManager::GetInstance()->LoadScene<Sokoban>("Sokoban");
}

void Game::input()
{
	if (_kbhit())
	{
		unsigned char key = _getch();
		InputManager::GetInstance()->KeyDown(key);
	}
}

void Game::update()
{
	for (auto& scene : SceneManager::GetInstance()->GetScenesMap())
	{
		scene.second->Update();
	}

	InputManager::GetInstance()->ReleaseKey();
}

void Game::draw() const
{
	for (auto& scene : SceneManager::GetInstance()->GetScenesMap())
	{
		scene.second->Draw();
	}

	WindowManager::GetInstance()->Draw();
}

void Game::Shutdown()
{
	SceneManager::GetInstance()->Clear();
	WindowManager::GetInstance()->Clear();
}