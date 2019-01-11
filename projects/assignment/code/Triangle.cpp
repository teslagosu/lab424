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
	setColour();
	offsetX = setCordinate();
	offsetY = setCordinate();
	Vector2d vel(0.0005, 0.0005);
	setVelocity(vel);
	offsetVector.addXToArray(offsetX);
	offsetVector.addYToArray(offsetY);
	v1.addXToArray(base/6 );
	v1.addYToArray(-height/6 );
	v2.addXToArray(-base/6 );
	v2.addYToArray(-height/6 );
	v3.addXToArray(0 );
	v3.addYToArray(height/6 );

	mat = mat.rotate2((30*3.14f)/180);
	mat.setPosition(offsetVector);

	v4 = mat * v1;
	v5 = mat * v2;
	v6 = mat * v3;
	Vector2d test1(0.1,0.1);
	Vector2d test2(0.3,0.9);
	Vector2d test3;
	Vector2d test4(0.5,0.9);
	test3.getDotProduct(test1, test2);

	
	cout << (test3.distance(test1, test2)) << endl;
	
	//Vector2d v1(0.3f * base, -0.3 * height);
	//Vector2d v2(-0.3f * base, -0.3 * height);
	//Vector2d v3(0.0f * base, 0.3 * height);
}


Triangle::~Triangle()
{
}
//function that updates position
void Triangle::updatePosition() {

	linesArray[0].x1 = v4.getXFromArray() + mat.getPosition().getXFromArray();
	linesArray[0].y1 = v4.getYFromArray() + mat.getPosition().getYFromArray();
	linesArray[0].c1.g = getGreen();		
	linesArray[0].c1.r = getRed();			
	linesArray[0].c1.b = getBlue();			
											
	linesArray[1].x1 = v5.getXFromArray() + mat.getPosition().getXFromArray();;
	linesArray[1].y1 = v5.getYFromArray() + mat.getPosition().getYFromArray();;
	linesArray[1].c1.g = getGreen();		
	linesArray[1].c1.r = getRed();			
	linesArray[1].c1.b = getBlue();			
	linesArray[2].x1 = v6.getXFromArray() + mat.getPosition().getXFromArray();;
	linesArray[2].y1 = v6.getYFromArray() + mat.getPosition().getYFromArray();;
	linesArray[2].c1.g = getGreen();		
	linesArray[2].c1.r = getRed();			
	linesArray[2].c1.b = getBlue();			
	linesArray[0].x2 = v5.getXFromArray() + mat.getPosition().getXFromArray();;
	linesArray[0].y2 = v5.getYFromArray() + mat.getPosition().getYFromArray();;
											
	linesArray[1].x2 = v6.getXFromArray() + mat.getPosition().getXFromArray();;
	linesArray[1].y2 = v6.getYFromArray() + mat.getPosition().getYFromArray();;
											
	linesArray[2].x2 = v4.getXFromArray() + mat.getPosition().getXFromArray();;
	linesArray[2].y2 = v4.getYFromArray() + mat.getPosition().getYFromArray();;
	

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
	float smallNumber = -1.0f;
	float bigNumber = 1.0f;
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

void Triangle::update() {
	Vector2d x(mat.getPosition().getXFromArray() + velocity.getXFromArray(), mat.getPosition().getYFromArray() + velocity.getYFromArray());
	mat.setPosition(x);

	

	if (mat.getPosition().getYFromArray() > 1) {

		this->velocity.addXToArray(velocity.getXFromArray() * 1);
		this->velocity.addYToArray(velocity.getYFromArray() * -1);
	}
	
	if (mat.getPosition().getYFromArray() < -1) {

		this->velocity.addXToArray(velocity.getXFromArray() * 1);
		this->velocity.addYToArray(velocity.getYFromArray() * -1);
	}

	if (mat.getPosition().getXFromArray() > 1) {

		this->velocity.addXToArray(velocity.getXFromArray() * -1);
		this->velocity.addYToArray(velocity.getYFromArray() * -1);
	}

	if (mat.getPosition().getXFromArray() < -1) {

		this->velocity.addXToArray(velocity.getXFromArray() * -1);
		this->velocity.addYToArray(velocity.getYFromArray() * 1);
	}
	

	
}