#pragma once

#include "Gamestate.h"
#include "SFML/Graphics.hpp"
#include "Entity.h"

class TestState : public Gamestate
{
public:
	TestState(sf::RenderTarget& target, std::stack<Gamestate*>& gamestates) 
		: Gamestate(target, gamestates), 
		ent1_(100.F, 100.F, text1_)
	{
		
	}

	virtual ~TestState() = default;

	void update(const float dt) override
	{
		(void)dt; // ignore error
	}

	void render() override
	{
		ent1_.render(renderTarget_);
	}

private:
	sf::Texture text1_;

	Entity ent1_;

};
