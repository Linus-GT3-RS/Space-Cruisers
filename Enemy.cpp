#include "Enemy.h"

Enemy::Enemy()
{
	shape_.setFillColor(sf::Color::Red);
	shape_.setSize({ 35.F, 35.F });
	shape_.setPosition({ 100.F, 100.F });
}

void Enemy::render(sf::RenderTarget& target) const
{
	target.draw(shape_);
}
