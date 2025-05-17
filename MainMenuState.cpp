#include "MainMenuState.h"
#include <iostream>
#include "Level1State.h"

MainMenuState::MainMenuState(sf::RenderTarget& target, std::stack<Gamestate*>& gamestates) :
    Gamestate(target, gamestates), 
    btnNewGame_(&font_, [this]() { this->gamestates_.push(new Level1State(renderTarget_, gamestates_)); }, "New Game"),
    btnExit_(&font_, [this]() { this->isRunning_ = false; }, "Exit", 500.F, 500.F)
{
    // Fonts
    if (!font_.openFromFile("Fonts/arial.ttf")) std::cout << "ERROR::GAME::GAME Font loading error" << "\n";
}

#pragma warning(push)
#pragma warning(disable: 4100) // remove
void MainMenuState::update(const float dt)
{
    // TODO unschön des immer machen?? oder lassen, wenn man des window später ändern kann
    auto pWindow = dynamic_cast<sf::RenderWindow*>(&renderTarget_);
    assert(pWindow != nullptr);
    Gamestate::updateMouse(*pWindow);

    btnNewGame_.update(mousePos_c);
    btnExit_.update(mousePos_c);
}
#pragma warning(pop)

void MainMenuState::render()
{
    btnNewGame_.render(renderTarget_);
    btnExit_.render(renderTarget_);
}
