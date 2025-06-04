#pragma once

#include "Gamestate.h"
#include "GameConfig.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Level1State : public Gamestate
{
public:
	Level1State(sf::RenderTarget& target, std::stack<Gamestate*>& gamestates);
	virtual ~Level1State();

	void update(const float dt) override;
	void render() override;	

private:
	// Entities
	Player* pPlayer_;
	std::vector<Bullet*> bullets_;
	std::vector<Enemy*> enemies_;
	float counter_;

	void updateBullets(const float dt);
	void updateEnemiesAndCombat(const float dt);

	// Resources TODO make into own file
	sf::Texture text_;
};

