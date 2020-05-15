#pragma once

#include <string>
#include <vector>

#include "Vector2.h"
#include "IComponent.h"

class IComponent;

class GameObject final
{
public:
	GameObject() = default;
	GameObject(const GameObject&) = default;
	GameObject& operator=(const GameObject&) = default;
	~GameObject() = default;

	void Update();
	void Clear();

	void SetName(const std::string& name) { mName = name; }
	const std::string& GetName() const { return mName; }

	void SetTag(const std::string& tag) { mTag = tag; }
	const std::string& GetTag() const { return mTag; }

	void SetPosition(const Vector2& position) { mPosition = position; }
	const Vector2& GetPosition() const { return mPosition; }

	void SetTexture(char texture) { mTexture = texture; }
	char GetTexture() const { return mTexture; }

	void SetUpdateActive(bool bActive) { mbUpdateActive = bActive; }
	bool IsUpdateActive() const { return mbUpdateActive; }

	void SetRenderActive(bool bActive) { mbRenderActive = bActive; }
	bool IsRenderActive() const { return mbRenderActive; }

	void AddComponent(IComponent* component);

private:
	std::string mName = "";
	std::string mTag = "";

	Vector2 mPosition;
	char mTexture = 0;

	bool mbUpdateActive = true;
	bool mbRenderActive = true;

	std::vector<IComponent*> mComponentVect;
};