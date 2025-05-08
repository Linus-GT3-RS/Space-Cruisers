#pragma once

#include "SFML/Graphics.hpp"

class Enemy
{
public:
	Enemy();

	void render(sf::RenderTarget& target) const;

private:
	sf::RectangleShape shape_;
};

