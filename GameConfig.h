#pragma once

/*
	Stores all Config Data
*/
namespace cfg
{
	struct Window
	{
		inline static const std::string title = "Space Cruisers";
		inline static const int width = 1440;
		inline static const int height = 900;
	};


	struct Enemy
	{
		// Form
		inline static const float width = 50.F;
		inline static const float height = 70.F;

		// Speed
		inline static const float movementSpeed = 90.F;

		inline static const int maxEnemies = 15;
		inline static const float spawnTimerCounterMax = 0.5F;
	};


	struct Player
	{
		// Form
		inline static const float width = 50.F;
		inline static const float height = 50.F;

		// Speed
		inline static const float dashSpeed = 45000;
		inline static const float movementSpeed = 250.F;

		// Cooldown
		inline static const float cooldownDashMax = 8.F; 
		inline static const float cooldownAttackSprayMax = 0.1F;
		inline static const float cooldownAttackSnipeMax = 10.F;
	};


	struct Bullet
	{
		inline static const float width = 5.F;
		inline static const float height = 20.F;

		// Speed
		inline static const float speed_spray = 850.F;
		inline static const float speed_snipe = 5000.F;
	};


}