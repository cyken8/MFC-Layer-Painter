// PolyGon.h: interface for the CPolyGon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLYGON_H__8953E2DA_1511_4DAB_B05A_8B421756B501__INCLUDED_)
#define AFX_POLYGON_H__8953E2DA_1511_4DAB_B05A_8B421756B501__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

class CPolyGon : public CLayer  
{
public:
	CArray<CPoint,CPoint> m_arr;
	CPoint m_LastPoint;
public:
	CPolyGon();
	virtual ~CPolyGon();
public:
	virtual void OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnMouseMove(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnDraw(CDC* pDC);

	//图层拖动过程，选择，平移和跟踪
	virtual void Select(CPoint point);//单击某个图层，显示选择状态
	virtual void Offset(int x,int y);//拖动图层
	virtual BOOL Track(CPoint point);//光标掠过图层时改变光标形状

	virtual void OnLButtonDblClk(UINT nFlags,CPoint point );

};

#endif // !defined(AFX_POLYGON_H__8953E2DA_1511_4DAB_B05A_8B421756B501__INCLUDED_)
