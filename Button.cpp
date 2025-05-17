#include "Button.h"

Button::Button
	(
	sf::Font* font,
	const std::function<void()> onBtnPressed,
	std::string txt,
	float x_pos, float y_pos, 
	float width, float height
	) :
	text_(*font), btnState_(BtnState::INACTIVE), onBtnPressed(onBtnPressed)
{
	// Button shape
	shape_.setSize({ width, height });
	shape_.setOrigin({ width / 2.F, height / 2.F });
	shape_.setPosition({ x_pos, y_pos });

	shape_.setFillColor(sf::Color::Transparent);
	shape_.setOutlineThickness(3.f);
	shape_.setOutlineColor(sf::Color(0, 150, 255)); // Neonblau Rahmen

	// Button Text
	text_.setString(txt);
	text_.setOrigin(shape_.getOrigin());
	text_.setPosition(shape_.getPosition());
	text_.setFillColor(sf::Color(100, 220, 255)); // Hellblau/neon
}

void Button::update(const sf::Vector2f& mousePos)
{
	btnState_ = BtnState::INACTIVE;

	if (shape_.getGlobalBounds().contains(mousePos))
	{
		btnState_ = BtnState::HOVERED;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			btnState_ = BtnState::PRESSED;

			onBtnPressed();
		}
	}
}

void Button::render(sf::RenderTarget& target)
{
	switch (btnState_)
	{
	case BtnState::INACTIVE: 
		shape_.setFillColor(sf::Color::Transparent);
		shape_.setOutlineColor(sf::Color(0, 150, 255)); // Neonblau
		shape_.setScale({ 1.f, 1.f });
		break;
	case BtnState::HOVERED: 
		shape_.setFillColor(sf::Color(0, 150, 255, 80)); // leicht transparentes Blau
		shape_.setOutlineColor(sf::Color(50, 200, 255)); // helleres Blau
		shape_.setScale({ 1.05f, 1.05f });
		break;
	case BtnState::PRESSED:
		shape_.setFillColor(sf::Color(0, 100, 200, 140)); // dunkleres Blau, mehr Deckkraft
		shape_.setOutlineColor(sf::Color(0, 100, 255));
		shape_.setScale({ 0.98f, 0.98f }); // kleiner drücken
		break;
	}

	// Render
	target.draw(shape_);
	target.draw(text_);
}
