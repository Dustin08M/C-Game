#pragma once
#include <SFML/Graphics.hpp>

class GameCircleObj
{
private:
	sf::CircleShape circle;

public:
	GameCircleObj
	(
		float xPos,
		float yPos,
		float radius,
		sf::Color color
	);
	void draw(sf::RenderWindow& window);
};

