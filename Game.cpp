#include "Game.h"

#include <iostream>
#include <sstream>

Game::Game()
{
    pWindow_ = new sf::RenderWindow(sf::VideoMode{ {600,800} }, 
        "Space Cruisers", sf::Style::Titlebar | sf::Style::Close);
	pWindow_->setFramerateLimit(144);

    pPlayer_ = new Player(50.F, 50.F);
}

Game::~Game()
{
    delete pWindow_;
	delete pPlayer_;
}

void Game::update()
{
	updatePlayer();
}

void Game::updatePlayer()
{
    // Move player up or down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) pPlayer_->move(0.F, -1.F);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) pPlayer_->move(0.F, 1.F);

	// Move player left or right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) pPlayer_->move(-1.F, 0.F);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) pPlayer_->move(1.F, 0.F);

	
}

void Game::render()
{
    pWindow_->clear();
    
    // draw game objects    
	pPlayer_->render(*pWindow_);

    pWindow_->display();
}

/*
    -------------------------- Helper Functions ------------------------------------------------------------------------------------- 
*/

const bool Game::isRunning() const
{
    return pWindow_->isOpen();
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


void Game::run()
{
    while (isRunning())
    {
        pollEvents();

		update();

		render();
    }
}
