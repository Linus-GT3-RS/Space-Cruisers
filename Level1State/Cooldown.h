#pragma once

#include "SFML/Graphics.hpp"

class Cooldown
{
public:
	Cooldown(float cooldownMax, std::string name, sf::Font* font, float pos_x, float pos_y);

	bool isReady() const;
	bool useCooldown();

	void update(float dt);
	void render(sf::RenderTarget& target);	

private:
	float cooldownCur_;
	float cooldownMax_;

	sf::RectangleShape shape_;
	sf::Text text_;

};

