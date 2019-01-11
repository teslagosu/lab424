#include "pch.h"
#include "Vector2d.h"
#include <math.h>
#include <iostream>
using namespace std;

//Constructor with x and y as argument
Vector2d::Vector2d(float x, float y)
{
	this->vector2dArray[0] = x;
	this->vector2dArray[1] = y;
	this->vector2dArray[2] = 1;
}

// Copy constructor 
Vector2d::Vector2d(const Vector2d &v2) { 
	
	this->vector2dArray[0] = v2.vector2dArray[0];
	this->vector2dArray[1] = v2.vector2dArray[1];
	this->vector2dArray[2] = v2.vector2dArray[2];
}

//Constructor standard
Vector2d::Vector2d() {
	this->vector2dArray[0] = 0;
	this->vector2dArray[1] = 0;
	this->vector2dArray[2] = 1;

}
//prints x and y 
void Vector2d::printEverything() {
	cout << "[X:" << this->vector2dArray[0] << ", Y:" << this->vector2dArray[1] << "]"<< endl;
}
//prints length of x and y
void Vector2d::printLength(Vector2d& v) {
	cout << "Length: " << v.getLengthOfVector() << endl;
}
//plus operator
Vector2d Vector2d::operator+(const Vector2d &v) {
	//cout << "inside +operator" << endl;
	Vector2d vec;
	vec.vector2dArray[0] = this->vector2dArray[0] + v.vector2dArray[0];
	vec.vector2dArray[1] = this->vector2dArray[1] + v.vector2dArray[1];

	return vec;
}
//minus operator
Vector2d Vector2d::operator-(const Vector2d &v) {
	//cout << "inside -operator" << endl;
	Vector2d vec;
	vec.vector2dArray[0] = this->vector2dArray[0] - v.vector2dArray[0];
	vec.vector2dArray[1] = this->vector2dArray[1] - v.vector2dArray[1];

	return vec;
}

//multiply operator
Vector2d Vector2d::operator*(const Vector2d &v) {
	//cout << "inside -operator" << endl;
	Vector2d vec;
	vec.vector2dArray[0] = this->vector2dArray[0] * v.vector2dArray[0];
	vec.vector2dArray[1] = this->vector2dArray[1] * v.vector2dArray[1];
	
	return vec;
}
// = operator
Vector2d& Vector2d::operator=(const Vector2d &v) {
	this->vector2dArray[0] = v.vector2dArray[0];
	this->vector2dArray[1] = v.vector2dArray[1];
	return *this;
}

//== operator
bool Vector2d::operator==(const Vector2d &v) {
	return (vector2dArray[0] == v.vector2dArray[0] && vector2dArray[1] == v.vector2dArray[1]);
}

// != operator
bool Vector2d::operator!=(const Vector2d &v) {
	return !(vector2dArray[0] == v.vector2dArray[0] && vector2dArray[1] == v.vector2dArray[1]);
}

//Dotproduct function
float Vector2d::getDotProduct(Vector2d& v1,Vector2d& v2) {
	//(x1 * x2) + (y1 * y2)
	return ((v1.vector2dArray[0] * v2.vector2dArray[0] + (v1.vector2dArray[1] * v2.vector2dArray[1])));
}

//Length of vector function
float Vector2d::getLengthOfVector() {
	return sqrt(this->vector2dArray[0] * this->vector2dArray[0] + this->vector2dArray[1] * this->vector2dArray[1]);
}

//normalization of vector
float Vector2d::getNormalizeOfVector(Vector2d& v1) {

	return ((v1.vector2dArray[0] / v1.getLengthOfVector())+v1.vector2dArray[1] /v1.getLengthOfVector() + v1.getLengthOfVector() / v1.getLengthOfVector());

}
//getters and setters
void Vector2d::addXToArray(float x) {
	vector2dArray[0] = x;
}

float Vector2d::getXFromArray() {
	return vector2dArray[0];
}
void Vector2d::addYToArray(float y) {
	vector2dArray[1] = y;
}

float Vector2d::getYFromArray() {
	return vector2dArray[1];
}

float Vector2d::distance(Vector2d v1, Vector2d v2){	
	float result = sqrt(pow(v2.getXFromArray() - v1.getXFromArray(), 2) + pow(v2.getYFromArray() - v1.getYFromArray(), 2) * 1.0);
	// Calculating distance 
	return result;
}






