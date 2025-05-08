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
    for (Bullet* pCur : bullets_)
    {
        delete pCur;
    }
    for (Enemy* e : enemies_)
    {
        delete e;
    }
}

void Game::update()
{
    pPlayer_->update();

    updateBullets();

    updateEnemies();
}

void Game::updateBullets()
{
    // Move existing Bullets
    for (int i = static_cast<int>(bullets_.size()) - 1; i >= 0; i--)
    {
        Bullet* pCur = bullets_[i];

        // Move
        pCur->move();

        // Border Collision Detection
        if (pCur->getPosition().y + pCur->getBounds().size.y <= 0.F || // top
            pCur->getPosition().y > static_cast<float>(pWindow_->getSize().y) || // bottom
            pCur->getPosition().x + pCur->getBounds().size.x <= 0.F || // left
            pCur->getPosition().x  > static_cast<float>(pWindow_->getSize().x) // right
            )
        {
            // delete
            bullets_.erase(bullets_.begin() + i);
            delete pCur;
        }
    }

    // Spawn new Bullet
	if (pPlayer_->canAttack() && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) // TODO enprellung 
	{
		bullets_.push_back(
            new Bullet(pPlayer_->getPosition().x, pPlayer_->getPosition().y, sf::Vector2f(0.F, -1.F), 5.F)
        );
	}
}

void Game::updateEnemies() // TODO
{
    
}

void Game::render()
{
    // Clear
    pWindow_->clear();
    
    /*
        draw game objects
    */
	pPlayer_->render(*pWindow_);

    for (Bullet* b : bullets_)
    {
		b->render(*pWindow_);
    }

    for (Enemy* e : enemies_)
    {
        e->render(*pWindow_);
    }

    // Display
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
