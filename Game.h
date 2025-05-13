#pragma once

#include <SFML/Graphics.hpp>

#include "stack"
#include "Gamestate.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void run();

private:
	// UI
	sf::RenderWindow* pWindow_;

	sf::Clock dtClock_;
	float dt_;

	// Gamestate
	std::stack<Gamestate*> gamestates_; // TODO mb alle pointer in diesen containern in referenzen?

	// Functions
	void pollEvents();
	void updateDeltaTime();

	void render();
};

