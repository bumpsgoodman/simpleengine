#pragma once

class GameObject;

class IComponent
{
public:
	IComponent() = default;
	IComponent(const IComponent&) = default;
	IComponent& operator=(const IComponent&) = default;
	virtual ~IComponent() = default;

	virtual void Init() { };
	virtual void Update() { };
	virtual void Clear() { };

	void SetParent(GameObject* parent) { mParent = parent; }
	GameObject* GetParent() const { return mParent; }

private:
	GameObject* mParent = nullptr;
};