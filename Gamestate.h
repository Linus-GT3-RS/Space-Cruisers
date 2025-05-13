#pragma once

#include "SFML/Graphics.hpp"


// Base Class for all Gamestates
class Gamestate
{
public:
	Gamestate(sf::RenderTarget& target);
	virtual ~Gamestate();

	virtual void update(const float dt) = 0;
	virtual void render() = 0;

	const bool isRunning() const { return isRunning_; }

protected:
	bool isRunning_;
	sf::RenderTarget& renderTarget_;

	static sf::Vector2f mouse_pos_c;
	static void updateMouse(const sf::RenderWindow& target);
};

