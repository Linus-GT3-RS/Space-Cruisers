#include "AnimationComponent.h"

void AnimationComponent::addAnimation(AnimationType key, Animation& anim)
{
	animations_.insert({ key, anim }); // TODO correct cmd? 
}
