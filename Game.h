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
	void updateBullets();
	void updateEnemies();

	void render();
	

private:
	// UI
	sf::RenderWindow* pWindow_;

	// Entities
	Player* pPlayer_;
	std::vector<Bullet*> bullets_;
	std::vector<Enemy*> enemies_;

	void pollEvents();	
};

