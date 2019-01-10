
#include "Shape.h"
#include <random>
#include <time.h>  
#include <stdlib.h>





Shape::Shape()
{

}


Shape::~Shape()
{
}

Vector2d Shape::setVelocity(const Vector2d& newVelocity) {
	return this->velocity = newVelocity;
}

Vector2d Shape::getVelocity() {
	return velocity;
}

void Shape::setRed(int r)
{
	this->red = r;
}

int Shape::getRed()
{
	return red;
}

void Shape::setBlue(int b)
{
	this->blue = b;
}

int Shape::getBlue()
{
	return blue;
}

void Shape::setGreen(int g)
{
	this->green = g;
}

int Shape::getGreen()
{
	return green;
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


void Shape::setColour() {
	this->red = randomColour();
	this->blue = randomColour();
	this->green = randomColour();
}

int Shape::getColour() {
	return colour;
}

int Shape::randomColour() {
	int r = (rand() % 2, rand() % 2, rand() % 2);


	return r;
}





