#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <vector>
#include <tuple>

class GUI;
class Object;


//Game Utilities
class Engine
{
public:
	Engine(
		GUI* gui,
		const std::string& levelFile,
		const std::string& playerAnimationFile,
		const std::string& EnemyAnimationFile);

	Engine(const Engine& src);
	Engine(Engine&& src);
	Engine& operator=(const Engine& src) noexcept;
	Engine& operator=(Engine&& src) noexcept;
	~Engine();

	bool getGameOver() const;
	bool getGameWon() const;
	void changeGameState(Object::Command command);
	std::vector<Object*> getObjects() const;
private:
	bool gameOver{ false };
	bool gameWon{ false };
	std::vector<Object*> objects;
	const GUI* gui;
};

#endif