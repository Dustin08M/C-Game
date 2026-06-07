#include "Entity_Object.h"

Entity_Object::Entity_Object(ShapeType type, float xPos, float yPos, float size,float speedX, float speedY, sf::Color color)
{
	if (type == ShapeType::Rectangle)
	{
		auto rect = std::make_unique<sf::RectangleShape>(sf::Vector2f(size, size));
		rect->setPosition(sf::Vector2f(xPos, yPos));
		rect->setFillColor(color);
		shape = std::move(rect);
	}
	else
	{
		auto circle = std::make_unique<sf::CircleShape>(size);

		circle->setPosition(sf::Vector2f(xPos, yPos));
		circle->setFillColor(color);

		shape = std::move(circle);
	}
}

void Entity_Object::draw(sf::RenderWindow & window) { window.draw(*shape); }