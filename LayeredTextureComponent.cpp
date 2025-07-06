#include "LayeredTextureComponent.h"

LayeredTextureComponent::~LayeredTextureComponent()
{
	for (auto ait = layers_.begin(); ait != layers_.end(); ait++)
	{
		delete (*ait)->second; // delete sprite
		delete (*ait); // delete pair
	}
}

void LayeredTextureComponent::pushBack(TextureKey key, sf::Sprite& sprite)
{
	auto pPair = new std::pair<TextureKey, sf::Sprite*>(key, &sprite);
	layers_.push_back(pPair);
}

void LayeredTextureComponent::render(const sf::RectangleShape& physicalBody, sf::RenderTarget& renderTarget)
{
	for (auto ait = layers_.begin(); ait != layers_.end(); ait++)
	{
		// apply transform properties of physical body onto render-sprites
		sf::Sprite* pCur = (*ait)->second;
		pCur->setPosition(physicalBody.getPosition());
		pCur->setRotation(physicalBody.getRotation());

		renderTarget.draw(*pCur);
	}
}
