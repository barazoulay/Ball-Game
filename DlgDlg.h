// DlgDlg.h : header file
//

#if !defined(AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_)
#define AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgDlg dialog
// added s
#include <vector>
#include "Figure.h"
#include "UNDOREDO.h"
#include "afxwin.h"
using namespace std;
// added e
class CDlgDlg : public CDialog
{
	UNDOREDO undo_redo_objects;
	UNDOREDO remove_revive_objects;
	enum FIGURES{RECTANGLE,ELLIPSE,CIRCLE};
	enum Actions {ADD,REMOVE,REVIVE_OBJECT,UNDO_OBJECT,REDO_OBJECT,CHANGE_COLOR,REMOVE_REVIVAL};
	FIGURES futureFigKIND;
    COLORREF curColor;
	Figure *figtemp;
	CTypedPtrArray< CObArray, Figure*> figs;
	bool isPressed;
	bool isDragging;
	bool isSelectingObject;
	bool inArea;
	bool isPressedMovement;
	bool GameStart;
	CString S_;
	int dir;
	int Score;
	int TopScore;
	int posY1;
	int posY2;
	CPoint startP;
	CPoint endP;
	vector<Actions> actions;
	int set;
	bool MouseOver_;
	bool PressedAndOutSide;
	// Construction
public:
	CDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgDlg)
	enum { IDD = IDD_DLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//BOOL isThin;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedUndobutton();
	afx_msg void OnBnClickedRedoButton();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	void InvalidateArea();
	afx_msg void OnMouseLeave();
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnEnChangeEdit1();
	CButton Save1;
	CButton Load1;
	CButton Move1;
	CButton Down1;
	CButton Remove1;
	CButton Redo1;
	CButton Undo1;
	int BackRound1;
	CButton Game1;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif 
