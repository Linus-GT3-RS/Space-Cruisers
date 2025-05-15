#pragma once

#include "Button.h"

#include "Gamestate.h"
#include <iostream>

class MainMenuState : public Gamestate
{
public:
	MainMenuState(sf::RenderTarget& target);
	virtual ~MainMenuState() = default;

	void update(const float dt) override;
	void render() override;

private:

	// Game Resources
	sf::Font font_; // TODO move all resources somewhere else
	Button btn_; // TODO test
	
};

