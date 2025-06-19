#pragma once

#include "Animation.h"
#include <map>
#include "AnimationTypes.h"

class AnimationComponent
{
public:
	AnimationComponent();
	virtual ~AnimationComponent();

	void addAnimation(AnimationType key, Animation* pAnim);

	void playAnimation(AnimationType key, const float dt);

private:
	std::map<AnimationType, Animation*> animations_;
	AnimationType lastAnimPlayed_;
};

