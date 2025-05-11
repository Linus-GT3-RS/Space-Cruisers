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
		inline static const float movementSpeed = 1.F;
		// inline static const float rotationSpeed = 2.F;

		inline static const int maxEnemies = 15;
		inline static const int spawnTimerCounterMax = 50;
	};


	struct Player
	{
		// Form
		inline static const float width = 50.F;
		inline static const float height = 50.F;

		// Speed
		inline static const float dashSpeed = 250.F;
		inline static const float movementSpeed = 2.F;
		inline static const float rotationSpeed = 2.5F;

		// Cooldown
		inline static const int cooldownDashMax = 1000; 
		inline static const int cooldownAttackSprayMax = 20;
		inline static const int cooldownAttackSnipeMax = 250;
	};


	struct Bullet
	{
		inline static const float width = 5.F;
		inline static const float height = 20.F;

		// Speed
		inline static const float speed_spray = 8.F;
		inline static const float speed_snipe = 25.F;
	};


}