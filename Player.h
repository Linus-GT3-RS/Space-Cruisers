#pragma once

#include "SFML/Graphics.hpp"

enum class CooldownType
{
	SPRAY, SNIPE, SPLASH,
	DASH
};

class Player
{
public:
	Player(float pos_x, float pos_y);

	void update(const sf::Vector2f& mousePos, const sf::RenderTarget& window, const float dt);
	void render(sf::RenderTarget& target);

	void move(float dir_x, float dir_y, const float dt);
	const sf::Vector2f getPosition() const;
	const sf::Vector2f getSize() const;
	const bool isCooldownReady(CooldownType attack);


private:
	sf::RectangleShape shape_;

	// Movement
	float cooldownDash_;

	// Shooting
	float cooldownSpray_;
	float cooldownSnipe_;
};

