#include "Gamestate.h"

sf::Vector2f Gamestate::mouse_pos_c{};

Gamestate::Gamestate(sf::RenderTarget& target) :
	isRunning_(true),
	renderTarget_(target)
{
}

Gamestate::~Gamestate()
{
}

void Gamestate::updateMouse(const sf::RenderWindow& target)
{
	Gamestate::mouse_pos_c.x = static_cast<float>(sf::Mouse::getPosition(target).x);
	Gamestate::mouse_pos_c.y = static_cast<float>(sf::Mouse::getPosition(target).y);
}
