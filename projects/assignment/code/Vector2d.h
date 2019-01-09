#pragma once
#include "pch.h"
class Vector2d
{
private:
	
public:
	Vector2d(float x, float y);
	Vector2d();
	// Copy constructor 
	Vector2d(const Vector2d &v2);
	float vector2dArray[3];
	Vector2d operator+(const Vector2d& v);
	Vector2d operator-(const Vector2d& v);
	Vector2d& operator=(const Vector2d &v);
	bool operator==(const Vector2d &v);
	bool operator!=(const Vector2d &v);
	Vector2d operator*(const Vector2d &v);
	void addXToArray(float x);
	float getXFromArray();
	float getYFromArray();
	void addYToArray(float y);
	float getDotProduct(Vector2d& v1,Vector2d& v2);
	float getLengthOfVector();
	float getNormalizeOfVector(Vector2d& v1);
	void printEverything();
	void printLength(Vector2d& v);

};

