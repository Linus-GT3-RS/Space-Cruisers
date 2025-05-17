#include "Entity.h"

Entity::Entity(float pos_x, float pos_y, sf::Texture& texture) :
	sprite_(texture)
{
	sprite_.setPosition({ pos_x, pos_y });
}

void Entity::render(sf::RenderTarget& target)
{
	target.draw(sprite_);
}

sf::FloatRect Entity::getGlobalBounds() const
{
	return sprite_.getGlobalBounds();
}
