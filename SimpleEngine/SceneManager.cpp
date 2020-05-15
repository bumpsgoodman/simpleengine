#include "SceneManager.h"

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;
	return &instance;
}

void SceneManager::Clear()
{
	for (auto& scene : mScenesMap)
	{
		scene.second->Clear();
		delete scene.second;
	}

	mScenesMap.clear();
}

void SceneManager::UnloadScene(const std::string& sceneName)
{
	auto got = mScenesMap.find(sceneName);

	if (got != mScenesMap.end())
	{
		got->second->Clear();
		delete got->second;

		mScenesMap.erase(got->first);
	}
}

void SceneManager::SetActiveScene(const std::string& sceneName)
{
	auto got = mScenesMap.find(sceneName);

	if (got != mScenesMap.end())
	{
		mActiveScene = got->second;
	}
}