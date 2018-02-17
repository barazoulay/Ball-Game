// DlgDlg.cpp : implementation file

#include "stdafx.h"
#include "Dlg.h"
#include "DlgDlg.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDlg dialog

CDlgDlg::CDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDlg::IDD, pParent)
	
	, BackRound1(0)
{
	futureFigKIND=RECTANGLE;
	figtemp=NULL;
	isPressed=false;
	GameStart=false;
	isPressedMovement=false;
	S_=_T("");
	TopScore=0;
	set=0;
	curColor=RGB(255,0,0);
	MouseOver_ = false;
	PressedAndOutSide = false;

	//{{AFX_DATA_INIT(CDlgDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, S_);
	DDX_Control(pDX, IDC_BUTTON1, Save1);
	DDX_Control(pDX, IDC_BUTTON2, Load1);
	DDX_Control(pDX, IDC_BUTTON5, Move1);
	DDX_Control(pDX, IDC_BUTTON7, Down1);
	DDX_Control(pDX, IDC_BUTTON4, Remove1);
	DDX_Control(pDX, RedoButton, Redo1);
	DDX_Control(pDX, UndoButton, Undo1);
	DDX_Control(pDX, IDC_BUTTON8, Game1);
}

BEGIN_MESSAGE_MAP(CDlgDlg, CDialog)
	//{{AFX_MSG_MAP(CDlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO1, &CDlgDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDlgDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CDlgDlg::OnBnClickedRadio3)
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_CHECK1, &CDlgDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(UndoButton, &CDlgDlg::OnBnClickedUndobutton)
	ON_BN_CLICKED(RedoButton, &CDlgDlg::OnBnClickedRedoButton)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlgDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CDlgDlg::OnBnClickedButton6)
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEHOVER()
	ON_BN_CLICKED(IDC_BUTTON5, &CDlgDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON7, &CDlgDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON8, &CDlgDlg::OnBnClickedButton9)
	ON_EN_CHANGE(IDC_EDIT1, &CDlgDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDlg message handlers

BOOL CDlgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.
	Save1.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP1)));
	Load1.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP3)));
	Move1.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP7)));
	Down1.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP8)));
	Remove1.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP2)));
	Undo1.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP9)));
	Redo1.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP10)));
	Game1.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP11)));
	//Backround.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP11)));

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	//!!2
	CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO1);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDlgDlg::OnPaint() 
{

	
	char *s;
    CRect rect;
    GetClientRect (&rect);
	CPaintDC dc (this);	
	dc.SetBkMode (TRANSPARENT);


	 CFont font;
    font.CreatePointFont (200, _T ("Arial"));

    
    CFont *oldFont= dc.SelectObject (&font);
    dc.SetBkMode (TRANSPARENT);

    CString string = "Game Box";

    rect.OffsetRect (0, -140);
    dc.SetTextColor (RGB (250, 250, 250));
    dc.DrawText (string, &rect, DT_SINGLELINE |
        DT_CENTER | DT_VCENTER);

    rect.OffsetRect (-8, -8);
    dc.SetTextColor (RGB (255, 0, 0));
    dc.DrawText (string, &rect, DT_SINGLELINE |
        DT_CENTER | DT_VCENTER);

	dc.SelectObject (oldFont);

	Figure *f;
	for(int i=0;i<figs.GetSize();i++)
	{
		f = figs[i];
		figs[i]->Draw(&dc);
	}
	if(isPressed)
	{
		dc.MoveTo(startP.x,startP.y);
		dc.LineTo(startP.x,endP.y);
		dc.LineTo(endP.x,endP.y);
		dc.LineTo(endP.x,startP.y);
		dc.LineTo(startP.x,startP.y);
	}
	
	if (isPressedMovement)
	{
		CRect rect;
		CWnd *pWnd = this->GetDlgItem(IDC_STATIC);
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);

		if(figtemp != NULL)
		{
			figtemp->Move(1,&dir,&rect,&Score);
			InvalidateRect(rect);
			if (dir==2)
			{
				int i=0;
				isPressedMovement=false;
				if (Score!=i)
				{
					UpdateData(true);
					s = S_.GetBuffer(5);
					TopScore+=Score;
					itoa(TopScore, s, 10);
					S_.ReleaseBuffer();
					UpdateData(false);
				}
			}
		}	

		
		
	}
	if (GameStart)
	{
		
		CPen myPen1(PS_SOLID, 3, RGB(255,0,0));
		CPen *oldPen;
		oldPen=dc.SelectObject( &myPen1 ); 
		dc.SetROP2(R2_NOTXORPEN);  
		dc. MoveTo(450,400);
		dc.LineTo(450, 550);
		dc.LineTo(385, 550);
		dc.LineTo(385,400);
		dc.LineTo (450,400);
		dc.SelectObject( oldPen ); 
		dc.SetROP2(R2_COPYPEN); 
	
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDlgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDlgDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// check that the drawing is on the right area
	CRect rect;
	CWnd *pWnd = this->GetDlgItem(IDC_STATIC);
	pWnd->GetWindowRect(&rect);
	ScreenToClient(&rect);
	if(point.y > rect.top + 7 && point.y < rect.bottom -7 && point.x < rect.right -7&& point.x > rect.left +7)
	{
		inArea = true;
	}
	else
	{
		inArea = false;
		return;
	}

	bool insideObject = false;
    endP=startP=point;
	//isPressedMovement=false;
	isPressed=true;
	int x = point.x;
	int y = point.y;
	for(int i=figs.GetSize()-1;i>=0;i--)
	{
		figtemp = figs[i];
		if(x <= max(figtemp->getX1(),figtemp->getX2()) && x >=min(figtemp->getX1(),figtemp->getX2())
			&& y <= max(figtemp->getY1(),figtemp->getY2()) && y >=min(figtemp->getY1(),figtemp->getY2()))
		{
			insideObject = true;
			isSelectingObject = true;
			break;
		}
	}
	if(insideObject == false)
	{
		figtemp = NULL;
		isSelectingObject = false;
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CDlgDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	//TRACE(_T("L Button Up\n"));
	// TODO: Add your message handler code here and/or call default

	if(isPressed && !isSelectingObject && inArea && !PressedAndOutSide)
	{

		
			
		isPressedMovement=false;
		endP=point;
  
		switch(futureFigKIND)
		{
		case RECTANGLE:
			figs.Add(new RectangleS(startP.x, startP.y,startP.x+30,startP.y+30));
			break;
		case ELLIPSE:
			figs.Add(new EllipseS(startP.x, startP.y,startP.x+40,  startP.y+20));
			break;
		case CIRCLE:
			figs.Add(new CircleS(startP.x, startP.y,startP.x+20,  startP.y+20));
			break;
		}

		//CRect r;
		//r.left=min(startP.x,endP.x);
		//r.right=max(startP.x,endP.x)+10;
		//r.top=min(startP.y,endP.y);
		//r.bottom=max(startP.y,endP.y)+10;
		//InvalidateRect(&r);
		InvalidateArea();
	}
	else
	{ 
		Invalidate();
	}
	isPressed=false;
		isPressedMovement=false;
	//isPressedMovement=true;
	CDialog::OnLButtonUp(nFlags, point);
}

void CDlgDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// used to detect if the mouse is outside the window
	if(!MouseOver_)
	{
		//TRACE(_T("Mouse Enter\n"));
		MouseOver_ = TRUE;
		TRACKMOUSEEVENT tme;
        tme.cbSize = sizeof(tme);
        tme.dwFlags = TME_HOVER | TME_LEAVE;
        tme.hwndTrack = m_hWnd;
        tme.dwHoverTime = HOVER_DEFAULT;
        ::TrackMouseEvent(&tme);
	}

    if(isPressed && !isSelectingObject)
	{
		// Check that drawing inside the drawing area
		CRect rect;
		CWnd *pWnd = this->GetDlgItem(IDC_STATIC);
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		if(point.y > rect.top + 7 && point.y < rect.bottom -7 && point.x < rect.right -7&& point.x > rect.left +7)
		{
			inArea = true;
		}
		else
		{
			inArea = false;
			//return;
		}

		isSelectingObject = false;
		figtemp = NULL;
		CClientDC dc(this);
  
	}
	else if(isPressed && isSelectingObject)
	{
		CRect rect;
		CWnd *pWnd = this->GetDlgItem(IDC_STATIC);
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		endP = point;
		int diffxx1,diffxx2,diffyy1,diffyy2;
		diffxx1 = diffxx2 = startP.x - endP.x;
		diffyy1 = diffyy2 = startP.y - endP.y;
		int xx1,xx2,yy1,yy2;
		xx1 = figtemp->getX1() - diffxx1;
		xx2 = figtemp->getX2() - diffxx2;
		yy1 = figtemp->getY1() - diffyy1;
		yy2 = figtemp->getY2() - diffyy2;
		int max = max(xx1,xx2);
		int min = min(xx1,xx2);
		xx1 = min;
		xx2 = max;
		max = max(yy1,yy2);
		min = min(yy1,yy2);
		yy1 = min;
		yy2 = max;
		// checking that the figure doesn't cross the drawing area
		if(yy1 > rect.top + 7 && yy2 < rect.bottom -7 && xx2 < rect.right -7&& xx1 > rect.left +7)
		{
			figtemp->setXY(xx1,yy1,xx2,yy2);
			InvalidateArea();
		}
		startP = endP;
	}
	else
	{
		PressedAndOutSide = false;
	}
	CDialog::OnMouseMove(nFlags, point);
}

