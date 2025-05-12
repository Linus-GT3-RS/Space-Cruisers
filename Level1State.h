#pragma once

#include "Gamestate.h"
#include "GameConfig.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Level1State : public Gamestate
{
public:
	Level1State(sf::RenderTarget& target);
	virtual ~Level1State();

	void update() override;
	void render() override;	

private:
	// Entities
	Player* pPlayer_;
	std::vector<Bullet*> bullets_;
	std::vector<Enemy*> enemies_;
	int counter_;

	void updateBullets();
	void updateEnemiesAndCombat();
};

