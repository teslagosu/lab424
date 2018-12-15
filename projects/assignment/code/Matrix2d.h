#pragma once
#include "Vector2d.h"
class Matrix2d
{
private:
	float a;
	float b;
	float c;
	float d;
	float matrixArray[2][2];
	float transposeArray[2][2];
	float rotatedArray[2][2];
	
	
public:
	float PI = 3.14159265359;
	Matrix2d();
	Matrix2d(float a, float b, float c, float d);
	Matrix2d(const Matrix2d &m);
	~Matrix2d();
	
	void printEverything();
	Matrix2d operator*(const Matrix2d &v);
	Vector2d operator*(const Vector2d &v);
	Matrix2d& operator=(const Matrix2d &v);
	Vector2d transform(Vector2d& v);
	Matrix2d transpose();
	void rotate(float matrixArray[2][2]);
	Matrix2d rotate2(const float  radians);
	float radian(float angle);
	void printOriginalMatrix();
	void printTranspose();
	void printRotated();
	float roundDec(float f, int precision);
	void setA(float a);
	float getA();
	void setB(float b);
	float getB();
	void setC(float c);
	float getC();
	void setD(float d);
	float getD();
	
	
};

