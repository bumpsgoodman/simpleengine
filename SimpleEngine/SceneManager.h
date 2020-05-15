#pragma once

#include <string>
#include <unordered_map>

#include "IScene.h"

class SceneManager final
{
public:
	SceneManager() = default;
	SceneManager(const SceneManager&) = default;
	SceneManager& operator=(const SceneManager&) = default;
	~SceneManager() = default;

	static SceneManager* GetInstance();

	void Clear();

	std::unordered_map<std::string, IScene*>& GetScenesMap() { return mScenesMap; }

	void UnloadScene(const std::string& sceneName);
	void SetActiveScene(const std::string& sceneName);
	IScene* GetActiveScene() const { return mActiveScene; }

	template <class T>
	IScene* LoadScene(const std::string& sceneName)
	{
		UnloadScene(sceneName);

		IScene* scene = new T;
		scene->Init();
		scene->SetSceneName(sceneName);

		mScenesMap[sceneName] = scene;
		mActiveScene = scene;

		return scene;
	}

private:
	std::unordered_map<std::string, IScene*> mScenesMap;
	IScene* mActiveScene = nullptr;
};