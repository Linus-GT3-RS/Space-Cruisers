#pragma once

#include "Gamestate.h"

class MainMenuState : public Gamestate
{
public:
	MainMenuState(sf::RenderTarget& target);
	virtual ~MainMenuState() = default;

	void update(const float dt) override;
	void render() override;

private:
	sf::RectangleShape shape_;

};

