#pragma once
#include "Vector2d.h"

#include "Matrix2d.h"




class Shape
{
private:
	int shapeType;
	int colour;
	int red;
	int blue;
	int green;
	//Circle circle;
	
public:
	Shape();
	virtual ~Shape();
	Vector2d position;
	Matrix2d rotation;
	Vector2d velocity;
	void setColour();
	int getColour();
	virtual void updatePosition() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	void setPosition(const Vector2d& newPosition);
	Vector2d getPosition();
	void setRotation(const Matrix2d& newRotation);
	Matrix2d getRotation();
	void setVelocity(const Vector2d& newVelocity);
	Vector2d getVelocity();
	virtual int getShapeType() = 0;
	virtual void setShapeType() = 0;

	void setRed(int r);
	int getRed();
	void setBlue(int b);
	int getBlue();
	void setGreen(int g);
	int getGreen();
	int randomColour();

	//void setCircle(Circle s);
	//Circle getCircle();
	



};

