#pragma once

#include "../Button.h"

#include "../Gamestate.h"
#include <iostream>
#include <stack>

class MainMenuState : public Gamestate
{
public:
	MainMenuState(sf::RenderTarget& target, std::stack<Gamestate*>& gamestates);
	virtual ~MainMenuState() = default;

	void update(const float dt) override;
	void render() override;

private:

	// Game Resources
	Button btnNewGame_;
	Button btnExit_;
	
};

