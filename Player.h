#pragma once

#include "SFML/Graphics.hpp"

class Player
{
public:
	Player(float pos_x, float pos_y);

	void update(const sf::Vector2f& mousePos, const sf::RenderTarget& window);
	void render(sf::RenderTarget& target);

	void move(float dir_x, float dir_y);
	const sf::Vector2f getPosition() const;
	const sf::Vector2f getSize() const;
	const bool canAttack();


private:
	sf::RectangleShape shape_;

	// Movement
	float movementSpeed_;
	float rotationSpeed_;

	// Shooting
	int attackCooldown_;
	const int attackCooldownMax_;
};

