#pragma once
#include <SFML/Graphics.hpp>

class GameRectObj
{
private:
	sf::RectangleShape rect;

public:
	GameRectObj
	(
		float xPos,
		float yPos,
		float rWidth,
		float rHeight,
		sf::Color color
	);
	void draw(sf::RenderWindow& window);
};

