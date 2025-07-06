#include "Entity.h"

Entity::Entity(float pos_x, float pos_y, int health) :
	health_(health)
{
	shape_.setPosition({ pos_x, pos_y });
}

void Entity::move(sf::Vector2f dir)
{
	shape_.move(dir);
}

void Entity::setRotation(sf::Angle angle)
{
	shape_.setRotation(angle);
}

bool Entity::damage(int damage)
{
	health_ -= damage;
	return health_ <= 0;
}

sf::FloatRect Entity::getGlobalBounds() const
{
	return shape_.getGlobalBounds();
}
