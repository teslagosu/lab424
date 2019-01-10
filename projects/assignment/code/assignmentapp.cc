//------------------------------------------------------------------------------
// assignmentapp.cc
// (C) 2015-2017 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "assignmentapp.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <cstdlib>
#include "Matrix2d.h"
#include "Vector2d.h"
using namespace std;




Square square;





namespace Assignment
{
	
//------------------------------------------------------------------------------
/**
*/
AssignmentApp::AssignmentApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
AssignmentApp::~AssignmentApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
std::vector<Shape*>AssignmentApp::getShapeList() {
	return shapeList;
}

int AssignmentApp::getIndex(int num)
{
	for (int i = 0; i < shapeList.size(); i++) {
		if (shapeList[i]->getShapeType() == num) {
			return i;
		}
	}
	return -1;
	
}



void AssignmentApp::KeyEvent(int key, int action, int modifier)
{
	
	
	// does something with the key. action == 1 means key has been pressed
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_1) {
			//add a square to the vector
			shapeList.push_back(new Square);
			

			
			for (auto v : shapeList) {
				v->updatePosition();
				
				
				
				
			}
			}
		}
		else if (key == GLFW_KEY_2) {
			//add a triangle to the vector
		
		shapeList.push_back(new Triangle);
		for (auto v : shapeList) {
			
			v->updatePosition();
			

		}
			
			
		}
		else if (key == GLFW_KEY_3) {
		//add circle to the vector
		shapeList.push_back(new Circle);
		for (auto v : shapeList) {
			v->updatePosition();
			
		}
	}

		else if (key == GLFW_KEY_Q) {
			//delete the square from vector
		
		for (auto v : shapeList) {
			 //i = v->getShapeType();
			//cout << i<<endl;
			if (v->getShapeType() == 1) {
				int index = getIndex(1);
				if (index != -1) {
					shapeList.erase(shapeList.begin() + index);
				}
			}
			}
		}
		else if (key == GLFW_KEY_W) {
			//delete the triangle from vector
		for (auto v : shapeList) {
			if (v->getShapeType() == 2) {
				int index = getIndex(2);
				if (index != -1) {
					shapeList.erase(shapeList.begin() + index);
				}
			}
		}
		}
		else if (key == GLFW_KEY_E) {
			//delete the circle from vector
		for (auto v : shapeList) {

			if (v->getShapeType() == 3) {
				int index = getIndex(3);
				if (index != -1) {
					shapeList.erase(shapeList.begin() + index);
				}
			}
		}
		}
		
	
	// action == 0 means it was released
	if (action == GLFW_RELEASE){
	
	}
	
}

void 
AssignmentApp::Setup()
{
	// create your own objects 
	Display::Window *w = this->getWindow();
	w->SetKeyPressFunction([this](int key, int, int action, int mod) {
		this->KeyEvent(key, action, mod);
	}
	);
	
	
	
	

}

//------------------------------------------------------------------------------
/**
*/
void AssignmentApp::Update()
{
	
	for (auto v : shapeList) {
		
		v->update();
		v->render();
		
		
	}
	
	

	
	

	/*
	// demo line drawing code
	LineData line;
	line.x1 = -0.3f;
	line.y1 = -0.3f;
	line.x2 = 0.0f;
	line.y2 = 0.5f;
	line.c1.r = 1.0f;
	AssignmentApp::DrawLine(line);	
	line.x1 = 0.0f;
	line.y1 = 0.5f;
	line.x2 = 0.3f;
	line.y2 = -0.3f;	
	AssignmentApp::DrawLine(line);	
	line.x1 = 0.3f;
	line.y1 = -0.3f;
	line.x2 = -0.3f;
	line.y2 = -0.3f;
	AssignmentApp::DrawLine(line);	
	AssignmentApp::PrintText("triangle", 0.5f, 0.5f);
	*/
}

} // namespace Assignment
