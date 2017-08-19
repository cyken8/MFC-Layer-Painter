// LyView.h : interface of the CLyView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LYVIEW_H__31FD0EA9_435A_47BD_913D_76A5C41B0389__INCLUDED_)
#define AFX_LYVIEW_H__31FD0EA9_435A_47BD_913D_76A5C41B0389__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Layer.h"

class CLyView : public CView
{
public:
	UINT m_nType;	//要绘制图层的种类
	CArray <CLayer*,CLayer*>m_ls;	//记录所有图层对象的集合
	CPoint m_point;			//拖动一个图层时的起点坐标
	COLORREF m_clText;		//前景色
	COLORREF m_clBack;		//背景色
	BOOL m_endPolyLine;
	BOOL m_startPolyLine;

protected: // create from serialization only
	CLyView();
	DECLARE_DYNCREATE(CLyView)

// Attributes
public:
	CLyDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLyView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLyView)
	afx_msg void OnDrawDrag();
	afx_msg void OnUpdateDrawDrag(CCmdUI* pCmdUI);
	afx_msg void OnDrawEllip();
	afx_msg void OnUpdateDrawEllip(CCmdUI* pCmdUI);
	afx_msg void OnDrawLine();
	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);
	afx_msg void OnDrawPen();
	afx_msg void OnUpdateDrawPen(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDrawColor();
	afx_msg void OnDrawRectangle();
	afx_msg void OnUpdateDrawRectangle(CCmdUI* pCmdUI);
	afx_msg void OnDrawRoundrect();
	afx_msg void OnUpdateDrawRoundrect(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnDrawPolyline();
	afx_msg void OnUpdateDrawPolyline(CCmdUI* pCmdUI);
	afx_msg void OnDrawPolygon();
	afx_msg void OnUpdateDrawPolygon(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LyView.cpp
inline CLyDoc* CLyView::GetDocument()
   { return (CLyDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LYVIEW_H__31FD0EA9_435A_47BD_913D_76A5C41B0389__INCLUDED_)
