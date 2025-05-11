#pragma once

#include "SFML/Graphics.hpp"
#include "Player.h"

class Enemy
{
public:
	Enemy(float pos_x, float pos_y);

	void render(sf::RenderTarget& target) const;

	const sf::FloatRect getBounds() const;
	void moveAndRotate(const Player& target);

private:
	sf::RectangleShape shape_;
};

