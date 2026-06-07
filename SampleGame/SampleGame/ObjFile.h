#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Entity_Object.h"
class ObjFile
{
	std::vector<Entity_Object> entObj;

public:
	ObjFile() {}

	void AddObj(Entity_Object ent);
	void LoadFile(const std::string filename);
	void DrawAll(sf::RenderWindow& window);
};

