#pragma once

#include <vector>

#include "IComponent.h"

class GameObject;

class GameController : public IComponent
{
public:
	GameController() = default;
	GameController(const GameController&) = default;
	GameController& operator=(const GameController&) = default;
	virtual ~GameController() = default;
	
	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;	
};
