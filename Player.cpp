#include "Player.h"

Player::Player(float pos_x, float pos_y) :
	movementSpeed_(2.F), rotationSpeed_(2.5F),
	cooldownSpray_(0), cooldownSnipe_(0), attackCooldownMax_(40)
{
	shape_.setSize({ 50.F, 50.F });
	shape_.setFillColor(sf::Color::White);
	shape_.setPosition({ pos_x, pos_y });
	shape_.setOrigin({ shape_.getSize().x / 2.F, shape_.getSize().y / 2.F });
}


void Player::move(float dir_x, float dir_y)
{
	shape_.move({ dir_x * movementSpeed_, dir_y * movementSpeed_ });
}

const sf::Vector2f Player::getPosition() const
{
	return shape_.getPosition();
}

const sf::Vector2f Player::getSize() const
{
	return shape_.getSize();
}

const bool Player::canAttack(AttackType attack)
{
	if (attack == AttackType::SPRAY)
	{
		if (cooldownSpray_ < attackCooldownMax_) return false;
		cooldownSpray_ = 0;
		return true;
	}
	else if (attack == AttackType::SNIPE)
	{
		if (cooldownSnipe_ < attackCooldownMax_) return false;
		cooldownSnipe_ = 0;
		return true;
	}

	return false;
}

void Player::update(const sf::Vector2f& mousePos, const sf::RenderTarget& window)
{
	// Move player up or down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) move(0.F, -1.F);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) move(0.F, 1.F);

	// Move player left or right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) move(-1.F, 0.F);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) move(1.F, 0.F);

	// Rotate Player to point into direction of mouse
	sf::Vector2f dir2Mouse = (mousePos - shape_.getPosition()).normalized();
	shape_.setRotation(sf::radians(std::atan2(dir2Mouse.y, dir2Mouse.x)));

	// World Border Collision Detection
	if (shape_.getPosition().x - shape_.getOrigin().x <= 0.F) // Left of Screen
	{
		shape_.setPosition({ shape_.getOrigin().x, shape_.getPosition().y });
	}
	else if (shape_.getPosition().x + shape_.getOrigin().x >= window.getSize().x) // Right of Screen
	{
		shape_.setPosition({ window.getSize().x - shape_.getOrigin().x, shape_.getPosition().y });
	}
	if (shape_.getPosition().y - shape_.getOrigin().y <= 0.F) // Top of Screen
	{
		shape_.setPosition({ shape_.getPosition().x, shape_.getOrigin().y });
	}
	else if (shape_.getPosition().y + shape_.getOrigin().y >= window.getSize().y) // Bottom of Screen
	{
		shape_.setPosition({ shape_.getPosition().x, window.getSize().y - shape_.getOrigin().y });
	}

	// Update Cooldowns
	if (cooldownSpray_ < attackCooldownMax_) cooldownSpray_ += 2;
	if (cooldownSnipe_ < attackCooldownMax_) cooldownSnipe_++;
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(shape_);
}
