#include "config.h"
#include "Square.h"
#include "assignmentapp.h"
#include <iostream>
#include <random>
#include <time.h>  
#include <stdlib.h>
using namespace std;




//constructor that takes a dimension
Square::Square(float dimension)
{
	this->dimension = dimension;
	
}

Square::Square() {

	//test grejer
	
	setDimension(setCordinate());
	Vector2d newVector2d(dimension / 2, dimension / 2);
	//setters
	dimension = 1.0f;
	setPosition(newVector2d);
	setColour();
	setShapeType();
	setCordinate();
	Vector2d vel(0.005, 0.005);
	setVelocity(vel);
	
	
	cout << getVelocity().getXFromArray();
	cout << getVelocity().getYFromArray();
	
	offsetX = setCordinate();
	offsetY = setCordinate();

	Vector2d offsetVector(offsetX, offsetY);
	//punkter för fyrkanten.
	
	
	
	v1.addXToArray(-dimension/4 + offsetX);
	v1.addYToArray(dimension/4 + offsetY);
	v2.addXToArray(dimension/4 + offsetX);
	v2.addYToArray(dimension/4 + offsetY);
	v3.addXToArray(dimension/4 + offsetX);
	v3.addYToArray(-dimension/4 + offsetY);
	v4.addXToArray(-dimension/4 + offsetX);
	v4.addYToArray(-dimension/4 + offsetY);

	
	
	rotation = mat.rotate2((30 * 3.14f) / 180);
	rotation.setPosition(offsetVector);
	v1 = rotation * v1;
	v2 = rotation * v2;
	v3 = rotation * v3;
	v4 = rotation * v4;
	
	rotation.printOriginalMatrix();
	
	
	v5 = v1;
	v6 = v2;
	v7 = v3;
	v8 = v4;

	

	cout << "offsetVectorX: " << offsetVector.getXFromArray() << endl;
	cout << "offsetVectorY: " << offsetVector.getYFromArray() << endl;


	
	
}



//destructor
Square::~Square()
{
}
//function that updates position
void Square::updatePosition() {
	
	linesArray[0].x1 = v5.getXFromArray() + getVelocity().getXFromArray();
	linesArray[0].y1 = v5.getYFromArray() + getVelocity().getYFromArray();
	linesArray[0].c2.b = getBlue();
	linesArray[0].c2.r = getRed();
	linesArray[0].c2.g = getGreen();
	
	linesArray[1].x1 = v6.getXFromArray() + getVelocity().getXFromArray();
	linesArray[1].y1 = v6.getYFromArray() + getVelocity().getYFromArray();
	linesArray[1].c2.b = getBlue();			
	linesArray[1].c2.r = getRed();			
	linesArray[1].c2.g = getGreen();		
											
	linesArray[2].x1 = v7.getXFromArray() + getVelocity().getXFromArray();
	linesArray[2].y1 = v7.getYFromArray() + getVelocity().getYFromArray();
	linesArray[2].c2.b = getBlue();
	linesArray[2].c2.r = getRed();
	linesArray[2].c2.g = getGreen();
	
	linesArray[3].x1 = v8.getXFromArray() + getVelocity().getXFromArray();
	linesArray[3].y1 = v8.getYFromArray() + getVelocity().getYFromArray();
	linesArray[3].c2.b = getBlue();			
	linesArray[3].c2.r = getRed();			
	linesArray[3].c2.g = getGreen();		
											
	linesArray[0].x2 = v6.getXFromArray() + getVelocity().getXFromArray();
	linesArray[0].y2 = v6.getYFromArray() + getVelocity().getYFromArray();
											
											
	linesArray[1].x2 =  v7.getXFromArray() +getVelocity().getXFromArray();
	linesArray[1].y2 = v7.getYFromArray() + getVelocity().getYFromArray();
											
											
	linesArray[2].x2 = v8.getXFromArray() + getVelocity().getXFromArray();
	linesArray[2].y2 = v8.getYFromArray() + getVelocity().getYFromArray();
											
											
	linesArray[3].x2 = v5.getXFromArray() + getVelocity().getXFromArray();
	linesArray[3].y2 = v5.getYFromArray() + getVelocity().getYFromArray();
	
	
	
	


	
	

}
//function that renders the square.
void Square::render() {
	for(int i = 0; i < 4; i++){
		Assignment::AssignmentApp::DrawLine(linesArray[i]);
		
		
	}
	
		
	

}

void Square::update() {
	Vector2d test(0.4, 0.4);
	velocity = velocity +test;
	rotation.setPosition(rotation.getPosition() + getVelocity());
	//velocity = velocity + rotation.getPosition();
	
	
	
	/*if (rotation.getPosition().getXFromArray() > 1) {
		Vector2d n(-1, 0);
		Vector2d v;
		v.addXToArray(getVelocity().getDotProduct(getVelocity(), n) * 2 * n.getXFromArray());
		v.addYToArray(getVelocity().getDotProduct(getVelocity(), n) * 2 * n.getYFromArray());
		velocity = getVelocity() - v;
	}
	else if(rotation.getPosition().getXFromArray() < -1){
		Vector2d n(1, 0);
		Vector2d v;
		v.addXToArray(getVelocity().getDotProduct(getVelocity(), n) * 2 * n.getXFromArray());
		v.addYToArray(getVelocity().getDotProduct(getVelocity(), n) * 2 * n.getYFromArray());
		velocity = getVelocity() - v;
		
	}
	else if (rotation.getPosition().getYFromArray() > 1) {
		Vector2d n(0, -1);
		Vector2d v;
		v.addXToArray(getVelocity().getDotProduct(getVelocity(), n) * 2 * n.getXFromArray());
		v.addYToArray(getVelocity().getDotProduct(getVelocity(), n) * 2 * n.getYFromArray());
		velocity = getVelocity() - v;
	}
	else if (rotation.getPosition().getYFromArray() < -1) {
		Vector2d n(0, 1);
		Vector2d v;
		v.addXToArray(getVelocity().getDotProduct(getVelocity(), n) * 2 * n.getXFromArray());
		v.addYToArray(getVelocity().getDotProduct(velocity, n) * 2 * n.getYFromArray());
		velocity = getVelocity() - v;
		
	}
	*/
	
}

//getter that returns the dimension.
float Square::getDimension() {
	return dimension;
}

void Square::setDimension(float d) {
	this->dimension = d;
}

float Square::setCordinate()
{
	/*
	srand(static_cast <unsigned>(time(0)));
	random = ((float)rand()) / ((float)(RAND_MAX) );
	cout << "random" << random << endl;
	this->cordinate = random;
	*/

	float smallNumber = -0.5f;
	float bigNumber = 0.5f;
	float diff = bigNumber - smallNumber;
	this->cordinate = (((float)rand() / RAND_MAX) * diff) + smallNumber;

	return this->cordinate;
}

int Square::getShapeType()
{
	return shapeType;
}

void Square::setShapeType()
{
	this->shapeType = 1;
}