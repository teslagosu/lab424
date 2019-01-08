
#include "Shape.h"





Shape::Shape()
{

}


Shape::~Shape()
{
}


void Shape::setPosition(const Vector2d& newPosition) {
	this->position = newPosition;
}

void Shape::setRotation(const Matrix2d& newRotation) {
	this->rotation = newRotation;
}

Vector2d Shape::getPosition() {
	return position;
}

Matrix2d Shape::getRotation() {
	return rotation;
}







