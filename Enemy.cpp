#include "Enemy.h"

Enemy::Enemy(float pos_x, float pos_y) :
	movementSpeed_(1.F), rotationSpeed_(2.F)
{
	shape_.setFillColor(sf::Color::Red);
	shape_.setSize({ 50.F, 50.F });
	shape_.setPosition({ pos_x, pos_y });
	shape_.setOrigin({ shape_.getSize().x / 2.F, shape_.getSize().y / 2.F });
}

void Enemy::render(sf::RenderTarget& target) const
{
	target.draw(shape_);
}

const sf::FloatRect Enemy::getBounds() const
{
	return shape_.getGlobalBounds();
}

void Enemy::move(const Player& target)
{
	shape_.move((target.getPosition() - shape_.getPosition()).normalized() * movementSpeed_);
}
