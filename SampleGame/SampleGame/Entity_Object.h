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
	float speedX,speedY;
	float objSpeed = 0.05f;
public:
	Entity_Object(ShapeType type, float xPos, float yPos, float size, float _speedX, float _speedY, sf::Color color);

	void draw(sf::RenderWindow& window);
};

