#pragma once

//Outdated please use 'GameRectObj.h
#include <SFML/Graphics.hpp>
class CreateRect
{
private:
	sf::RectangleShape rect;
	int rWidth, rHeight;
	float rXpos, rYpos;
	sf::Color color;
public:
	CreateRect(int _rWidth, int _rHeight,float _rXpos, float _rYpos, sf::Color _color)
		:rWidth(_rWidth),rHeight(_rHeight), rXpos(_rXpos), rYpos(_rYpos), color(_color)
	{
		rect.setSize({ (float)rWidth, (float)rHeight });
		rect.setPosition({ rXpos, rYpos });
		rect.setFillColor(color);
	}
	void draw(sf::RenderWindow& window)
	{
		window.draw(rect);
	}
};

