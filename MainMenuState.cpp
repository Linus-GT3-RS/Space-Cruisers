#include "MainMenuState.h"
#include <iostream>

MainMenuState::MainMenuState(sf::RenderTarget& target) :
    Gamestate(target), btn_(&font_)
{
    // Fonts
    if (!font_.openFromFile("Fonts/arial.ttf")) std::cout << "ERROR::GAME::GAME Font loading error" << "\n";
}

#pragma warning(push)
#pragma warning(disable: 4100) // remove
void MainMenuState::update(const float dt)
{
    // TODO unsch�n des immer machen?? oder lassen, wenn man des window sp�ter �ndern kann
    auto pWindow = dynamic_cast<sf::RenderWindow*>(&renderTarget_);
    assert(pWindow != nullptr);
    Gamestate::updateMouse(*pWindow);

    btn_.update(mousePos_c);
}
#pragma warning(pop)

void MainMenuState::render()
{
    btn_.render(renderTarget_);
}
