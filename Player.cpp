#include "Player.h"

#include "GameConfig.h"

Player::Player(float pos_x, float pos_y) :
	cooldownDash_(0.F),
	cooldownSpray_(0.F), cooldownSnipe_(0.F)
{
	shape_.setSize({ cfg::Player::width, cfg::Player::height });
	shape_.setFillColor(sf::Color::White);
	shape_.setPosition({ pos_x, pos_y });
	shape_.setOrigin({ shape_.getSize().x / 2.F, shape_.getSize().y / 2.F });
}


void Player::move(float dir_x, float dir_y, const float dt)
{
	shape_.move({ dir_x * cfg::Player::movementSpeed * dt, dir_y * cfg::Player::movementSpeed * dt });
}

const sf::Vector2f Player::getPosition() const
{
	return shape_.getPosition();
}

const sf::Vector2f Player::getSize() const
{
	return shape_.getSize();
}

const bool Player::isCooldownReady(CooldownType cdtype)
{
	if (cdtype == CooldownType::SPRAY)
	{
		if (cooldownSpray_ < cfg::Player::cooldownAttackSprayMax) return false;
		cooldownSpray_ = 0;
		return true;
	}
	else if (cdtype == CooldownType::SNIPE)
	{
		if (cooldownSnipe_ < cfg::Player::cooldownAttackSnipeMax) return false;
		cooldownSnipe_ = 0;
		return true;
	}
	else if (cdtype == CooldownType::DASH)
	{
		if (cooldownDash_ < cfg::Player::cooldownDashMax) return false;
		cooldownDash_ = 0;
		return true;
	}

	return false;
}

void Player::update(const sf::Vector2f& mousePos, const sf::RenderTarget& window, const float dt)
{
	/*
		Update Movement
	*/

	// Rotate Player to point into direction of mouse
	sf::Vector2f dir2Mouse = (mousePos - shape_.getPosition()).normalized();
	shape_.setRotation(sf::radians(std::atan2(dir2Mouse.y, dir2Mouse.x)));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space) && isCooldownReady(CooldownType::DASH))
	{
		shape_.move(dir2Mouse * cfg::Player::dashSpeed * dt);
	}
	else
	{
		// Move player up or down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) move(0.F, -1.F, dt);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) move(0.F, 1.F, dt);

		// Move player left or right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) move(-1.F, 0.F, dt);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) move(1.F, 0.F, dt);
	}

	/*
		World Border Collision Detection
	*/
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

	/*
		Update Cooldowns
	*/	
	if (cooldownSpray_ < cfg::Player::cooldownAttackSprayMax) cooldownSpray_ += dt;
	if (cooldownSnipe_ < cfg::Player::cooldownAttackSnipeMax) cooldownSnipe_ += dt;
	if (cooldownDash_ < cfg::Player::cooldownDashMax) cooldownDash_ += dt;
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(shape_);
}
