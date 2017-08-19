// Penc.h: interface for the CPenc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PENC_H__B8EA473E_3489_4486_BE05_D0D575D5AFBD__INCLUDED_)
#define AFX_PENC_H__B8EA473E_3489_4486_BE05_D0D575D5AFBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

class CPenc : public CLayer  
{
public:
	CArray<CPoint,CPoint> m_arr;
public:
	CPenc();
	virtual ~CPenc();
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

#endif // !defined(AFX_PENC_H__B8EA473E_3489_4486_BE05_D0D575D5AFBD__INCLUDED_)
