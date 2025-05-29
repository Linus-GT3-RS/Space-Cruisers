#pragma once

#include "SFML/Graphics.hpp"
#include "Cooldown.h"

enum class CooldownType
{
	SPRAY, SNIPE, /* TODO SPLASH, */
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
	//const bool isCooldownReady(CooldownType attack);

	bool useCooldown(CooldownType type);


private:
	sf::RectangleShape shape_;

	sf::Font font_; // replace later TODO mb use a static resource class with getters

	// Movement
	//float cooldownDash_; // TODO rename to HyperJump
	Cooldown cdHyperJump_;

	// Shooting
	/*float cooldownSpray_;
	float cooldownSnipe_;*/
	Cooldown cdSpray_;
	Cooldown cdSnipe_;
};

