#include "Enemy.h"

#include "GameConfig.h"

Enemy::Enemy(float pos_x, float pos_y)
{
	shape_.setFillColor(sf::Color::Red);
	shape_.setSize({ cfg::Enemy::width, cfg::Enemy::height });
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

void Enemy::moveAndRotate(const Player& target, const float dt)
{
	const sf::Vector2f dir2Player = (target.getPosition() - shape_.getPosition()).normalized();

	// Move Enemy to Player
	shape_.move(dir2Player * cfg::Enemy::movementSpeed * dt);

	// Rotate Enemy to Player
	shape_.setRotation(sf::radians(std::atan2(dir2Player.y, dir2Player.x)));
}
