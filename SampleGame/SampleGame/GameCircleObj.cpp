#include "GameCircleObj.h"


GameCircleObj::GameCircleObj(float xPos, float yPos, float radius, sf::Color color)
{
	circle.setPosition({ xPos, yPos });
	circle.setRadius(radius);
	circle.setFillColor(color);
}

void GameCircleObj::draw(sf::RenderWindow& window) { window.draw(circle); }