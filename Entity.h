#pragma once

#include "SFML/Graphics.hpp"

class Entity
{
public:
	Entity(float pos_x, float pos_y, int health);
	virtual ~Entity() = default;

	virtual void update(float dt) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

	void move(sf::Vector2f dir);
	void setRotation(sf::Angle angle);

	virtual bool damage(int damage);

	// Getters
	sf::FloatRect getGlobalBounds() const;

private:
	sf::RectangleShape shape_; 

	int health_;
};

