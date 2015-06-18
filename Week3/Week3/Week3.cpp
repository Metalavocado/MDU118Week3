// Week3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


class Vector2
{
public:
	// Vector2 Constructor
	Vector2(float _x = 0, float _y = 0)
	{
		x = _x;
		y = _y;
		std::cout << "Vector2 contructed" << std::endl;
	}
	// Vector2 Deconstructor
	~Vector2()
	{
		std::cout << "Vector2 decontructed" << std::endl;
	}

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
	}

	virtual ~Shape()
	{
		std::cout << "Shape decontructed" << std::endl;
	}

	std::string name;

	Vector2 position;

};

class Circle : public Shape
{
public:

	Circle(float _radius)
	{
		std::cout << "Circle contructed" << std::endl;
	}

	virtual ~Circle()
	{
		std::cout << "Circle decontructed" << std::endl;
	}

	float radius;

};

class Box : public Shape
{
public:

	Box(float _x, float _y)
	{
		std::cout << "Box contructed" << std::endl;
	}

	virtual ~Box()
	{
		std::cout << "Box decontructed" << std::endl;
	}

	float x, y;

};




int _tmain(int argc, _TCHAR* argv[])
{
	{
		Shape shape;
		shape.name = "shape";
		shape.position.x = 5;
		shape.position.y = 3.1;
		std::cout << shape.name << ", " << shape.position.x << ", " << shape.position.y << std::endl;
	}

	return 0;
}

