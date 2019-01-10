//------------------------------------------------------------------------------
// main.cc
// (C) 2015-2017 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "assignmentapp.h"
#include <iostream>
using namespace std;

int
main(int argc, const char** argv)
{
	float smallNumber = -1.0f;
	float bigNumber = 1.0f;
	float diff = bigNumber - smallNumber;
	for (int i = 0; i <= 10; i++) {
		cout << "test:"<< (((float)rand() / RAND_MAX) * diff) + smallNumber << endl;
		}
	

	Assignment::AssignmentApp & app = Assignment::AssignmentApp::GetInstance();
	if (app.Open())
	{
		app.Run();
		app.Close();
	}
	app.Exit();
	
}