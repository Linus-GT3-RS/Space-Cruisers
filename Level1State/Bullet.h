#pragma once

#include <SFML/Graphics.hpp>

#include "../Entity.h"

class Bullet : public Entity
{
public:
	Bullet(float pos_x, float pos_y, sf::Texture& texture, sf::Vector2f direc, float speed_, int damage);
	
	void update(float dt) override;
	bool damage(int damage) override;

	// Getters
	const int getDamage() const;

private:
	sf::Vector2f direc_;
	float speed_;
	int damage_;
};

