#pragma once

#include "Gamestate.h"
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Cooldown.h"
#include "GameConfig.h"

class TestState : public Gamestate
{
public:
	TestState(sf::RenderTarget& target, std::stack<Gamestate*>& gamestates) 
		: Gamestate(target, gamestates)
		, cd_(cfg::Player::cooldownAttackSnipeMax, "testname",&font_, 50.F, 50.F)
	{
		// Fonts
		if (!font_.openFromFile("Fonts/arial.ttf")) std::cout << "ERROR::TestState::TestState Font loading error" << "\n";
	}

	virtual ~TestState() = default;

	void update(const float dt) override
	{
		(void)dt; // ignore error
		cd_.update(dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space)) 
		{
			std::cout << cd_.useCooldown() << "\n";
		}
	}

	void render() override
	{
		cd_.render(renderTarget_);
	}

private:
	sf::Texture text1_;
	sf::Font font_;

	Cooldown cd_;

};
