#include "GameRectObj.h"

								//Position					//Size				//Color
GameRectObj::GameRectObj(float xPos, float yPos, float rWidth, float rHeight,sf::Color color)
{
	rect.setPosition({ xPos, yPos });
	rect.setSize({ rWidth, rHeight });
	rect.setFillColor(color);
}

void GameRectObj::draw(sf::RenderWindow& window) { window.draw(rect); }
