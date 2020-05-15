#pragma once

#include <string>
#include <vector>

#include "GameObject.h"

class IScene
{
public:
	IScene() = default;
	IScene(const IScene&) = default;
	IScene& operator=(const IScene&) = default;
	virtual ~IScene();

	virtual void Init() { };
	void Update();
	void Draw() const;
	virtual void Clear() { };

	void SetSceneName(const std::string& sceneName) { mSceneName = sceneName; }
	const std::string& GetSceneName() const { return mSceneName; };

	void AddChild(GameObject* gameObject);

	const std::vector<GameObject*>& GetRootGameObjects() const { return mRootGameObjectsVect; }

private:
	std::string mSceneName;
	std::vector<GameObject*> mRootGameObjectsVect;
};