#include "Level1State.h"

Level1State::Level1State(sf::RenderTarget& target) :
    counter_(0), Gamestate(target)
{
    pPlayer_ = new Player(renderTarget_.getSize().x / 2.F, renderTarget_.getSize().y / 2.F);
}

Level1State::~Level1State()
{
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

/*
    --------------------------------------------------------------------------
*/

void Level1State::update()
{
    // TODO unschön des immer machen?? oder lassen, wenn man des window später ändern kann
    auto pWindow = dynamic_cast<sf::RenderWindow*>(&renderTarget_); 
    assert(pWindow != nullptr);
    Gamestate::updateMouse(*pWindow);

    pPlayer_->update(Gamestate::mouse_pos_c, renderTarget_);

    updateBullets();

    updateEnemiesAndCombat();
}

void Level1State::render()
{
    // Bullets
    for (Bullet* b : bullets_)
    {
        b->render(renderTarget_);
    }

    // Player
    pPlayer_->render(renderTarget_);
    
    // Enemies
    for (Enemy* e : enemies_)
    {
        e->render(renderTarget_);
    }
}

/*
    --------------------------------------------------------------------------
*/

void Level1State::updateBullets()
{
    // Move existing Bullets
    for (int i = static_cast<int>(bullets_.size()) - 1; i >= 0; i--)
    {
        Bullet* pCur = bullets_[i];

        // Move
        pCur->move();

        // Border Collision Detection
        if (pCur->getPosition().y + pCur->getBounds().size.y <= 0.F || // top
            pCur->getPosition().y > static_cast<float>(renderTarget_.getSize().y) || // bottom
            pCur->getPosition().x + pCur->getBounds().size.x <= 0.F || // left
            pCur->getPosition().x > static_cast<float>(renderTarget_.getSize().x) // right
            )
        {
            // delete
            bullets_.erase(bullets_.begin() + i);
            delete pCur;
        }
    }

    // Spawn new Bullet
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && pPlayer_->isCooldownReady(CooldownType::SPRAY))
    {
        bullets_.push_back(new Bullet(
            pPlayer_->getPosition().x, pPlayer_->getPosition().y,
            (Gamestate::mouse_pos_c - sf::Vector2f{ pPlayer_->getPosition().x, pPlayer_->getPosition().y }).normalized(),
            cfg::Bullet::speed_spray
        ));
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && pPlayer_->isCooldownReady(CooldownType::SNIPE))
    {
        bullets_.push_back(new Bullet(
            pPlayer_->getPosition().x, pPlayer_->getPosition().y,
            (Gamestate::mouse_pos_c - sf::Vector2f{ pPlayer_->getPosition().x, pPlayer_->getPosition().y }).normalized(),
            cfg::Bullet::speed_snipe
        ));
    }
}

void Level1State::updateEnemiesAndCombat()
{
    // Update Combat
    for (int i = static_cast<int>(enemies_.size()) - 1; i >= 0; i--)
    {
        enemies_[i]->moveAndRotate(*pPlayer_);

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
    if (counter_ < cfg::Enemy::spawnTimerCounterMax) counter_++;
    if (counter_ >= cfg::Enemy::spawnTimerCounterMax && static_cast<int>(enemies_.size()) < cfg::Enemy::maxEnemies)
    {
        counter_ = 0;
        enemies_.push_back(new Enemy(
            static_cast<float>(rand() % renderTarget_.getSize().x),
            static_cast<float>(rand() % renderTarget_.getSize().y)
        ));
    }
}

