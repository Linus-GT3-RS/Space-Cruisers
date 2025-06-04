#include "Level1State.h"

#include <iostream>

Level1State::Level1State(sf::RenderTarget& target, std::stack<Gamestate*>& gamestates) :
    counter_(0.F), Gamestate(target, gamestates)
{
    pPlayer_ = new Player(renderTarget_.getSize().x / 2.F, renderTarget_.getSize().y / 2.F);

    if (!text_.loadFromFile("test.jpg", false, { {0, 0}, {80, 80} })) std::cout << "ERROR::Level1State::Level1State texture cant be loaded\n";
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

void Level1State::update(const float dt)
{
    // TODO unschön des immer machen?? oder lassen, wenn man des window später ändern kann
    auto pWindow = dynamic_cast<sf::RenderWindow*>(&renderTarget_); 
    assert(pWindow != nullptr);
    Gamestate::updateMouse(*pWindow);

    pPlayer_->update(Gamestate::mousePos_c, renderTarget_, dt);

    updateBullets(dt);

    updateEnemiesAndCombat(dt);
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

void Level1State::updateBullets(const float dt)
{
    // Move existing Bullets
    for (int i = static_cast<int>(bullets_.size()) - 1; i >= 0; i--)
    {
        Bullet* pCur = bullets_[i];

        // Move
        pCur->update(dt);

        // Border Collision Detection
        if (pCur->getGlobalBounds().position.y + pCur->getGlobalBounds().size.y <= 0.F || // top
            pCur->getGlobalBounds().position.y > static_cast<float>(renderTarget_.getSize().y) || // bottom
            pCur->getGlobalBounds().position.x + pCur->getGlobalBounds().size.x <= 0.F || // left
            pCur->getGlobalBounds().position.x > static_cast<float>(renderTarget_.getSize().x) // right
            )
        {
            // delete
            bullets_.erase(bullets_.begin() + i);
            delete pCur;
        }
    }

    // Spawn new Bullet
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && pPlayer_->useCooldown(CooldownType::SPRAY))
    {
        bullets_.push_back(new Bullet(
            pPlayer_->getPosition().x, pPlayer_->getPosition().y,
            text_,
            (Gamestate::mousePos_c - sf::Vector2f{ pPlayer_->getPosition().x, pPlayer_->getPosition().y }).normalized(),
            cfg::Bullet::speed_spray,
            cfg::Bullet::dmg_spray
        ));
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && pPlayer_->useCooldown(CooldownType::SNIPE))
    {
        bullets_.push_back(new Bullet(
            pPlayer_->getPosition().x, pPlayer_->getPosition().y,
            text_,
            (Gamestate::mousePos_c - sf::Vector2f{ pPlayer_->getPosition().x, pPlayer_->getPosition().y }).normalized(),
            cfg::Bullet::speed_snipe,
            cfg::Bullet::dmg_snipe
        ));
    }

    std::cout << "Bullets size:" << bullets_.size() << "\n";
}

void Level1State::updateEnemiesAndCombat(const float dt)
{
    // Update Combat
    for (int i = static_cast<int>(enemies_.size()) - 1; i >= 0; i--)
    {
        // Move and rotate Enemy towards player
        const sf::Vector2f dir2Player = (pPlayer_->getPosition() - enemies_[i]->getGlobalBounds().getCenter()).normalized();
        enemies_[i]->move(dir2Player * cfg::Enemy::movementSpeed * dt);
        enemies_[i]->setRotation(sf::radians(std::atan2(dir2Player.y, dir2Player.x)));

        // Check if enemy got hit
        for (int k = static_cast<int>(bullets_.size()) - 1; k >= 0; k--)
        {
            // check Bullet and Enemy if they interconnect
            if (bullets_[k]->getGlobalBounds().findIntersection(enemies_[i]->getGlobalBounds()))
            {
                if (enemies_[i]->damage(bullets_[k]->getDamage())) // check if enemy is destroyed
                {
                    delete enemies_[i];
                    enemies_.erase(enemies_.begin() + i);
                }

                // remove bullet
                delete bullets_[k];
                bullets_.erase(bullets_.begin() + k);

                break;
            }
        }
    }

    // Spawn Enemy
    if (counter_ < cfg::Enemy::spawnTimerCounterMax) counter_ += dt;
    if (counter_ >= cfg::Enemy::spawnTimerCounterMax && static_cast<int>(enemies_.size()) < cfg::Enemy::maxEnemies)
    {
        counter_ = 0;
        enemies_.push_back(new Enemy(
            static_cast<float>(rand() % renderTarget_.getSize().x),
            static_cast<float>(rand() % renderTarget_.getSize().y),
            text_,
            cfg::Enemy::health
        ));
    }
}

