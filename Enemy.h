#pragma once

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy(float pos_x, float pos_y, sf::Texture& texture, int health);
	virtual ~Enemy() = default;

	void update(float dt) override;

private:
};

