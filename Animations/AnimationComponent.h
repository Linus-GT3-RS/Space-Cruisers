#pragma once

#include "Animation.h"
#include <map>
#include "AnimationTypes.h"

class AnimationComponent
{
public:
	AnimationComponent();
	virtual ~AnimationComponent();

	void addAnimation(AnimationType key, Animation& anim);

private:
	std::map<AnimationType, Animation&> animations_;
};

