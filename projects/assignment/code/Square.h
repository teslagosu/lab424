#pragma once
#include "Shape.h"
#include"2d/2dapp.h"

class Square :
	public Shape
{
private:
	float dimension = 0.1;
	App2D::BaseApp::LineData linesArray[4];
	Vector2d v1;
	Vector2d v2;
	Vector2d v3;
	Vector2d v4;
	Vector2d v5;
	Vector2d v6;
	Vector2d v7;
	Vector2d v8;

	Matrix2d matrixSquare;
	Matrix2d mat;
	float cordinate;
	float random;
	float minNum;
	float maxNum;
	int shapeType;
	float offsetX;
	float offsetY;
	
public:
	Square(float dimension);
	Square();
	~Square();
	void updatePosition();
	void render();
	float getDimension();
	void setDimension(float d);
	float setCordinate();
	int getShapeType();
	void setShapeType();
	Vector2d newVector2d;
	
	void update();
	
};

