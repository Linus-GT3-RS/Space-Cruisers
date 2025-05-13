#include "Gamestate.h"

sf::Vector2f Gamestate::mousePos_c{};

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
	Gamestate::mousePos_c.x = static_cast<float>(sf::Mouse::getPosition(target).x);
	Gamestate::mousePos_c.y = static_cast<float>(sf::Mouse::getPosition(target).y);
}
