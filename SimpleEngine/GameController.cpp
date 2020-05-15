#include "GameController.h"
#include "Application.h"
#include "GameObject.h"
#include "SceneManager.h"

void GameController::Init()
{
}

void GameController::Update()
{
	IScene* activeScene = SceneManager::GetInstance()->GetActiveScene();
	int goalCount = 0;

	for (auto obj : activeScene->GetRootGameObjects())
	{
		if (obj->GetTag() == "Goal" && obj->IsRenderActive())
		{
			goalCount++;
		}
	}
	
	if (goalCount == 0)
	{
		Application::Quit();
	}
}

void GameController::Clear()
{
}
