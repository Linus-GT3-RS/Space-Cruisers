#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

namespace resc
{
	struct Spaceships
	{
		inline static sf::Texture textu_test;
	};

	struct World
	{

	};

	struct Fonts
	{
		inline static sf::Font font_arial;
	};

	class ResourceManager
	{
	public:
		static void initResources();

	private:
		static void initFonts();
		static void initTextures();
	};
}