#include <assert.h>

#include "GameObject.h"
#include "IComponent.h"

void GameObject::Update()
{
	for (auto component : mComponentVect)
	{
		component->Update();
	}
}

void GameObject::Clear()
{
	for (auto& component : mComponentVect)
	{
		component->Clear();
		delete component;
	}

	mComponentVect.clear();
}

void GameObject::AddComponent(IComponent* component)
{
	assert(component != nullptr);

	component->SetParent(this);
	component->Init();

	mComponentVect.push_back(component);
}