#pragma once

#include "SFML/Graphics.hpp"

class Entity
{
public:
	Entity(float pos_x, float pos_y, sf::Texture& texture);
	virtual ~Entity() = default;

	virtual void update(float dt) = 0;
	virtual void render(sf::RenderTarget& target);

	// Getters
	sf::FloatRect getGlobalBounds() const;

private:
	sf::Sprite sprite_;
};

