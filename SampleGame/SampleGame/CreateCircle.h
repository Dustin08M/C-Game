#pragma once

//Outdated please use 'GameCircleObj.h

#include <SFML/Graphics.hpp>
class CreateCircle
{
private:
	sf::CircleShape circle;
	int radius;
	float cXpos, cYpos;
	sf::Color color;

public:
	CreateCircle(int _radius, float _cXpos, float _cYpos, sf::Color _color)
		:radius(_radius), cXpos(_cXpos), cYpos(_cYpos), color(_color)
	{
		circle.setRadius((float)radius);
		circle.setPosition({ cXpos, cYpos });
		circle.setFillColor(color);
	}
	void draw(sf::RenderWindow& window)
	{
		window.draw(circle);
	}
};

