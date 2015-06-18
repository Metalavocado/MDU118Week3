// Week3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

class Vector2
{
public:
	// Vector2 Constructor
	Vector2(float _x = 0, float _y = 0)
	{
		x = _x;
		y = _y;
		std::cout << "Vector2 contructed" << std::endl;
	};
	// Vector2 Deconstructor
	~Vector2()
	{
		std::cout << "Vector2 decontructed" << std::endl;
	};

	float x, y;

};

class Shape
{
public:

	Shape(std::string _name = "", Vector2 _position = Vector2())
	{
		name = _name;
		position = _position;
		std::cout << "Shape contructed" << std::endl;
	};

	virtual ~Shape()
	{
		std::cout << "Shape decontructed" << std::endl;
	};

	std::string name;

	Vector2 position;

};

class Circle : public Shape
{
public:

	Circle(float _radius)
	{
		std::cout << "Circle contructed" << std::endl;
	};

	virtual ~Circle()
	{
		std::cout << "Circle decontructed" << std::endl;
	};

	float radius;

};

class Box : public Shape
{
public:

	Box(float _length = 0, float _width = 0)
	{
		length = _length;
		width = _width;

		std::cout << "Box contructed" << std::endl;
	};

	virtual ~Box()
	{
		std::cout << "Box decontructed" << std::endl;
	};

	float length, width;

};

int _tmain(int argc, _TCHAR* argv[])
{
	{
		typedef enum LineComponent
		{
			elcShapeType,
			elcShapeName,
			elcXCoordinate,
			elcYCoordinate,

			elcNumLineComponents
		};

		std::string csvLine = "Circle,AwesomeCircle,1.3f,2.5f";
		std::istringstream inputStream(csvLine);

		LineComponent currentComponent = elcShapeType;

		std::string shapeType;
		std::string shapeName;
		float coordX;
		float coordY;

		std::string lineElement;
		while (std::getline(inputStream, lineElement, ','))
		{

			std::cout << lineElement << std::endl;
			currentComponent = (LineComponent)(currentComponent + 1);


			if (currentComponent == elcXCoordinate)
			{
				float lineElementAsFloat = std::atof(lineElement.c_str());
				coordX = lineElementAsFloat;
			}

			if (currentComponent == elcYCoordinate)
			{
				float lineElementAsFloat = std::atof(lineElement.c_str());
				coordY = lineElementAsFloat;
			}

			if (currentComponent == elcShapeType)
			{
				shapeType = lineElement;
			}

			if (currentComponent == elcShapeName)
			{
				shapeName = lineElement;
			}


		};

		std::cout << shapeType << shapeName << coordX << coordX << std::endl;



		std::ostringstream outputStream;
		outputStream << "Circle" << "," << "AwesomeCircle" << "," << 1.3f << "," << -2.5f;
		std::string builtCSVLine = outputStream.str();

		//std::string shapeType;
		//inputStream >> shapeType;
	}

	{

		Box box = Box();

		box.length = 5.0f;
		box.width = 4.0f;
		box.name = "Box1";
		box.position.x = 3.1f;
		box.position.y = 2.8f;

		std::ostringstream boxOutputStream;
		boxOutputStream << "Box" << "," << box.name << "," << box.position.x << "," << box.position.y;
		std::string builtCSVLine = boxOutputStream.str();

		std::cout << builtCSVLine << std::endl;

	};

	return 0;
}

