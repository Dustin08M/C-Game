#pragma once

//Come back once you figure out how to use this for either creating rect or sphere
#include<SFML/Graphics.hpp>
#include <iostream>
#include <variant>
#include <vector>

class ShapeObject
{
private:
	std::variant<sf::RectangleShape, sf::CircleShape> shape;

public:
	ShapeObject(const sf::RectangleShape& rect)
		:shape(rect)
	{
	}

	ShapeObject(const sf::CircleShape& circle)
		:shape(circle)
	{
	}
	void draw(sf::RenderWindow& window)
	{
		std::visit([&window](auto& s)
		{
			window.draw(s);
		}, shape);
	}
};

