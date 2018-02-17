#pragma once   
#include <cstdlib>
class Figure: public CObject 
{
	DECLARE_SERIAL (Figure)    
public:
	void Serialize (CArchive& ar)
	{
		CObject::Serialize (ar);
		if (ar.IsStoring ())
		{
			ar << x1;
			ar << x2;
			ar << y1;
			ar << y2;
			ar << color;
			ar << set;
		}
		else // Loading, not storing
		{
			ar >> x1;
			ar >> x2;
			ar >> y1;
			ar >> y2;
			ar >> color;
			ar >> set;
		}
	}
	Figure();
	Figure(int xx1,int yy1, int xx2, int yy2)
	{
		x1=xx1;
		x2=xx2;
		y1=yy1;
		y2=yy2;
		color=RGB(255,0,0);
		directX=1;
		directY=1;
		ChangeD=1;
		frame=3;
		Score=0;
	}
	int getX1() const;
	int getX2() const;
	int getY1() const;
	int getY2() const;
	int getFrame() const;
	void setFrame(int F);
	void setX1(int);
	void setX2(int);
	void setY1(int);
	void setY2(int);
	void setColor(COLORREF);
	void setXY(int,int,int,int);
	int getSet() const;
	void setSet(int);
	void Move(int d,int *dir,const CRect &r,int *S)
	{
		if (*dir==0)
		{
			if (x2>=r.BottomRight().x||x1<=0)
				directX*=-1;
			x1+=d*directX;
			x2+=d*directX;
		}
		else
		{
			if (y2>=545||y1<=0)
			{
				*dir=2;
				if (x1>=385 && x2<=450)
					*S=5;
				else
					*S=0;
			}
			y1+=d*directY;
			y2+=d*directY;
		}

	}
	
	COLORREF getColor() ;
	virtual void Draw(CDC *dc)
	{
		
	}
	virtual ~Figure(void);
	
private:
	int x1,y1,x2,y2,set,directX,directY,ChangeD,frame, Score;
	COLORREF color;
};

class RectangleS:public Figure{
	DECLARE_SERIAL (RectangleS)   
public:
	RectangleS();
	RectangleS(int xx1,int yy1, int xx2, int yy2)
		:Figure(xx1,yy1,xx2,yy2)
	{

	}
	void Draw(CDC *dc)
	{
		CPen pen(PS_SOLID,this->getFrame(), RGB(0, 255, 200)); 
		CPen *oldPen = dc->SelectObject(&pen);
		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(this->getColor());
		oldBrush=dc->SelectObject( &myBrush );
		dc->Rectangle(getX1(),getY1(),getX2(),getY2());
		
		dc->SelectObject(oldBrush );
		dc->SelectObject(oldPen);
		
	}
};
class EllipseS:public Figure{
	DECLARE_SERIAL (EllipseS)    
public:
	EllipseS();
	EllipseS(int xx1,int yy1, int xx2, int yy2)
		:Figure(xx1,yy1,xx2,yy2)
	{
	}
	void Draw(CDC *dc)
	{
		CPen pen(PS_SOLID,this->getFrame(), RGB(0, 255, 0)); 
		CPen *oldPen = dc->SelectObject(&pen);
		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(this->getColor());
		oldBrush=dc->SelectObject( &myBrush );
		dc->Ellipse(getX1(),getY1(),getX2(),getY2());
		dc->SelectObject( oldBrush );
		dc->SelectObject(oldPen);
	}
};


class CircleS:public EllipseS
{
	DECLARE_SERIAL (CircleS)

public:
	CircleS();
	CircleS(int xx1,int yy1,int xx2, int yy2):EllipseS(xx1,yy1,xx2,yy2)
	{

	}
	void Draw(CDC *dc)
	{
		int midY = (getY1()+getY2())/2;
		int midX = (getX1()+getX2())/2;
		CPoint p1(midX,midY); // get the center as a point
		int distY = abs(getY1() - midY);
		int distX = abs(getX1() - midX);
		int minDist = min(distX,distY);
		CPen pen(PS_SOLID,this->getFrame(), RGB(200, 255, 0)); 
		CPen *oldPen = dc->SelectObject(&pen);
		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(this->getColor());
		oldBrush=dc->SelectObject( &myBrush );
		dc->Ellipse(p1.x-minDist,p1.y-minDist,p1.x+minDist+1,p1.y+minDist+1);
		dc->SelectObject( oldBrush ); 
		dc->SelectObject(oldPen);
	}
};