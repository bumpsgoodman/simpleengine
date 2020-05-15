#pragma once

#include "Collider.h"

class BoxCollider : public Collider
{
public:
	BoxCollider() = default;
	BoxCollider(const BoxCollider&) = default;
	BoxCollider& operator=(const BoxCollider&) = default;
	virtual ~BoxCollider() = default;
	
	virtual void OnTriggerEnter(const GameObject* obj) override;
	virtual void OnTriggerExit(const GameObject* obj) override;
};
