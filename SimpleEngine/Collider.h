#pragma once

#include <vector>

#include "IComponent.h"
#include "GameObject.h"

class IScene;

class Collider : public IComponent
{
public:
	Collider() = default;
	Collider(const Collider&) = default;
	Collider& operator=(const Collider&) = default;
	virtual ~Collider() = default;
	
	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;
	
	inline bool IsEnabled() const { return mbEnabled; }
	inline void SetEnable(bool bEnable) { mbEnabled = bEnable; }
	
	virtual void OnTriggerEnter(const GameObject* other) { }
	virtual void OnTriggerExit(const GameObject* other) { }
	virtual void OnTriggerStay(const GameObject* other) { }

private:
	IScene* mActiveScene = nullptr;
	
	bool mbEnabled = true;
	bool mbTouching = false;
	GameObject* mTouchingObject = nullptr;
};
