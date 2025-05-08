#pragma once

#include "SFML/Graphics.hpp"

class Player
{
public:
	Player(float pos_x, float pos_y);

	void move(float dir_x, float dir_y);
	void render(sf::RenderTarget& target);

private:
	sf::RectangleShape shape_;

	float speed_;
};

