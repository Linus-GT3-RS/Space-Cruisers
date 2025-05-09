#include "Enemy.h"

Enemy::Enemy(float pos_x, float pos_y)
{
	shape_.setFillColor(sf::Color::Red);
	shape_.setSize({ 35.F, 35.F });
	shape_.setPosition({ pos_x, pos_y });
}

void Enemy::render(sf::RenderTarget& target) const
{
	target.draw(shape_);
}

const sf::FloatRect Enemy::getBounds() const
{
	return shape_.getGlobalBounds();
}
