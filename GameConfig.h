#pragma once

/*
	Stores all Config Data
*/
namespace config
{
	struct Window
	{
		inline static const std::string title = "Space Cruisers";
		inline static const int width = 1440;
		inline static const int height = 900;
	};

	struct Enemies
	{
		inline static const int maxEnemies = 15;
		inline static const int spawnTimerCounterMax = 50;
	};

	struct Player
	{
		// Stats
		inline static const float dashSpeed = 250.F;
		inline static const float movementSpeed = 2.F;
		inline static const float rotationSpeed = 2.5F;

		// Cooldown
		inline static const int cooldownDashMax = 1000; 
		inline static const int cooldownAttackSprayMax = 20;
		inline static const int cooldownAttackSnipeMax = 50;
	};

	struct Bullet
	{
		inline static const float speed_spray = 8.F;
		inline static const float speed_snipe = 25.F;
	};


}