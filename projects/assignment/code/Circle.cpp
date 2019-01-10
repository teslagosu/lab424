#include "config.h"
#include "assignmentapp.h"
#include "Circle.h"
#include <time.h>  
#include <stdlib.h>
#include <iostream>
using namespace std;



Circle::Circle(float r)
{
	this->radius = r;
}

Circle::Circle() {
	setRadius(setCordinate());
	setShapeType();
	setCordinate();
	setColour();
	float offsetX = setCordinate();
	float offsetY = setCordinate();
	


	
	v1.addXToArray(0.0 + offsetX);
	v1.addYToArray(radius + offsetY);
	
	v2.addXToArray(0.75*radius + offsetX);
	v2.addYToArray(0.75*radius + offsetY);
	

	v3.addXToArray(radius + offsetX);
	v3.addYToArray(0.0 + offsetY);
	

	v4.addXToArray(0.75*radius + offsetX);
	v4.addYToArray(-0.75*radius + offsetY);
	

	v5.addXToArray(0.0 + offsetX);
	v5.addYToArray(-radius + offsetY);
	
	

	v6.addXToArray(-0.75*radius + offsetX);
	v6.addYToArray(-0.75*radius + offsetY);
	

	v7.addXToArray(-radius + offsetX);
	v7.addYToArray(0.0 + offsetY);
	

	v8.addXToArray(-0.75*radius + offsetX);
	v8.addYToArray(0.75*radius + offsetY);
	

	/*v9.addXToArray(0.0 + offsetX);
	v9.addYToArray(radius + offsetY);
	cout << "v7 X:" << v7.getXFromArray() << endl;
	cout << "v7 Y:" << v7.getYFromArray() << endl;
	*/
	//Vector2d v2(0.2f*radius, 0.2f*radius);
	//Vector2d v3(0.3f*radius, 0.0f*radius);
	//Vector2d v4(0.2f*radius, -0.2f*radius);
	//Vector2d v5(0.0f*radius, -0.3f*radius);
	//Vector2d v6(-0.2f*radius, -0.2f*radius);
	//Vector2d v7(-0.3f*radius, 0.0f*radius);
	//Vector2d v8(-0.2f*radius, 0.2f*radius);
}


Circle::~Circle()
{
}

void Circle::updatePosition() {


	linesArray[0].x1 = v1.getXFromArray();
	linesArray[0].y1 = v1.getYFromArray();
	linesArray[0].c1.r = getRed();
	linesArray[0].c1.b = getBlue();
	linesArray[0].c1.g = getGreen();

	linesArray[1].x1 = v2.getXFromArray();
	linesArray[1].y1 = v2.getYFromArray();
	linesArray[1].c1.r = getRed();
	linesArray[1].c1.b = getBlue();
	linesArray[1].c1.g = getGreen();
	linesArray[2].x1 = v3.getXFromArray();
	linesArray[2].y1 = v3.getYFromArray();
	linesArray[2].c1.r = getRed();
	linesArray[2].c1.b = getBlue();
	linesArray[2].c1.g = getGreen();
	linesArray[3].x1 = v4.getXFromArray();
	linesArray[3].y1 = v4.getYFromArray();
	linesArray[3].c1.r = getRed();
	linesArray[3].c1.b = getBlue();
	linesArray[3].c1.g = getGreen();

	linesArray[4].x1 = v5.getXFromArray();
	linesArray[4].y1 = v5.getYFromArray();
	linesArray[4].c1.r = getRed();
	linesArray[4].c1.b = getBlue();
	linesArray[4].c1.g = getGreen();

	linesArray[5].x1 = v6.getXFromArray();
	linesArray[5].y1 = v6.getYFromArray();
	linesArray[5].c1.r = getRed();
	linesArray[5].c1.b = getBlue();
	linesArray[5].c1.g = getGreen();

	linesArray[6].x1 = v7.getXFromArray();
	linesArray[6].y1 = v7.getYFromArray();
	linesArray[6].c1.r = getRed();
	linesArray[6].c1.b = getBlue();
	linesArray[6].c1.g = getGreen();

	linesArray[7].x1 = v8.getXFromArray();
	linesArray[7].y1 = v8.getYFromArray();
	linesArray[7].c1.r = getRed();
	linesArray[7].c1.b = getBlue();
	linesArray[7].c1.g = getGreen();

	linesArray[0].x2 = v2.getXFromArray();
	linesArray[0].y2 = v2.getYFromArray();
	linesArray[1].x2 = v3.getXFromArray();
	linesArray[1].y2 = v3.getYFromArray();
	linesArray[2].x2 = v4.getXFromArray();
	linesArray[2].y2 = v4.getYFromArray();
	linesArray[3].x2 = v5.getXFromArray();
	linesArray[3].y2 = v5.getYFromArray();
	linesArray[4].x2 = v6.getXFromArray();
	linesArray[4].y2 = v6.getYFromArray();
	linesArray[5].x2 = v7.getXFromArray();
	linesArray[5].y2 = v7.getYFromArray();
	linesArray[6].x2 = v8.getXFromArray();
	linesArray[6].y2 = v8.getYFromArray();
	linesArray[7].x2 = v1.getXFromArray();
	linesArray[7].y2 = v1.getYFromArray();

	

}
//function that renders the square.
void Circle::render() {
	for (int i = 0; i < 8; i++) {
		Assignment::AssignmentApp::DrawLine(linesArray[i]);
	}

}

void Circle::setRadius(float radius)
{
	this->radius = radius;
}

float Circle::getRadius()
{
	return radius;
}
int Circle::getColor() {
	int r = ((double)rand() / (RAND_MAX)) + 1;
	return r;
}

void Circle::update()
{

}


float Circle::setCordinate()
{

	float smallNumber = -0.5f;
	float bigNumber = 0.5f;
	float diff = bigNumber - smallNumber;
	this->cordinate = (((float)rand() / RAND_MAX) * diff) + smallNumber;
	return this->cordinate;
}

int Circle::getShapeType()
{
	return shapeType;
}

void Circle::setShapeType()
{
	this->shapeType = 3;
}
