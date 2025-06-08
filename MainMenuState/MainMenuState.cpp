#include "MainMenuState.h"
#include <iostream>
#include "../Level1State/Level1State.h"
#include "../Resources/Resources.h"

MainMenuState::MainMenuState(sf::RenderTarget& target, std::stack<Gamestate*>& gamestates) :
    Gamestate(target, gamestates), 
    btnNewGame_(&resc::Fonts::font_arial, [this]() { this->gamestates_.push(new Level1State(renderTarget_, gamestates_)); }, "New Game"),
    btnExit_(&resc::Fonts::font_arial, [this]() { this->isRunning_ = false; }, "Exit", 500.F, 500.F)
{
}

void MainMenuState::update(const float dt)
{
    // TODO unsch�n des immer machen?? oder lassen, wenn man des window sp�ter �ndern kann
    auto pWindow = dynamic_cast<sf::RenderWindow*>(&renderTarget_);
    assert(pWindow != nullptr);
    Gamestate::updateMouse(*pWindow);

    btnNewGame_.update(mousePos_c);
    btnExit_.update(mousePos_c);

    (void)dt;
}

void MainMenuState::render()
{
    btnNewGame_.render(renderTarget_);
    btnExit_.render(renderTarget_);
}
