#pragma once
#include "Shape.h"
#include"2d/2dapp.h"

class Square :
	public Shape
{
private:
	float dimension;
	App2D::BaseApp::LineData linesArray[4];
	
public:
	Square(float dimension);
	Square();
	~Square();
	void updatePosition();
	void render();
	float getDimension();
	void setDimension(float d);
};

