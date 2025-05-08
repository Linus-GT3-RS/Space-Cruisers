#include "Player.h"

Player::Player(float pos_x, float pos_y) :
	speed_(5.F)
{
	shape_.setSize({ 50.F, 50.F });
	shape_.setFillColor(sf::Color::White);
	shape_.setPosition({ pos_x, pos_y });
}


void Player::move(float dir_x, float dir_y)
{
	shape_.move({ dir_x * speed_, dir_y * speed_ });
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(shape_);
}
