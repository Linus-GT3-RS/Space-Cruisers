#include "Cooldown.h"

Cooldown::Cooldown(float cooldownMax, std::string name, sf::Font* font, float pos_x, float pos_y) :
	cooldownCur_(0.F), cooldownMax_(cooldownMax), text_(*font)
{
	shape_.setPosition({ pos_x, pos_y });
	shape_.setFillColor(sf::Color::Red);
	shape_.setSize({ 75.F, 75.F });

	text_.setOrigin(text_.getGlobalBounds().size);
	text_.setPosition({ pos_x, pos_y});
	text_.setCharacterSize(22U);
	text_.setString(name);
}

bool Cooldown::isReady() const
{
	return cooldownCur_ >= cooldownMax_;
}

bool Cooldown::useCooldown()
{
	if (cooldownCur_ < cooldownMax_) return false;
	cooldownCur_ = 0.F;
	return true;
}

void Cooldown::update(float dt)
{
	if (cooldownCur_ < cooldownMax_) cooldownCur_ += dt;
}

void Cooldown::render(sf::RenderTarget& target)
{
	// Give player visual feedback if cooldown is ready
	if (cooldownCur_ >= cooldownMax_) shape_.setFillColor(sf::Color::Green);
	else shape_.setFillColor(sf::Color::Red);

	target.draw(shape_);
	target.draw(text_);
}
