#pragma once

#include "SFML/Graphics.hpp"
#include <stack>

// Base Class for all Gamestates
class Gamestate
{
public:
	Gamestate(sf::RenderTarget& target, std::stack<Gamestate*>& gamestates); 
	virtual ~Gamestate();

	virtual void update(const float dt) = 0;
	virtual void render() = 0;

	const bool isRunning() const { return isRunning_; }

protected:
	bool isRunning_;
	sf::RenderTarget& renderTarget_;

	std::stack<Gamestate*>& gamestates_;

	static sf::Vector2f mousePos_c;
	static void updateMouse(const sf::RenderWindow& target);
};

