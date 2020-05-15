#pragma once

#include "Collider.h"

class GoalCollider : public Collider
{
public:
	GoalCollider() = default;
	GoalCollider(const GoalCollider&) = default;
	GoalCollider& operator=(const GoalCollider&) = default;
	virtual ~GoalCollider() = default;
	
	virtual void OnTriggerEnter(const GameObject* obj) override;
	virtual void OnTriggerExit(const GameObject* obj) override;
};
