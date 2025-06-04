#include "Entity.h"

Entity::Entity(float pos_x, float pos_y, sf::Texture& texture, int health) :
	sprite_(texture),
	health_(health)
{
	sprite_.setPosition({ pos_x, pos_y });
}

void Entity::render(sf::RenderTarget& target)
{
	target.draw(sprite_);
}

void Entity::move(sf::Vector2f dir)
{
	sprite_.move(dir);
}

void Entity::setRotation(sf::Angle angle)
{
	sprite_.setRotation(angle);
}

bool Entity::damage(int damage)
{
	health_ -= damage;
	return health_ <= 0;
}

sf::FloatRect Entity::getGlobalBounds() const
{
	return sprite_.getGlobalBounds();
}
