#include "PlayerController.h"
#include "GameObject.h"
#include "Raycast.h"
#include "InputManager.h"

void PlayerController::Init()
{

}

void PlayerController::Update()
{
	const Vector2& playerPos = GetParent()->GetPosition();
	Vector2 dir(0, 0);

	if (InputManager::GetInstance()->IsPressedKey('w'))
	{
		dir.y = -1;
	}
	if (InputManager::GetInstance()->IsPressedKey('a'))
	{
		dir.x = -1;
	}
	if (InputManager::GetInstance()->IsPressedKey('s'))
	{
		dir.y = 1;
	}
	if (InputManager::GetInstance()->IsPressedKey('d'))
	{
		dir.x = 1;
	}

	if (dir == Vector2::ZeroVector())
	{
		return;
	}

	GameObject* hittedObject = RayCastOrNull(playerPos, dir, 1);
	if (hittedObject != nullptr)
	{
		const std::string& tag = hittedObject->GetTag();

		if (tag == "Wall")
		{
			return;
		}
		else if (tag == "Box")
		{
			GameObject* nextHittedObject = RayCastOrNull(hittedObject->GetPosition(), dir, 1);

			if (nextHittedObject != nullptr)
			{
				const std::string& nextTag = nextHittedObject->GetTag();
				if (nextTag == "Wall" || nextTag == "Box")
				{
					return;
				}
			}

			hittedObject->SetPosition(hittedObject->GetPosition() + dir);
		}
	}

	GetParent()->SetPosition(playerPos + dir);
}

void PlayerController::Clear()
{

}