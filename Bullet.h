#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(float pos_x, float pos_y, sf::Vector2f direc, float speed_);

	void render(sf::RenderTarget& target) const;

	void move(const float dt);
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getBounds() const;

private:
	sf::RectangleShape shape_;
	sf::Vector2f direc_;
	float speed_;
};

