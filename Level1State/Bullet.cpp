#include "Bullet.h"

#include "../Config/GameConfig.h"
#include <stdexcept> // Include this header for std::runtime_error

Bullet::Bullet(float pos_x, float pos_y, sf::Texture& texture, sf::Vector2f direc, float speed_, int damage) :
	Entity(pos_x, pos_y, texture, 0),
	direc_(direc), speed_(speed_), damage_(damage)
{
	// Rotate to match direction
	setRotation(sf::radians(std::atan2(direc.y, direc.x)) + sf::degrees(90.F));
}

void Bullet::update(float dt)
{
	move(speed_ * direc_ * dt);
}

bool Bullet::damage(int damage)
{
	(void)damage; // ignore
	throw std::runtime_error("Bullet cannot take damage");
}

const int Bullet::getDamage() const
{
	return damage_;
}
