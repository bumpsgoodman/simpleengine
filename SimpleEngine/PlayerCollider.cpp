#include "PlayerCollider.h"

void PlayerCollider::OnTriggerEnter(const GameObject* other)
{
	if (other->GetTag() == "Goal")
	{
		GetParent()->SetTexture('P');
	}
}

void PlayerCollider::OnTriggerExit(const GameObject* other)
{
	if (other->GetTag() == "Goal")
	{
		GetParent()->SetTexture('p');
	}
}