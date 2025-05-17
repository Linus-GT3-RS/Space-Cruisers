#pragma once

#include "SFML/Graphics.hpp"
#include <functional>
#include "Gamestate.h"

enum class BtnState
{
	INACTIVE = 0, HOVERED, PRESSED
};

class Button
{
public:
	Button(	sf::Font* font, 
			const std::function<void()> onBtnPressed = [](){},
			std::string txt = "Button",		
			float x_pos = 300.F, float y_pos = 300.F, 
			float width = 400.F, float height = 100.F
			);
	virtual ~Button() = default;

	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget& target);

private:
	sf::RectangleShape shape_;
	BtnState btnState_;

	sf::Text text_;

	const std::function<void()> onBtnPressed;

};

