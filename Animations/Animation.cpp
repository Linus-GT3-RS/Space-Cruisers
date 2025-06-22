#include "Animation.h"
#include "../Config/GameConfig.h"

Animation::Animation(sf::Sprite& sprite, sf::Texture& animSheet,
					 sf::IntRect startFrame, int frameWidth, int numFrames) :
	sprite_(sprite), animSheet_(animSheet),
	startFrame_(startFrame), numFrames_(numFrames), curFrame_(0), frameWidth_(frameWidth),
	curTimer_(0.F)
{
}

void Animation::update(float dt)
{
	curTimer_ += cfg::Animation::anim_speed * dt; 
	if (curTimer_ >= cfg::Animation::timer_max) // play next frame
	{
		curTimer_ = 0.F; // reset timer

		// play next frame -> loop to start if end is reached
		curFrame_ = (curFrame_ + 1) % numFrames_;
		sprite_.setTexture(animSheet_, true);
		sf::IntRect cur = startFrame_;
		cur.position.x = startFrame_.position.x + curFrame_ * frameWidth_;
		sprite_.setTextureRect(cur);
	}
}

void Animation::reset()
{
	curTimer_ = 0.F;
	curFrame_ = 0;
}
