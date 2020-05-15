#include "IScene.h"
#include "WindowManager.h"

IScene::~IScene()
{
	for (auto gameObject : mRootGameObjectsVect)
	{
		gameObject->Clear();
		delete gameObject;
	}

	mRootGameObjectsVect.clear();
}

void IScene::Update()
{
	for (auto gameObject : mRootGameObjectsVect)
	{
		if (gameObject->IsUpdateActive())
		{
			gameObject->Update();
		}
	}
}

void IScene::Draw() const
{
	char* buffer = WindowManager::GetInstance()->GetBuffer();
	const int WINDOW_WIDTH = WindowManager::GetInstance()->GetWindowWidth();

	for (auto gameObject : mRootGameObjectsVect)
	{
		if (gameObject->IsRenderActive())
		{
			Vector2 position = gameObject->GetPosition();
			buffer[position.y * WINDOW_WIDTH + position.x] = gameObject->GetTexture();
		}
	}
}

void IScene::AddChild(GameObject* gameObject)
{
	mRootGameObjectsVect.push_back(gameObject);
}