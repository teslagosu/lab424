#pragma once
#include "Vector2d.h"
#include "Matrix2d.h"



class Shape
{
private:
	int shapeType;
public:
	Shape();
	virtual ~Shape();
	Vector2d position;
	Matrix2d rotation;
	virtual void updatePosition() = 0;
	virtual void render() = 0;
	void setPosition(const Vector2d& newPosition);
	Vector2d getPosition();
	void setRotation(const Matrix2d& newRotation);
	Matrix2d getRotation();
	virtual int getShapeType() = 0;
	virtual void setShapeType() = 0;
	
	



};

