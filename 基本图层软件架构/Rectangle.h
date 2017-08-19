// Rectangle.h: interface for the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECTANGLE_H__B8DD8B76_5D73_478D_BDF6_319F453A6E4F__INCLUDED_)
#define AFX_RECTANGLE_H__B8DD8B76_5D73_478D_BDF6_319F453A6E4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

class CRectangle : public CLayer  
{
public:
//	CPoint m_LeftTop;
//	CPoint m_RightBottom;
	enum{PointNum=4};
	CRect m_Rectangle;
	CPoint m_point[PointNum];
public:
	CRectangle();
	virtual ~CRectangle();
public:
	virtual void OnLButtonDblClk(UINT nFlags, CPoint point);
	BOOL MouseOnLine(CPoint a,CPoint b,CPoint c);
	virtual void OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnMouseMove(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnDraw(CDC* pDC);

	//图层拖动过程，选择，平移和跟踪
	virtual void Select(CPoint point);//单击某个图层，显示选择状态
	virtual void Offset(int x,int y);//拖动图层
	virtual BOOL Track(CPoint point);//光标掠过图层时改变光标形状



};

#endif // !defined(AFX_RECTANGLE_H__B8DD8B76_5D73_478D_BDF6_319F453A6E4F__INCLUDED_)
