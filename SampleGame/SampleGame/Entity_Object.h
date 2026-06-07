#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

enum class ShapeType
{
	Rectangle,
	Circle
};


class Entity_Object
{
private:
	std::unique_ptr<sf::Shape> shape;
public:
	Entity_Object(ShapeType type, float xPos, float yPos, float size, sf::Color color);

	void draw(sf::RenderWindow& window);
};

