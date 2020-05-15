#pragma once

#include "Collider.h"

class PlayerCollider final : public Collider
{
public:
	PlayerCollider() = default;
	PlayerCollider(const PlayerCollider&) = default;
	PlayerCollider& operator=(const PlayerCollider&) = default;
	virtual ~PlayerCollider() = default;

	virtual void OnTriggerEnter(const GameObject* other) override;
	virtual void OnTriggerExit(const GameObject* other) override;
};