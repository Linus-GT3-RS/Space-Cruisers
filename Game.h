#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Game
{
public:
	Game();
	virtual ~Game();

	const bool isRunning() const;
	void run();

	void update();

	void render();
	

private:
	// UI
	sf::RenderWindow* pWindow_;
	sf::Vector2f mouse_pos_;

	// Entities
	Player* pPlayer_;
	std::vector<Bullet*> bullets_;

	// Enemies
	std::vector<Enemy*> enemies_;
	int maxEnemies_;
	int counter_;
	const int counterMax_;

	// Functions
	void pollEvents();	
	void updateMouse();
	void updateBullets();
	void updateEnemiesAndCombat();
};

