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
	};

	struct Bullet
	{
		inline static const float speed_spray = 8.F;
		inline static const float speed_snipe = 25.F;
	};


}