#include "config.h"
#include "assignmentapp.h"
#include "Triangle.h"
#include "Vector2d.h"
#include <iostream>
#include <time.h>  
#include <stdlib.h>
using namespace std;






Triangle::Triangle(float b, float h)
{
	this->base = b;
	this->height = h;
}

Triangle::Triangle() {
	setBase();
	setHeight();
	setShapeType();
	setCordinate();

	offsetX = setCordinate();
	offsetY = setCordinate();

	v1.addXToArray(cordinate * 1 + offsetX);
	v1.addYToArray(-cordinate * 1 + offsetY);
	v2.addXToArray(-cordinate * 1 + offsetX);
	v2.addYToArray(-cordinate * 1 + offsetY);
	v3.addXToArray(cordinate * 0 + offsetX);
	v3.addYToArray(cordinate * 1 + offsetY);

	Matrix2d mat = mat.rotate2(setCordinate());

	v4 = mat * v1;
	v5 = mat * v2;
	v6 = mat * v3;
	//Vector2d v1(0.3f * base, -0.3 * height);
	//Vector2d v2(-0.3f * base, -0.3 * height);
	//Vector2d v3(0.0f * base, 0.3 * height);
}


Triangle::~Triangle()
{
}
//function that updates position
void Triangle::updatePosition() {

	linesArray[0].x1 = v4.getXFromArray();
	linesArray[0].y1 = v4.getYFromArray();
	linesArray[0].c1.g = 1;
	linesArray[1].x1 = v5.getXFromArray();
	linesArray[1].y1 = v5.getYFromArray();
	linesArray[1].c1.g = 1;
	linesArray[2].x1 = v6.getXFromArray();
	linesArray[2].y1 = v6.getYFromArray();
	linesArray[2].c1.g = 1;
	linesArray[0].x2 = v5.getXFromArray();
	linesArray[0].y2 = v5.getYFromArray();
	linesArray[1].x2 = v6.getXFromArray();
	linesArray[1].y2 = v6.getYFromArray();
	linesArray[2].x2 = v4.getXFromArray();
	linesArray[2].y2 = v4.getYFromArray();

}
//function that renders the square.
void Triangle::render() {

	for (int i = 0; i < 3; i++) {
		Assignment::AssignmentApp::DrawLine(linesArray[i]);
	}
	

}

void Triangle::setBase()
{
	this->base = 1;
}

float Triangle::getBase()
{
	return base;
}

void Triangle::setHeight()
{
	this->height = 1;
}

float Triangle::getHeight()
{
	return height;
}

float Triangle::setCordinate()
{
	float smallNumber = -0.5f;
	float bigNumber = 0.5f;
	float diff = bigNumber - smallNumber;
	this->cordinate = (((float)rand() / RAND_MAX) * diff) + smallNumber;
	return this->cordinate;
}

int Triangle::getShapeType()
{
	return shapeType;
}

void Triangle::setShapeType()
{
	this->shapeType = 2;
}
