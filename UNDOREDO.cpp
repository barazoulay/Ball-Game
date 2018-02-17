#include "stdafx.h"
#include "UNDOREDO.h"

UNDOREDO::UNDOREDO(){};
UNDOREDO::~UNDOREDO(){};
Figure* UNDOREDO::redoPop()
{
	Figure* fig = NULL;
	fig = redoStack.top();
	redoStack.pop();
	undoStack.push(fig);
	return fig;
}

//Figure* UNDOREDO::redoPop()
//{
//	Figure* fig = NULL;
//	fig = redoStack.top();
//	redoStack.pop();
//	return fig;
//}

void UNDOREDO::pushRedo(Figure* fig)
{
	redoStack.push(fig);
}

Figure* UNDOREDO::undoPop(bool pushRedo)
{
	Figure* fig = NULL;
	fig = undoStack.top();
	undoStack.pop();
	if(pushRedo == true)
		redoStack.push(fig);
	return fig;
}

//Figure* UNDOREDO::undoPop()
//{
//	Figure* fig = NULL;
//	fig = undoStack.top();
//	undoStack.pop();
//	return fig;
//}
void UNDOREDO::pushUndo(Figure* fig)
{
	undoStack.push(fig);
}

void UNDOREDO::clearRedo()
{
	Figure* figure = NULL;
	while(!redoStack.empty())
	{
		figure = redoStack.top();
		redoStack.pop();
		if(figure!=NULL)
			delete figure;
	}
}
void UNDOREDO::clearUndo()
{
	Figure* figure = NULL;
	while(!undoStack.empty())
	{
		figure = undoStack.top();
		undoStack.pop();
	}
}

int UNDOREDO::redoSize() const
{
	return redoStack.size();
}

int UNDOREDO::undoSize() const
{
	return undoStack.size();
}
