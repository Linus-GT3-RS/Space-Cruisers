#include "Player.h"

#include "GameConfig.h"
#include <iostream>

Player::Player(float pos_x, float pos_y) :
	cdHyperJump_(cfg::Player::cooldownDashMax, "HyperJ", &font_, 1300.F, 800.F),
	cdSpray_(cfg::Player::cooldownAttackSprayMax, "SprayA", &font_, 1150.F, 800.F),
	cdSnipe_(cfg::Player::cooldownAttackSnipeMax, "SnipeA", &font_, 1000.F, 800.F)
{
	shape_.setSize({ cfg::Player::width, cfg::Player::height });
	shape_.setFillColor(sf::Color::White);
	shape_.setPosition({ pos_x, pos_y });
	shape_.setOrigin({ shape_.getSize().x / 2.F, shape_.getSize().y / 2.F });

	if (!font_.openFromFile("Fonts/arial.ttf")) std::cout << "ERROR::Player::Player Font loading error" << "\n";
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

bool Player::useCooldown(CooldownType type)
{
	switch (type)
	{
	case CooldownType::SPRAY:
		return cdSpray_.useCooldown();
		break;
	case CooldownType::SNIPE:
		return cdSnipe_.useCooldown();
		break;
	default:
		return false;
	}
}

void Player::update(const sf::Vector2f& mousePos, const sf::RenderTarget& window, const float dt)
{
	/*
		Update Movement
	*/

	// Rotate Player to point into direction of mouse
	sf::Vector2f dir2Mouse = (mousePos - shape_.getPosition()).normalized();
	shape_.setRotation(sf::radians(std::atan2(dir2Mouse.y, dir2Mouse.x)));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space) && cdHyperJump_.useCooldown())
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
	cdHyperJump_.update(dt);
	cdSpray_.update(dt);
	cdSnipe_.update(dt);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(shape_);
	cdHyperJump_.render(target);
	cdSpray_.render(target);
	cdSnipe_.render(target);
}
