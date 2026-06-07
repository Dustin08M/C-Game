#include <iostream>
#include <cstdlib>

#include <SFML/Graphics.hpp>

//=======================================
#include "ShapeObject.h"
////Outdated use GameRectObj and GameCircleObj
//#include "CreateRect.h"
//#include "CreateCircle.h"

#include "Entity_Object.h"
#include "GameRectObj.h"
#include "GameCircleObj.h"
//=======================================
//For testing c++
#include "CourseTest.h"
#include "Student.h"

int main()
{
    CourseTest c("Comp2300");
    c.loadFromFile("Students.txt");
    c.print();









    //for testing purposes
    bool isChanged = false;

    //Setting up window borders first
    const int wWidth = 800;
	const int wHeight = 600;
    sf::RenderWindow window(sf::VideoMode({ wWidth, wHeight }), "Testing Obj Graphics");

    //Create circle
    //Basic declaration of sphere properties
    sf::CircleShape shape(100.f);
    shape.setPosition({ 400.f,200.f });
    shape.setFillColor(sf::Color::Blue);
    float objSpeed = 0.08f;

    //Create lines for drawing grid
    //Basic declaration of rectangle properties
    sf::RectangleShape line({ 1,200 });
    line.setPosition({ 50,0 });

    //Font
    sf::Font font;
	//Handle font loading failure
    if (!font.openFromFile("Font/courbd.ttf"))
    {
		std::cerr << "Failed to load font!" << std::endl;
		exit(-1);
    }
    //Text
	sf::Text text(font);
    text.setString("Graphic Object Scene");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    text.setPosition({ 5,wHeight - (float)text.getCharacterSize() -5});

    //Sphere Pos Text
	sf::Text sphereText(font);
	sphereText.setCharacterSize(15);
	sphereText.setFillColor(sf::Color::White);
    sphereText.setPosition({ 0,0 });

    //Sphere Name
	sf::Text sphereName(font);
	sphereName.setString("Doyle");
	sphereName.setCharacterSize(15);
	sphereName.setFillColor(sf::Color::White);

	//declaration of rectangle properties using CreateRect class
	//CreateRect rect1(250, 100, 130, 90, sf::Color::Magenta); //outdated
    GameRectObj obj1(250, 130, 50, 95, sf::Color::Green);

	//declaration of circle properties using CreateCircle class
	//CreateCircle circle1(50, 600, 400, sf::Color::Green); //outdated
    GameCircleObj obj2(400, 200, 250, sf::Color::Red);
    Entity_Object obj3(Rectangle, 50, 50, 100, sf::Color::White);
    while (window.isOpen()) // updates every frame
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
                
            else if (const auto* keyPressed = event ->getIf<sf::Event::KeyPressed>())
            {
                std::cout << keyPressed<< std::endl;
            }
        }
        //Move obj
        shape.setPosition({shape.getPosition().x + objSpeed, shape.getPosition().y });
        //Check collision on windows border
        if(shape.getPosition().x >= wWidth - shape.getRadius() * 2 || shape.getPosition().x <= 0)
        {
            objSpeed = -objSpeed;
			isChanged = true;
            while (isChanged)
            {
				int r = rand() % 256;
				int g = rand() % 256;
				int b = rand() % 256;
                shape.setFillColor(sf::Color(r, g, b));
				isChanged = false;
            }
		}

        window.clear();
        obj1.draw(window);
        obj2.draw(window);
		window.draw(text);
		window.draw(sphereText);
        window.draw(shape);
		//rect1.draw(window);
		//circle1.draw(window);
        sphereText.setString("Sphere Pos: " + std::to_string(shape.getPosition().x) + " " + std::to_string(shape.getPosition().y));
        sphereName.setPosition({ shape.getPosition().x + shape.getRadius() - sphereName.getCharacterSize() -5, shape.getPosition().y + shape.getRadius() - sphereName.getCharacterSize() +5});
        window.draw(sphereName);
        window.display();
    }
}