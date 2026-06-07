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
#include "ObjFile.h"
#include "Vec2.h"
//=======================================
//For testing c++
#include "CourseTest.h"
#include "Student.h"

int main()
{

    Vec2 v1(5, 13);
    Vec2 v2(9, 16);
    Vec2 v3(v1 + v2);
    //std::cout << v3.x << " " << v3.y << std::endl;
    float dist = v1.dist(v2);
    std::cout << "distance is " << dist << std::endl;
    //Setting up window borders first
    const int wWidth = 800;
	const int wHeight = 600;
    sf::RenderWindow window(sf::VideoMode({ wWidth, wHeight }), "Testing Obj Graphics");

    ObjFile file;
    file.LoadFile("ObjectConfig.txt");

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


	//declaration of rectangle properties using CreateRect class
	//CreateRect rect1(250, 100, 130, 90, sf::Color::Magenta); //outdated
    GameRectObj obj1(250, 130, 50, 95, sf::Color::Green);

	//declaration of circle properties using CreateCircle class
	//CreateCircle circle1(50, 600, 400, sf::Color::Green); //outdated
    GameCircleObj obj2(400, 200, 250, sf::Color::Red);
    while (window.isOpen()) // updates every frame
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                exit(EXIT_SUCCESS);
                //window.close();
                
            else if (const auto* keyPressed = event ->getIf<sf::Event::KeyPressed>())
            {
                std::cout << keyPressed<< std::endl;
            }
        }

        window.clear();
        file.DrawAll(window);
        obj1.draw(window);
        obj2.draw(window);
        window.display();
    }
}