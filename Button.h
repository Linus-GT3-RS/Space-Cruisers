#pragma once

#include "SFML/Graphics.hpp"

#include "Gamestate.h"

enum class BtnState
{
	INACTIVE = 0, HOVERED, PRESSED
};

class Button
{
public:
	Button(	sf::Font* font, 
			// TODO Callback Lambda
			float x_pos = 300.F, float y_pos = 300.F, 
			float width = 400.F, float height = 100.F, 
			std::string txt = "Button"			
			);
	virtual ~Button() = default;

	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget& target);

private:
	sf::RectangleShape shape_;
	BtnState btnState_;

	sf::Text text_;

};

