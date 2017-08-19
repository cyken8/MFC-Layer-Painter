// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__3783A3FA_9AC6_4B32_B4C8_7A68FA108342__INCLUDED_)
#define AFX_LINE_H__3783A3FA_9AC6_4B32_B4C8_7A68FA108342__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

class CLine : public CLayer  
{
public:
	CPoint m_pts,m_ptn;	//记录线段的起点和终点
	CPoint m_last;		//用于记录绘制过程
public:
	CLine();
	virtual ~CLine();
public:
	virtual void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual void OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnMouseMove(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnDraw(CDC* pDC);

	//图层拖动过程，选择，平移和跟踪
	virtual void Select(CPoint point);
	virtual void Offset(int x,int y);
	virtual BOOL Track(CPoint point);


};

#endif // !defined(AFX_LINE_H__3783A3FA_9AC6_4B32_B4C8_7A68FA108342__INCLUDED_)
