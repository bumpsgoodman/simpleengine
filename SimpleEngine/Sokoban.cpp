#include <string>

#include "Sokoban.h"
#include "File.h"
#include "PlayerController.h"
#include "PlayerCollider.h"
#include "BoxCollider.h"
#include "GoalCollider.h"
#include "GameController.h"

void Sokoban::Init()
{
	initMaze();

	GameObject* gameController = new GameObject;
	gameController->SetRenderActive(false);

	gameController->AddComponent(new GameController);
	AddChild(gameController);
}

void Sokoban::Clear()
{

}

void Sokoban::initMaze()
{
	File mazeFile("maze1.txt");
	const char* buffer = mazeFile.GetBuffer();
	int size = mazeFile.GetSize();

	std::vector<GameObject*> wallVect;
	std::vector<GameObject*> goalVect;
	std::vector<GameObject*> boxVect;
	std::vector<GameObject*> playerVect;

	int dx = 0;
	int dy = 0;
	for (int i = 0; i < size; i++)
	{
		GameObject* obj = nullptr;
		Vector2 position(dx, dy);
		std::string name;
		std::string tag;
		char texture = 0;

		switch (buffer[i])
		{
		case 'X':
			obj = new GameObject;

			name = "Wall";
			tag = "Wall";
			texture = 'X';

			wallVect.push_back(obj);
			break;
		case 'o':
			obj = new GameObject;
			obj->AddComponent(new BoxCollider);

			name = "Box";
			tag = "Box";
			texture = 'o';

			boxVect.push_back(obj);
			break;
		case 'O':
			obj = new GameObject;
			obj->AddComponent(new BoxCollider);

			name = "Box";
			tag = "Box";
			texture = 'O';

			boxVect.push_back(obj);
			break;
		case '.':
			obj = new GameObject;
			obj->AddComponent(new GoalCollider);

			name = "Goal";
			tag = "Goal";
			texture = '.';

			goalVect.push_back(obj);
			break;
		case 'p':
			obj = new GameObject;
			obj->AddComponent(new PlayerController);
			obj->AddComponent(new PlayerCollider);

			name = "Player";
			tag = "Player";
			texture = 'p';

			playerVect.push_back(obj);
			break;
		case 'P':
			obj = new GameObject;
			obj->AddComponent(new PlayerController);
			obj->AddComponent(new PlayerCollider);

			name = "Player";
			tag = "Player";
			texture = 'P';

			playerVect.push_back(obj);
			break;
		case '\n':
			dx = -1;
			dy++;
			break;
		default:
			break;
		}

		if (obj != nullptr)
		{
			obj->SetName(name);
			obj->SetTag(tag);
			obj->SetTexture(texture);
			obj->SetPosition(position);
		}

		dx++;
	}

	addChildToScene(wallVect);
	addChildToScene(boxVect);
	addChildToScene(goalVect);
	addChildToScene(playerVect);
}

void Sokoban::addChildToScene(std::vector<GameObject*>& vect)
{
	for (auto& gameObject : vect)
	{
		AddChild(gameObject);
	}
}