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
	
	
	
	//setters
	dimension = 1.0f;
	
	setColour();
	setShapeType();
	setCordinate();
	Vector2d vel(0.0005, 0.0005);
	setVelocity(vel);

	offsetX = setCordinate();
	offsetY = setCordinate();
	Vector2d center(dimension / 2, dimension / 2);
	offsetVector.addXToArray(offsetX);
	offsetVector.addYToArray(offsetY);
	
	
	
	//offsetVector(offsetX, offsetY);
	//punkter för fyrkanten.
	
	
	
	v1.addXToArray(-dimension/6 );
	v1.addYToArray(dimension/6 );
	v2.addXToArray(dimension/6 );
	v2.addYToArray(dimension/6 );
	v3.addXToArray(dimension/6 );
	v3.addYToArray(-dimension/6 );
	v4.addXToArray(-dimension/6 );
	v4.addYToArray(-dimension/6 );

	
	mat = mat.rotate2(45* 3.14 / 180);
	mat.setPosition(offsetVector);
	
	
	v5 = mat * v1;
	v6 = mat * v2;
	v7 = mat * v3;
	v8 = mat * v4;
	
	
	


	

	cout << "position X: " << mat.getPosition().getXFromArray() << endl;
	cout << "position Y: " << mat.getPosition().getYFromArray() << endl;
	cout << "rotation X: " << mat.getPosition().getXFromArray() << endl;
	cout << "rotation Y: " << mat.getPosition().getYFromArray() << endl;
	cout << "velocity X: " << velocity.getXFromArray() << endl;
	cout << "velocity Y: " << velocity.getYFromArray() << endl;
	




}



//destructor
Square::~Square()
{
}
//function that updates position
void Square::updatePosition() {

	linesArray[0].x1 = v5.getXFromArray() + mat.getPosition().getXFromArray();
	linesArray[0].y1 = v5.getYFromArray() + mat.getPosition().getYFromArray();
	linesArray[0].c2.b = getBlue();
	linesArray[0].c2.r = getRed();
	linesArray[0].c2.g = getGreen();

	linesArray[1].x1 = v6.getXFromArray() + mat.getPosition().getXFromArray();
	linesArray[1].y1 = v6.getYFromArray() + mat.getPosition().getYFromArray();
	linesArray[1].c2.b = getBlue();
	linesArray[1].c2.r = getRed();
	linesArray[1].c2.g = getGreen();

	linesArray[2].x1 = v7.getXFromArray() + mat.getPosition().getXFromArray();
	linesArray[2].y1 = v7.getYFromArray() + mat.getPosition().getYFromArray();
	linesArray[2].c2.b = getBlue();
	linesArray[2].c2.r = getRed();
	linesArray[2].c2.g = getGreen();

	linesArray[3].x1 = v8.getXFromArray() + mat.getPosition().getXFromArray();
	linesArray[3].y1 = v8.getYFromArray() + mat.getPosition().getYFromArray();
	linesArray[3].c2.b = getBlue();
	linesArray[3].c2.r = getRed();
	linesArray[3].c2.g = getGreen();

	linesArray[0].x2 = v6.getXFromArray() + mat.getPosition().getXFromArray();
	linesArray[0].y2 = v6.getYFromArray() + mat.getPosition().getYFromArray();


	linesArray[1].x2 = v7.getXFromArray() + mat.getPosition().getXFromArray();
	linesArray[1].y2 = v7.getYFromArray() + mat.getPosition().getYFromArray();


	linesArray[2].x2 = v8.getXFromArray() + mat.getPosition().getXFromArray();
	linesArray[2].y2 = v8.getYFromArray() + mat.getPosition().getYFromArray();


	linesArray[3].x2 = v5.getXFromArray() + mat.getPosition().getXFromArray();
	linesArray[3].y2 = v5.getYFromArray() + mat.getPosition().getYFromArray();









}
//function that renders the square.
void Square::render() {
	for (int i = 0; i < 4; i++) {
		Assignment::AssignmentApp::DrawLine(linesArray[i]);


	}




}

void Square::update() {

	Vector2d test(0, -1);
	Vector2d t(-1, -1);
	Vector2d xPlus(1, 1);
	Vector2d xMinus(0, 1);
	Vector2d newPos(mat.getPosition().getXFromArray() + velocity.getXFromArray(),(mat.getPosition().getYFromArray() + velocity.getYFromArray()));
	mat.setPosition(newPos);

	

	if (mat.getPosition().getYFromArray() > 1 ) {

		this->velocity.addXToArray(velocity.getXFromArray() * 1);
		this->velocity.addYToArray(velocity.getYFromArray() * -1);
	}

	 if(mat.getPosition().getYFromArray() < -1) {
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

	/*

	else if (x.getXFromArray() < -1) {
		cout << "mindre än -1" << endl;
		Vector2d n(1, 0);
		Vector2d v;
		v.addXToArray(velocity.getDotProduct(velocity, n) * 2 * n.getXFromArray());
		v.addYToArray(velocity.getDotProduct(velocity, n) * 2 * n.getYFromArray());
	}

	else if (x.getYFromArray() < -1) {
		cout << "mindre än -1" << endl;
		velocity = velocity + test;
	}

	else if (x.getYFromArray() > 1) {
		cout << "mindre än -1" << endl;
		velocity = velocity + test;
	}
	
	
	
	//velocity = velocity+test;
	//cout << x.getXFromArray() << endl;
	*/
	
	

	
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

	float smallNumber = -0.6f;
	float bigNumber = 0.8f;
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