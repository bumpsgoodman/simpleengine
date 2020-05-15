#pragma once

#include "IComponent.h"

class PlayerController final : public IComponent
{
public:
	PlayerController() = default;
	PlayerController(const PlayerController&) = default;
	PlayerController& operator=(const PlayerController&) = default;
	virtual ~PlayerController() = default;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;
};