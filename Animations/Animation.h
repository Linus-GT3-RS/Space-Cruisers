#pragma once

#include "SFML/Graphics.hpp"

////////////////////////////////////////////////////////////
/// \brief Handles sprite sheet-based frame animations for a sprite.
/// Think of a sprite as a point that moves around, with a rectangular frame from a texture (sprite sheet) drawn on top.
/// By changing which frame is displayed over time, the sprite appears animated.
///
/// The Animation class manages a sequence of frames from a texture (sprite sheet),
/// updating the displayed frame based on a timer and looping through frames in a single row in the texture 1 by 1.
/// It supports multiple animations per texture by keeping the y-coordinate fixed.
////////////////////////////////////////////////////////////
class Animation
{
public:
	////////////////////////////////////////////////////////////
	/// \brief Constructs an Animation object.
	///
	/// \param sprite Reference to the sprite to animate.
	/// \param animSheet Reference to the texture containing animation frames.
	/// \param startFrame Rectangle specifying the first frame in the row.
	/// \param frameWidth Width of each animation frame.
	/// \param numFrames Number of frames in the animation row.
	////////////////////////////////////////////////////////////
	Animation(sf::Sprite& sprite, sf::Texture& animSheet,
     sf::IntRect startFrame, int frameWidth, int numFrames);

	////////////////////////////////////////////////////////////
	/// \brief Virtual destructor.
	////////////////////////////////////////////////////////////
	virtual ~Animation() = default;

	////////////////////////////////////////////////////////////
	/// \brief Updates the animation, advancing the frame if timer is reached
	///
	/// \param dt Delta time
	////////////////////////////////////////////////////////////
	void update(float dt);

	////////////////////////////////////////////////////////////
	/// \brief Resets the animation to the first frame.
	////////////////////////////////////////////////////////////
	void reset();

	friend class AnimationComponent;

private:
	sf::Sprite& sprite_;      //!< Reference to the sprite being animated
	sf::Texture& animSheet_;  //!< Reference to the texture containing animation frames

	sf::IntRect startFrame_;  //!< Rectangle of the first frame in the animation row
	int frameWidth_;          //!< Width of each frame in pixels
	int numFrames_;           //!< Total number of frames in the animation
	int curFrame_;            //!< Index of the current frame
	float curTimer_;          //!< Timer for frame switching
};
