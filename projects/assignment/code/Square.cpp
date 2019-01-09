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
	
	setShapeType();
	setCordinate();
	
	offsetX = setCordinate();
	offsetY = setCordinate();
	//punkter för fyrkanten.
	
	v1.addXToArray(-dimension/4 + offsetX);
	v1.addYToArray(dimension/4 + offsetY);
	v2.addXToArray(dimension/4 + offsetX);
	v2.addYToArray(dimension/4 + offsetY);
	v3.addXToArray(dimension/4 + offsetX);
	v3.addYToArray(-dimension/4 + offsetY);
	v4.addXToArray(-dimension/4 + offsetX);
	v4.addYToArray(-dimension/4 + offsetY);

	Matrix2d mat;
	mat = mat.rotate2(setCordinate());
	v5 = mat * v1;
	v6 = mat * v2;
	v7 = mat * v3;
	v8 = mat * v4;
	
	cout << newVector2d.getXFromArray() + v5.getXFromArray() << endl;
	cout << newVector2d.getYFromArray() + v5.getYFromArray()<< endl;
	
	
}



//destructor
Square::~Square()
{
}
//function that updates position
void Square::updatePosition() {
	
	
	
	
	
	linesArray[0].x1 = v5.getXFromArray() ;
	linesArray[0].y1 = v5.getYFromArray();
	linesArray[0].c1.b = 1.0f;
	
	linesArray[1].x1 = v6.getXFromArray();
	linesArray[1].y1 = v6.getYFromArray() ;
	linesArray[1].c1.b = 1.0f;
	
	linesArray[2].x1 = v7.getXFromArray();
	linesArray[2].y1 = v7.getYFromArray() ;
	linesArray[2].c1.b = 1.0f;
	
	linesArray[3].x1 = v8.getXFromArray();
	linesArray[3].y1 = v8.getYFromArray();
	linesArray[3].c1.b = 1.0f;
	
	linesArray[0].x2 = v6.getXFromArray();
	linesArray[0].y2 = v6.getYFromArray();
	linesArray[0].c1.b = 1.0f;
	
	linesArray[1].x2 =  v7.getXFromArray() ;
	linesArray[1].y2 = v7.getYFromArray() ;
	linesArray[1].c1.b = 1.0f;
	
	linesArray[2].x2 = v8.getXFromArray() ;
	linesArray[2].y2 = v8.getYFromArray();
	linesArray[2].c1.b = 1.0f;
	
	linesArray[3].x2 = v5.getXFromArray();
	linesArray[3].y2 = v5.getYFromArray();
	linesArray[3].c1.b = 1.0f;

	



	
	

}
//function that renders the square.
void Square::render() {
	for(int i = 0; i < 4; i++){
		Assignment::AssignmentApp::DrawLine(linesArray[i]);
		
		
	}
	
		
	

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
