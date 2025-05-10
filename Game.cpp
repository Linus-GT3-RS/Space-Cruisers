#include "Game.h"

#include <iostream>
#include <sstream>

Game::Game() :
    counter_(0), counterMax_(100), maxEnemies_(10)
{
    pWindow_ = new sf::RenderWindow(
                    sf::VideoMode{ {1440,900} },
                    "Space Cruisers", sf::Style::Close
                    );
	pWindow_->setFramerateLimit(144);

    pPlayer_ = new Player(pWindow_->getSize().x / 2.F, pWindow_->getSize().y / 2.F);
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
    pPlayer_->update(mouse_pos_, *pWindow_);

    updateBullets();

    updateEnemiesAndCombat();
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
            new Bullet(pPlayer_->getPosition().x, pPlayer_->getPosition().y,
                (mouse_pos_ - sf::Vector2f{ pPlayer_->getPosition().x, pPlayer_->getPosition().y }).normalized(),
                8.F)
        );
	}
}

void Game::updateEnemiesAndCombat()
{
    // Update Combat
    for (int i = static_cast<int>(enemies_.size()) - 1; i >= 0; i--)
    {
        enemies_[i]->move(*pPlayer_);

        // Check if enemy got hit
        for (int k = static_cast<int>(bullets_.size()) - 1; k >= 0; k--)
        {
            // Remove Bullet and Enemy if they interconnect
            if (bullets_[k]->getBounds().findIntersection(enemies_[i]->getBounds()))
            {
                delete bullets_[k];
                bullets_.erase(bullets_.begin() + k);

                delete enemies_[i];
                enemies_.erase(enemies_.begin() + i);

                break;
            }
        }
    }

    // Spawn Enemy
    if(counter_ < counterMax_) counter_++;    
    if (counter_ >= counterMax_ && static_cast<int>(enemies_.size()) < maxEnemies_)
    {
        counter_ = 0;
        enemies_.push_back(new Enemy(
                                pPlayer_->getPosition().x + + 250.F + (static_cast<float>(rand() % pWindow_->getSize().x) / 2.F),
                                pPlayer_->getPosition().y + 250.F + (static_cast<float>(rand() % pWindow_->getSize().y) / 2.F)
                            ));
    }
}

void Game::render()
{
    // Clear Window
    pWindow_->clear();
    
    /*
        draw game objects
    */
    // Bullets
    for (Bullet* b : bullets_)
    {
        b->render(*pWindow_);
    }

    // Player
	pPlayer_->render(*pWindow_);
    
    // Enemies
    for (Enemy* e : enemies_)
    {
        e->render(*pWindow_);
    }

    // Display Window
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

void Game::updateMouse()
{
    mouse_pos_.x = static_cast<float>(sf::Mouse::getPosition(*pWindow_).x);
    mouse_pos_.y = static_cast<float>(sf::Mouse::getPosition(*pWindow_).y);
}


void Game::run()
{
    while (isRunning())
    {
        pollEvents();
        updateMouse();

		update();

		render();
    }
}
