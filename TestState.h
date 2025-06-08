#pragma once

#include "Gamestate.h"
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Level1State/Cooldown.h"
#include "Config/GameConfig.h"
#include "Resources\Resources.h"

class TestState : public Gamestate
{
public:
	TestState(sf::RenderTarget& target, std::stack<Gamestate*>& gamestates) 
		: Gamestate(target, gamestates)
		, cd_(cfg::Player::cooldownAttackSnipeMax, "testname",&resc::Fonts::font_arial, 50.F, 50.F)
	{
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

	Cooldown cd_;

};
