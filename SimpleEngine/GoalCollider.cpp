#include "GoalCollider.h"
#include "GameObject.h"

void GoalCollider::OnTriggerEnter(const GameObject* obj)
{
	if (obj->GetTag() == "Player" || obj->GetTag() == "Box")
	{
		GetParent()->SetRenderActive(false);
	}
}

void GoalCollider::OnTriggerExit(const GameObject* obj)
{
	if (obj->GetTag() == "Player" || obj->GetTag() == "Box")
	{
		GetParent()->SetRenderActive(true);
	}
}
