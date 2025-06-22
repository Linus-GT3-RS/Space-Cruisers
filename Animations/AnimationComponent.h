#pragma once

#include "Animation.h"
#include <map>
#include "AnimationTypes.h"

////////////////////////////////////////////////////////////
/// \brief Manages multiple animations and controls their playback.
///
/// The AnimationComponent class stores and manages a collection of Animation objects,
/// allowing switching between them and updating the currently active animation.
////////////////////////////////////////////////////////////
class AnimationComponent
{
public:
	////////////////////////////////////////////////////////////
	/// \brief Constructor.
	////////////////////////////////////////////////////////////
	AnimationComponent();

	////////////////////////////////////////////////////////////
	/// \brief Destructor. Cleans up all stored Animation pointers.
	////////////////////////////////////////////////////////////
	virtual ~AnimationComponent();

	////////////////////////////////////////////////////////////
	/// \brief Adds an animation to the component.
	///
	/// \param key The identifier for the animation.
	/// \param pAnim Pointer to the Animation object to add.
	////////////////////////////////////////////////////////////
	void addAnimation(AnimationType key, Animation* pAnim);

	////////////////////////////////////////////////////////////
	/// \brief Plays the animation associated with the given key.
	///
	/// If a different animation is played than the previous call, the current animation is reset and played from start.
	/// The current animation's update function is called with the provided delta time.
	///
	/// \param key The identifier for the animation to play.
	/// \param dt  The delta time (time since last update), used for animation timing.
	////////////////////////////////////////////////////////////
	void playAnimation(AnimationType key, const float dt);

private:
	////////////////////////////////////////////////////////////
	/// \brief Map storing all animations by their type.
	////////////////////////////////////////////////////////////
	std::map<AnimationType, Animation*> animations_;

	////////////////////////////////////////////////////////////
	/// \brief The type of the last animation that was played.
	////////////////////////////////////////////////////////////
	AnimationType lastAnimPlayed_;
};
