#include "Raycast.h"
#include "GameObject.h"
#include "SceneManager.h"
#include "Vector2.h"

GameObject* RayCastOrNull(const Vector2& origin, const Vector2& direction, int maxDistance)
{
	IScene* curScene = SceneManager::GetInstance()->GetActiveScene();

	Vector2 rayPosition = origin + direction;
	for (int i = 0; i < maxDistance; i++)
	{
		for (auto gameObject : curScene->GetRootGameObjects())
		{
			Vector2 targetPosition = gameObject->GetPosition();

			if (rayPosition == targetPosition)
			{
				return gameObject;
			}
		}

		rayPosition += direction;
	}

	return nullptr;
}