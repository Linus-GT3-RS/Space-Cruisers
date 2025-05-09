#include "Bullet.h"

Bullet::Bullet(float pos_x, float pos_y, sf::Vector2f direc, float speed_) :
	direc_(direc), speed_(speed_)
{
	shape_.setSize({ 10.F, 10.F });
	shape_.setFillColor(sf::Color::Blue);
	shape_.setPosition({ pos_x, pos_y });
}

void Bullet::render(sf::RenderTarget& target) const
{
	target.draw(shape_);
}

void Bullet::move()
{
	shape_.move(speed_ * direc_);
}

const sf::Vector2f Bullet::getPosition() const
{
	return shape_.getPosition();
}

const sf::FloatRect Bullet::getBounds() const
{
	return shape_.getGlobalBounds();
}
