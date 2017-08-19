// RoundRect.h: interface for the CRoundRect class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROUNDRECT_H__CAF3BC1C_5F67_452C_88CA_EF65964F8C27__INCLUDED_)
#define AFX_ROUNDRECT_H__CAF3BC1C_5F67_452C_88CA_EF65964F8C27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

class CRoundRect : public CLayer  
{
public:
	int m_degree;//圆角的弯曲度
	CRect m_rtRoundRect;
public:
	CRoundRect();
	virtual ~CRoundRect();
public:
	virtual void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual void OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnMouseMove(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC=NULL);
	virtual void OnDraw(CDC* pDC);

	//图层拖动过程，选择，平移和跟踪
	virtual void Select(CPoint point);//单击某个图层，显示选择状态
	virtual void Offset(int x,int y);//拖动图层
	virtual BOOL Track(CPoint point);//光标掠过图层时改变光标形状


};

#endif // !defined(AFX_ROUNDRECT_H__CAF3BC1C_5F67_452C_88CA_EF65964F8C27__INCLUDED_)
