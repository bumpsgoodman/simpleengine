#include "BoxCollider.h"
#include "GameObject.h"

void BoxCollider::OnTriggerEnter(const GameObject* obj)
{
	if (obj->GetTag() == "Goal")
	{
		GetParent()->SetTexture('O');
	}
}

void BoxCollider::OnTriggerExit(const GameObject* obj)
{
	if (obj->GetTag() == "Goal")
	{
		GetParent()->SetTexture('o');
	}
}
