#pragma once

#include "SFML/Graphics.hpp"

class Animation
{
public:
	Animation(sf::Sprite& sprite, sf::Texture& animSheet,
			  sf::IntRect startFrame, int frameWidth, int numFrames);
	virtual ~Animation() = default;

	void update(float dt);
	void reset();

	friend class AnimationComponent;

private:
	sf::Sprite& sprite_;
	sf::Texture& animSheet_;

	sf::IntRect startFrame_;
	int frameWidth_;
	int numFrames_;
	int curFrame_;

	float curTimer_;
};

