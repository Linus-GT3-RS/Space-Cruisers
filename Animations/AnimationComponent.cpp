#include "AnimationComponent.h"

AnimationComponent::AnimationComponent() :
	lastAnimPlayed_(AnimationType::INVALID)
{
}

AnimationComponent::~AnimationComponent()
{
	// Delete all Animation Objects
	for (auto& ait : animations_)
	{
		delete ait.second;
	}
}

void AnimationComponent::addAnimation(AnimationType key, Animation* pAnim)
{
	animations_.insert({ key, pAnim });
}

/*
	Plays Animation
	- if this anim differs from last one played, the current one gets resettet and played from the start
*/
void AnimationComponent::playAnimation(AnimationType key, const float dt)
{
	if (lastAnimPlayed_ != key) animations_[key]->reset();
	lastAnimPlayed_ = key;
	animations_[key]->update(dt);
}
