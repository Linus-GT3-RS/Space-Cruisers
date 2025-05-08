#pragma once

#include "SFML/Graphics.hpp"

class Player
{
public:
	Player(float pos_x, float pos_y);

	void update();
	void render(sf::RenderTarget& target);

	void move(float dir_x, float dir_y);
	const sf::Vector2f getPosition() const;
	const bool canAttack();


private:
	sf::RectangleShape shape_;

	// Movement
	float speed_;

	// Shooting
	int attackCooldown_;
	const int attackCooldownMax_;
};

