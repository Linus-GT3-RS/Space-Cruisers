#include "Resources.h"

void resc::ResourceManager::initResources()
{
	initFonts();
	initTextures();
}

void resc::ResourceManager::initFonts()
{
	if (!Fonts::font_arial.openFromFile("Resources/Fonts/arial.ttf")) std::cout << "ERROR::ResourceManager::font_arial loading error!" << "\n";
}

void resc::ResourceManager::initTextures()
{
	if (!Spaceships::textu_test.loadFromFile("Resources/test.jpg", false, { {0, 0}, {80, 80} })) std::cout << "ERROR::ResourceManager::textu_test cant be loaded\n";
}