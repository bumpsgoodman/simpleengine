#pragma once

class Game
{
public:
	Game() = default;
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	~Game() = default;

	void Start();
	void Shutdown();

private:
	void init();
	void input();
	void update();
	void draw() const;

private:
	int mFps = 15;
};