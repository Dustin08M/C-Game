#include "ObjFile.h"


void ObjFile::AddObj(Entity_Object _entObj)
{
	entObj.push_back(std::move(_entObj));
}

void ObjFile::LoadFile(const std::string filename)
{
	std::fstream fin(filename);
	std::string shapeName;
	ShapeType type;
	float xPos, yPos;
	float size;
	int r, g, b;
	while (fin >> shapeName)
	{
		if (shapeName == "Rectangle" || shapeName == "rectangle")
			type = ShapeType::Rectangle;
		else if (shapeName == "Circle" || shapeName == "circle")
			type = ShapeType::Circle;
		else
			continue;

		fin >> xPos >> yPos >> size >> r >> g >> b;
		entObj.emplace_back(type, xPos, yPos, size, sf::Color(r, g, b));
	}
}
void ObjFile::DrawAll(sf::RenderWindow& window)
{
	for (auto& obj : entObj)
	{
		obj.draw(window);
	}
}