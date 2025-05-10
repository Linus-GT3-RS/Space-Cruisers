#pragma once

#include "SFML/Graphics.hpp"

enum class AttackType
{
	SPRAY, SNIPE, SPLASH
};

class Player
{
public:
	Player(float pos_x, float pos_y);

	void update(const sf::Vector2f& mousePos, const sf::RenderTarget& window);
	void render(sf::RenderTarget& target);

	void move(float dir_x, float dir_y);
	const sf::Vector2f getPosition() const;
	const sf::Vector2f getSize() const;
	const bool canAttack(AttackType attack);


private:
	sf::RectangleShape shape_;

	// Movement
	float movementSpeed_;
	float rotationSpeed_;

	// Shooting
	int cooldownSpray_;
	int cooldownSnipe_;
	const int attackCooldownMax_;
};

