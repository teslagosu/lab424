//------------------------------------------------------------------------------
// assignmentapp.cc
// (C) 2015-2017 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "assignmentapp.h"
#include "Square.h"



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
void 
AssignmentApp::Setup()
{
	// create your own objects 
	square.setDimension(5);
	square.updatePosition();

}

//------------------------------------------------------------------------------
/**
*/
void
AssignmentApp::Update()
{
	
		square.render();
	
	
	

	
	// demo line drawing code
	/*LineData line;
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
