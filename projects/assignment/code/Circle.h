#pragma once
#include "Shape.h"
#include "2d/2dapp.h"
class Circle :
	public Shape
{
private:
	float radius;
	App2D::BaseApp::LineData linesArray[8];
	Vector2d v1;
	Vector2d v2;
	Vector2d v3;
	Vector2d v4;
	Vector2d v5;
	Vector2d v6;
	Vector2d v7;
	Vector2d v8;
	Vector2d v9;
	float random;
	float cordinate;
	int shapeType;
public:
	Circle(float r);
	Circle();
	~Circle();
	void updatePosition();
	void render();
	void setRadius(float radius);
	float getRadius();
	float setCordinate();
	int getShapeType();
	void setShapeType();
	int getColor();
	void update();
};

