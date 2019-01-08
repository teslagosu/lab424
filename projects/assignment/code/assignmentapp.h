//------------------------------------------------------------------------------
/**
	Application class used for Assignment applications.
	Based on 2D app
	
	(C) 2015-2017 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "core/app.h"
#include "render/window.h"
#include "2d/2dapp.h"
#include "Shape.h"

namespace Assignment
{
class AssignmentApp : public App2D::BaseApp
{
public:
	static AssignmentApp& GetInstance()
	{
		static AssignmentApp instance;
		return instance;
	}

	/// destructor
	~AssignmentApp();
	void KeyEvent(int key, int action, int modifier);
	/// initialize, create shapes etc
	void Setup();

	/// update app, draw lines etc
	void Update();

	/// line drawing function
	static void DrawLine(const LineData & line);

	std::vector<Shape*> getShapeList();
	int getIndex(int num);

private:

	/// constructor hidden because it is a singleton
	AssignmentApp();
	/// also hidden because of the singleton
	AssignmentApp(AssignmentApp const &);
	/// also hidden because of the singleton
	void operator=(AssignmentApp const &);
	std::vector<Shape*> shapeList;

};

//------------------------------------------------------------------------------
/**
*/
inline void 
AssignmentApp::DrawLine( const LineData & line )
{
	AssignmentApp::GetInstance().AddLine(line);
}
} // namespace Assignment