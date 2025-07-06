#pragma once

#include <list>
#include <utility>
#include "SFML/Graphics.hpp"

enum class TextureKey
{
	// Spaceship
	Boost, Engine, Weapons, Base

};

// use component to render multiple textures on top of each other
class LayeredTextureComponent
{
public:
	LayeredTextureComponent() = default;

	// deletes all sprites (texture layers)
	// also deletes other class specific stuff which is not important to know outside this class
	virtual ~LayeredTextureComponent();

	// adds new layer to the end
	// -> new top layer
	void pushBack(TextureKey key, sf::Sprite& sprite);

	// index 0 is rendered first onto physical body, each following index afterwards on top
	void render(const sf::RectangleShape& physicalBody, sf::RenderTarget& renderTarget);

private:
	std::list<std::pair<TextureKey, sf::Sprite*>*> layers_; 
};

