#include "config.h"
#include "Square.h"
#include "assignmentapp.h"





//constructor that takes a dimension
Square::Square(float dimension)
{
	this->dimension = dimension;
	
}

Square::Square() {

}

//destructor
Square::~Square()
{
}
//function that updates position
void Square::updatePosition() {


	position.addXToArray(5*dimension);
	position.addYToArray(-5 * dimension);

	Vector2d v1(0.5f * dimension, -0.5f * dimension);
	Vector2d v2(0.5f * dimension, 0.5f * dimension);
	Vector2d v3(-0.5f * dimension, 0.5f * dimension);
	Vector2d v4(-0.5f * dimension, -0.5f * dimension);
	
	linesArray[0].x1 = v1.getXFromArray();
	linesArray[0].y1 = v1.getYFromArray();
	linesArray[0].c1.b = 1.0f;
	linesArray[1].x1 = v2.getXFromArray();
	linesArray[1].y1 = v2.getYFromArray();
	linesArray[1].c1.b = 1.0f;
	linesArray[2].x1 = v3.getXFromArray();
	linesArray[2].y1 = v3.getYFromArray();
	linesArray[2].c1.b = 1.0f;
	linesArray[3].x1 = v4.getXFromArray();
	linesArray[3].y1 = v4.getYFromArray();
	linesArray[3].c1.b = 1.0f;
	linesArray[0].x2 = v2.getXFromArray();
	linesArray[0].y2 = v2.getYFromArray();
	linesArray[0].c1.b = 1.0f;
	linesArray[1].x2 = v3.getXFromArray();
	linesArray[1].y2 = v3.getYFromArray();
	linesArray[1].c1.b = 1.0f;
	linesArray[2].x2 = v4.getXFromArray();
	linesArray[2].y2 = v4.getYFromArray();
	linesArray[2].c1.b = 1.0f;
	linesArray[3].x2 = v1.getXFromArray();
	linesArray[3].y2 = v1.getYFromArray();
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