#include <vector>

#include "IScene.h"

class Sokoban final : public IScene
{
public:
	Sokoban() = default;
	Sokoban(const Sokoban&) = default;
	Sokoban& operator=(const Sokoban&) = default;
	virtual ~Sokoban() = default;

	virtual void Init() override;
	virtual void Clear() override;

private:
	void initMaze();

	void addChildForVect(std::vector<GameObject*>& vect);
};