#pragma once

#include "SFML/Graphics.hpp"

class Enemy
{
public:
	Enemy(float pos_x, float pos_y);

	void render(sf::RenderTarget& target) const;

	const sf::FloatRect getBounds() const;

private:
	sf::RectangleShape shape_;
};

