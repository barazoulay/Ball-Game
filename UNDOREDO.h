#pragma once 
#include "Figure.h"
#include <iostream>
#include <stack>
using namespace std;
class UNDOREDO
{
public:
	UNDOREDO();
	virtual ~UNDOREDO();
	void pushRedo(Figure*); // undo operation
	Figure* undoPop(bool);
	void pushUndo(Figure*);
	Figure* redoPop(); // redo operation returns the object
	void clearRedo(); // used to clear redo when a new action has been done after doing undo
	void clearUndo();
	int undoSize() const;
	int redoSize() const;

private:
	stack<Figure*> undoStack;
	stack<Figure*> redoStack;
};
