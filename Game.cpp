#include "Game.h"

#include <iostream>
#include <sstream>
#include "GameConfig.h"
#include "Level1State.h"
#include "MainMenuState.h"

Game::Game() :
    dt_(1.F)
{
    pWindow_ = new sf::RenderWindow(
                    sf::VideoMode{ {cfg::Window::width,cfg::Window::height} },
                    cfg::Window::title, sf::Style::Close
                    );
	pWindow_->setFramerateLimit(144);

    gamestates_.push(new Level1State(*pWindow_));
}

Game::~Game()
{
    delete pWindow_;	

    while (!gamestates_.empty())
    {
        delete gamestates_.top();
        gamestates_.pop();
    }
}


void Game::render()
{
    // Clear Window
    pWindow_->clear();
    
    gamestates_.top()->render();

    // Display Window
    pWindow_->display();
}

void Game::pollEvents()
{
    while (const std::optional event = pWindow_->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            pWindow_->close();
            break;
        }
    }
}

void Game::updateDeltaTime()
{
    dt_ = dtClock_.restart().asSeconds();
}

void Game::run()
{
    while (pWindow_->isOpen() && !gamestates_.empty())
    {

        if (gamestates_.top()->isRunning())
        {
            updateDeltaTime();

            gamestates_.top()->update(dt_);

		    render();
        }
        else
        {
            delete gamestates_.top();
            gamestates_.pop();
        }

        pollEvents();
    }
}
