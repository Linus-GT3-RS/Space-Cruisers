#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderTarget& target) :
    Gamestate(target)
{
    shape_.setSize({ 100.F, 100.F });
    shape_.setPosition({ 100.F, 100.F });
    shape_.setFillColor(sf::Color::White);
}

void MainMenuState::update(const float dt)
{
    // TODO unschön des immer machen?? oder lassen, wenn man des window später ändern kann
    auto pWindow = dynamic_cast<sf::RenderWindow*>(&renderTarget_);
    assert(pWindow != nullptr);
    Gamestate::updateMouse(*pWindow);

    if (shape_.getGlobalBounds().contains(mousePos_c))
    {
        shape_.setFillColor(sf::Color::Blue);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            shape_.setFillColor(sf::Color::Cyan);

            isRunning_ = (dt >= 0.F) ? false : true; // TODO change to sth usefull
        }
    }
    else
    {
        shape_.setFillColor(sf::Color::White);
    }

}

void MainMenuState::render()
{
	renderTarget_.draw(shape_);
}
