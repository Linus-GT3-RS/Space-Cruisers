#include "Bullet.h"

#include "GameConfig.h"

Bullet::Bullet(float pos_x, float pos_y, sf::Vector2f direc, float speed_) :
	direc_(direc), speed_(speed_)
{
	// Shape
	shape_.setSize({ cfg::Bullet::width, cfg::Bullet::height });
	shape_.setFillColor(sf::Color::Cyan);
	shape_.setPosition({ pos_x, pos_y });
	shape_.setOrigin({ shape_.getSize().x / 2.F, shape_.getSize().y / 2.F });

	// Rotate to match direction
	shape_.setRotation(sf::radians(std::atan2(direc.y, direc.x)) + sf::degrees(90.F));
}

void Bullet::render(sf::RenderTarget& target) const
{
	target.draw(shape_);
}

void Bullet::move(const float dt)
{
	shape_.move(speed_ * direc_ * dt);
}

const sf::Vector2f Bullet::getPosition() const
{
	return shape_.getPosition();
}

const sf::FloatRect Bullet::getBounds() const
{
	return shape_.getGlobalBounds();
}
