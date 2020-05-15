#include "Collider.h"
#include "SceneManager.h"

static std::vector<GameObject*> sGameObjectVect;

void Collider::Init()
{
	sGameObjectVect.push_back(GetParent());
	mActiveScene = SceneManager::GetInstance()->GetActiveScene();
}

void Collider::Update()
{
	const Vector2& myPosition = GetParent()->GetPosition();

	if (mbTouching)
	{
		if (myPosition == mTouchingObject->GetPosition())
		{
			OnTriggerStay(mTouchingObject);
			return;
		}
		else
		{
			OnTriggerExit(mTouchingObject);

			mbTouching = false;
			mTouchingObject = nullptr;
		}
	}
	
	for (auto obj : sGameObjectVect)
	{
		if (obj == GetParent())
		{
			continue;
		}
		
		if (myPosition == obj->GetPosition())
		{
			mbTouching = true;
			mTouchingObject = obj;
			
			OnTriggerEnter(mTouchingObject);
			return;
		}
	}
}

void Collider::Clear()
{
	sGameObjectVect.clear();
}