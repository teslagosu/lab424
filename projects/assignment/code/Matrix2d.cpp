#include "pch.h"
#include "Matrix2d.h"
#include <iostream>
#include <math.h>
using namespace std;
#define _USE_MATH_DEFINES

//constructors
Matrix2d::Matrix2d()
{
	a = 1;
	b = 0;
	c = 0;
	d = 0;
	e = 1;
	f = 0;
	g = 0;
	h = 0;
	i = 1;
	
	
}
Matrix2d::Matrix2d(float a, float b, float c, float d) {
	
	this->matrixArray[0][0] = a;
	this->matrixArray[0][1] = b;
	this->matrixArray[1][0] = c;
	this->matrixArray[1][1] = d;
}
//copy constructor
Matrix2d::Matrix2d(const Matrix2d &m) {
	matrixArray[0][0] = m.matrixArray[0][0];
	matrixArray[0][1] = m.matrixArray[0][1];
	matrixArray[1][0] = m.matrixArray[1][0];
	matrixArray[1][1] = m.matrixArray[1][1];
}
//destructor
Matrix2d::~Matrix2d()
{
}
//multiply matrix operator
Matrix2d Matrix2d::operator*(const Matrix2d &m) {
	Matrix2d result;
	result.matrixArray[0][0] = matrixArray[0][0] * m.matrixArray[0][0] + matrixArray[1][0] * m.matrixArray[0][1];
	result.matrixArray[0][1] = matrixArray[0][0] * m.matrixArray[1][0] + matrixArray[1][0] * m.matrixArray[1][1];
	result.matrixArray[0][2] = matrixArray[0][0] * m.matrixArray[2][0] + matrixArray[1][0] * m.matrixArray[2][1];

	result.matrixArray[1][0] = matrixArray[0][1] * m.matrixArray[0][0] + matrixArray[1][1] * m.matrixArray[0][1];
	result.matrixArray[1][1] = matrixArray[0][1] * m.matrixArray[1][0] + matrixArray[1][1] * m.matrixArray[1][1];
	result.matrixArray[1][2] = matrixArray[0][1] * m.matrixArray[2][0] + matrixArray[1][1] * m.matrixArray[2][1];

	result.matrixArray[2][0] = matrixArray[0][2] * m.matrixArray[0][0] + matrixArray[1][2] * m.matrixArray[0][1];
	result.matrixArray[2][1] = matrixArray[0][2] * m.matrixArray[0][0] + matrixArray[1][2] * m.matrixArray[1][1];
	result.matrixArray[2][2] = matrixArray[0][2] * m.matrixArray[0][0] + matrixArray[1][2] * m.matrixArray[2][1];
	return result;
}

//multiply operator Vector
Vector2d Matrix2d::operator*(const Vector2d & v)
{
	Vector2d array;
	
	array.vector2dArray[0] = matrixArray[0][0] * v.vector2dArray[0] + matrixArray[0][1] * v.vector2dArray[1];
	array.vector2dArray[1] = matrixArray[0][1] * v.vector2dArray[0] + matrixArray[1][1] * v.vector2dArray[1];
	array.vector2dArray[2] = matrixArray[0][2] * v.vector2dArray[0] + matrixArray[2][1] * v.vector2dArray[1];
	
	return array;
}
// = equal operator
Matrix2d & Matrix2d::operator=(const Matrix2d & v)
{
	this->matrixArray[0][0] = v.matrixArray[0][0];
	this->matrixArray[0][1] = v.matrixArray[0][1];
	this->matrixArray[1][0] = v.matrixArray[1][0];
	this->matrixArray[1][1] = v.matrixArray[1][1];
	return *this;
}

//transform function
Vector2d Matrix2d::transform(Vector2d& v) {
	return (v);

}

//transpose function
Matrix2d Matrix2d::transpose() {
	Matrix2d result;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			result.matrixArray[j][i] = this->matrixArray[i][j];
		}
	}
	return result;

}
//rotate function
void Matrix2d::rotate(float array[2][2]) {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			rotatedArray[i][j] = array[2 - j - 1] [i];
		}
	}
	
}

 Matrix2d Matrix2d:: rotate2(const float radians) {
	
	Matrix2d result;
	result.matrixArray[0][0] =  cos(radians);
	result.matrixArray[0][1] =  sin(radians);
	result.matrixArray[1][0] = -sin(radians);
	result.matrixArray[1][1] = cos(radians);
	
		

	return result;
	
	
}

 Matrix2d Matrix2d:: translationMatrix(Vector2d v) {
	 Matrix2d result;

	 result.matrixArray[0][2] = v.getXFromArray();
	 result.matrixArray[1][2] = v.getYFromArray();

	 return result;

 }

float Matrix2d::radian(float angle) {
	float calculateRadian = (angle * PI / 180);
	return calculateRadian;
}

float Matrix2d::roundDec(float f, int precision) {
	int pow = int(std::pow(10, precision));
	float res;
	res = (roundf((f*pow)) / pow);
	if (res < 0.0) {
		res = 0.0;
	}
	return res;
}

void Matrix2d::printOriginalMatrix() {

	cout << "Matrix2d Original" << endl;
	for (int i = 0; i < 2; ++i) {
		cout << "[ ";
		for (int j = 0; j < 2; ++j) {
			cout << " " << matrixArray[i][j];
			cout << " ";
		}
		cout << " ]" << endl;
	}

}

void Matrix2d::printTranspose() {

	cout << "Matrix Transposed" << endl;
	for (int i = 0; i < 2; ++i) {
		cout << "[ ";
		for (int j = 0; j < 2; ++j) {
			cout << " " << matrixArray[j][i];
			cout << " ";
		}
		cout << " ]" << endl;

	}
}

void Matrix2d::printRotated() {

}


//getters and setters

void Matrix2d::setA(float a)
{
	this->a = a;
}

float Matrix2d::getA()
{
	return a;
}

void Matrix2d::setB(float b)
{
	this->b = b;
}

float Matrix2d::getB()
{
	return b;
}

void Matrix2d::setC(float c)
{
	this->c = c;
}

float Matrix2d::getC()
{
	return c;
}

void Matrix2d::setD(float d)
{
	this->d = d;
}

float Matrix2d::getD()
{
	return d;
}



