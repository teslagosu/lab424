#pragma once
#include "Shape.h"
#include"2d/2dapp.h"
class Triangle :
	public Shape
{
private:
	float base;
	float height;
	App2D::BaseApp::LineData linesArray[3];
	Vector2d v1;
	Vector2d v2;
	Vector2d v3;
	Vector2d v4;
	Vector2d v5;
	Vector2d v6;
	Vector2d v7;
	Vector2d v8;
	Vector2d v9;
	Vector2d offsetVector;
	Matrix2d mat;
	float cordinate;
	float random;
	int shapeType;
	float offsetX;
		float offsetY;
public:
	Triangle(float b, float h);
	Triangle();
	~Triangle();
	void updatePosition();
	void render();
	void setBase();
	float getBase();
	void setHeight();
	float getHeight();
	float setCordinate();
	int getShapeType();
	void setShapeType();
	void update();
	
};

