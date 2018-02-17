#include "stdafx.h"
#include "Figure.h"
IMPLEMENT_SERIAL (Figure, CObject, 1)
IMPLEMENT_SERIAL (RectangleS, CObject, 1)
IMPLEMENT_SERIAL (EllipseS, CObject, 1)
IMPLEMENT_SERIAL (CircleS, CObject, 1)
Figure::Figure(void)
{
}

Figure::~Figure(void)
{
}
int Figure::getSet() const
{
	return this->set;
}
void Figure::setSet(int set)
{
	this->set = set;
}
int Figure::getX1() const
{
	return this->x1;
}
int Figure::getX2() const
{
	return this->x2;
}
int Figure::getY1() const
{
	return this->y1;
}
int Figure::getY2() const
{
	return this->y2;
}
int Figure:: getFrame()const
{
	return this->frame;
}

void Figure::setFrame (int F)
{
	this->frame=F;
}




void Figure::setX1(int xx1)
{
	this->x1 = xx1;
}
void Figure::setX2(int xx2)
{
	this->x2 = xx2;
}
void Figure::setY1(int yy1)
{
	this->y1 = yy1;
}
void Figure::setY2(int yy2)
{
	this->y2 = yy2;
}

void Figure::setColor(COLORREF color)
{

	this->color = color;
}


void Figure::setXY(int xx1,int yy1,int xx2,int yy2)
{
	setX1(xx1);
	setY1(yy1);
	setX2(xx2);
	setY2(yy2);
}

COLORREF Figure::getColor() 
{
	
	//color=RGB(rand() % 500,rand() % 500,rand() % 500);

	return color;
}
RectangleS::RectangleS(){}
EllipseS::EllipseS(){}
CircleS::CircleS(){}

