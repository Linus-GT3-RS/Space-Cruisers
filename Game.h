#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class Game
{
public:
	Game();
	virtual ~Game();

	const bool isRunning() const;
	void run();

	void update();
	void updatePlayer();

	void render();
	

private:
	// UI
	sf::RenderWindow* pWindow_;

	// Entities
	Player* pPlayer_;

	void pollEvents();	
};