void CDlgDlg::OnBnClickedButton1()
{ 
	// Save File Dialog
	TCHAR szFilters[] = _T("Project Files(*.BS)|*.BS|All Files (*.*)|(*.*)||");
	CFileDialog fileDlg(FALSE,_T("BS"),_T("*.BS"),OFN_HIDEREADONLY, szFilters);
	if(fileDlg.DoModal() == IDOK)
	{
	CFile file(fileDlg.GetPathName(), CFile::modeCreate|CFile::modeWrite);
	CArchive ar (&file, CArchive::store);
	figs.Serialize(ar);
	ar.Close();
	file.Close();
	}
}

void CDlgDlg::OnBnClickedButton2()
{
	// Open File Dialog
	TCHAR szFilters[] = _T("Project Files(*.BS)|*.BS|All Files (*.*)|(*.*)||");
	CFileDialog fileDlg(FALSE,_T("BS"),_T("*.BS"),OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);
	if(fileDlg.DoModal() == IDOK)
	{
		CFile file(fileDlg.GetPathName(), CFile::modeRead);
		CArchive ar (&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		// setting the proper set number
		set = -1;
		for(int i=0;i<figs.GetSize();i++)
		{
			if(figs[i]->getSet() > set)
				set = figs[i] -> getSet();
		}
		set++;
		InvalidateArea();
	}
}
void CDlgDlg::OnBnClickedRadio1()
{
    futureFigKIND=RECTANGLE;
	
}

void CDlgDlg::OnBnClickedRadio2()
{
	futureFigKIND=ELLIPSE;
}

void CDlgDlg::OnBnClickedRadio3()
{
	futureFigKIND=CIRCLE;
}

void CDlgDlg::OnRButtonDown(UINT nFlags, CPoint point)
{

	CDialog::OnRButtonDown(nFlags, point);
}

void CDlgDlg::OnBnClickedCheck1()
{
	
	UpdateData(true);
}

void CDlgDlg::OnBnClickedUndobutton()
{
	// if last action was adding an object or on a series of undoing objects
	if(actions.size()==0)
		return;
	if(actions[actions.size()-1] == ADD || actions[actions.size()-1] == REDO_OBJECT)
	{
		if(figs.GetSize() > 0)
		{
			actions.pop_back();
			undo_redo_objects.pushRedo(figs[figs.GetSize()-1]);
			figs.RemoveAt(figs.GetSize()-1);
			actions.push_back(UNDO_OBJECT);
			InvalidateArea();
		}
	}
	else if(actions[actions.size()-1] == UNDO_OBJECT)
	{
		if(figs.GetSize() > 0)
		{
			// check if the figure is from the last set of objects defined, otherwise don't delete it
			if(figs[figs.GetSize()-1]->getSet() == set)
			{
				actions.pop_back();
				undo_redo_objects.pushRedo(figs[figs.GetSize()-1]);
				figs.RemoveAt(figs.GetSize()-1);
				actions.push_back(UNDO_OBJECT);
				InvalidateArea();
			}
		}
	}
	else if(actions[actions.size()-1] == REMOVE || actions[actions.size()-1] == REMOVE_REVIVAL || actions[actions.size()-1] == REVIVE_OBJECT )
	{
		if(undo_redo_objects.undoSize() > 0)
		{
			for(int i = actions.size()-1;i>=0;i--)
			{
				if(actions[i] == REMOVE || actions[i] == REMOVE_REVIVAL)
				{
					actions.erase(actions.end()-(actions.size()-i));
					break;
				}
			}
			figs.Add(undo_redo_objects.undoPop(false));
			actions.push_back(REVIVE_OBJECT);
			InvalidateArea();
		}
	}
}

void CDlgDlg::OnBnClickedRedoButton()
{
	bool revival = false;
	if(actions.size()==0)
		return;
	// if last action was removing an object or on a series of redoing objects
	if(actions[actions.size()-1]==UNDO_OBJECT || actions[actions.size()-1] == REDO_OBJECT)
	{
		if(undo_redo_objects.redoSize() > 0)
		{
			actions.pop_back();
			figs.Add(undo_redo_objects.redoPop());
			actions.push_back(REDO_OBJECT);
			InvalidateArea();
		}
	}

	else if(actions[actions.size()-1]==REVIVE_OBJECT || actions[actions.size()-1] == REMOVE_REVIVAL)
	{
		if(figs.GetSize()>0)
		{
			for(int i = actions.size()-1;i>=0;i--)
			{
				if(actions[i] == REVIVE_OBJECT)
				{
					revival = true;
					actions.erase(actions.end()-(actions.size()-i));
					actions.push_back(REMOVE_REVIVAL);
					break;
				}
			}

			if(revival)
			{
				undo_redo_objects.pushUndo(figs[figs.GetSize()-1]);
				figs.RemoveAt(figs.GetSize()-1);
				InvalidateArea();
			}
		}
	}
}

void CDlgDlg::OnBnClickedButton3()
{
	COLORREF color(RGB(rand() % 500,rand() % 500,rand() % 500));
	if(figtemp != NULL)
	{
		figtemp->setColor(color);
		InvalidateArea();
	}
}

void CDlgDlg::OnBnClickedButton4()
{
	if(figtemp !=NULL)
	{
		for(int i=0;i<figs.GetSize();i++)
		{
			if(figtemp==figs[i])
			{
				undo_redo_objects.clearRedo();
				 //if removing an object after we did a redo then the stacks are no longer relevant
				if(actions.size() !=0)
				{
					if(actions[actions.size()-1] == REDO_OBJECT)
					{	
						undo_redo_objects.clearUndo();
					}
					else if(actions[actions.size()-1] != REMOVE)
					{
						set++;
					}
				}
				undo_redo_objects.pushUndo(figtemp);
				figs.RemoveAt(i);
				figtemp = NULL;
				break;
			}
		}
		// clearing the add actions from the actions vector, they are no longer relevant
		actions.push_back(REMOVE);
		InvalidateArea();
	}
}

void CDlgDlg::OnBnClickedButton6()
{
	CColorDialog dlg; 
	if (dlg.DoModal() == IDOK) 
	{ 
		curColor = dlg.GetColor();
	}
	if(figtemp != NULL)
	{
		figtemp->setColor(curColor);
		InvalidateArea();
	}
}

void CDlgDlg::InvalidateArea()
{
	CRect rect;
	CWnd *pWnd = this->GetDlgItem(IDC_STATIC);
	pWnd->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(rect);
}


void CDlgDlg::OnMouseLeave()
{
	//TRACE(_T("Mouse Leave \n"));
	MouseOver_ = false;
	if(isPressed)
		PressedAndOutSide = true;
	else
		PressedAndOutSide = false;
	CDialog::OnMouseLeave();
}


void CDlgDlg::OnMouseHover(UINT nFlags, CPoint point)
{
	TRACKMOUSEEVENT tme;
	tme.cbSize = sizeof(tme);
    tme.dwFlags = TME_HOVER | TME_LEAVE;
    tme.hwndTrack = m_hWnd;
    tme.dwHoverTime = HOVER_DEFAULT;
    ::TrackMouseEvent(&tme);
	CDialog::OnMouseHover(nFlags, point);
}


void CDlgDlg::OnBnClickedButton7()
{
	dir=0;
	isPressedMovement=true;
	InvalidateArea();

}


void CDlgDlg::OnBnClickedButton8()
{
		dir=1;
	isPressedMovement=true;
	InvalidateArea();
}

void CDlgDlg::OnBnClickedButton9()
{
	Score=0;
	GameStart=true;
	InvalidateArea();

}
void CDlgDlg::OnEnChangeEdit1()
{

}
