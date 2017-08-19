// Penc.cpp: implementation of the CPenc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ly.h"
#include "Penc.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPenc::CPenc()
{

}

CPenc::~CPenc()
{

}

void CPenc::OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC)
{

	m_arr.Add(point);
}


void CPenc::OnMouseMove(UINT nFlags,CPoint point,CDC* pDC)
{

	if(!(nFlags&MK_LBUTTON))//鼠标按下去的时候才划线
		return;
	int nSize=m_arr.GetSize();
	if(!nSize)
		return;
	//两点之间的距离大于3以上再添加
	CPoint &pt=m_arr[nSize-1];
	pDC->SetROP2(R2_NOT);	//绘制新线段过程使用反色技术
	if(pt.x>0)
	{
		pDC->MoveTo(pt);
		pDC->LineTo(point);
	}
	int cx=pt.x-point.x;
	int cy=pt.y-point.y;
	if(sqrt(cx*cx+cy*cy)>5)
		m_arr.Add(point);
}


void CPenc::OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC)
{
	m_arr.Add(point);
}

void CPenc::OnDraw(CDC* pDC)
{
	int nSize=m_arr.GetSize();
	if(!nSize)
		return;

	CPen pen(PS_SOLID,2,m_clText);
	CPen* pOldpen=pDC->SelectObject(&pen);

	pDC->Polyline(m_arr.GetData(),nSize);

	pDC->SelectObject(&pen);
	if(	m_nStatus==STU_SELECT)
	{
		CPoint pt=m_arr[0];
		pDC->FillSolidRect(pt.x-3,pt.y-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
		pt=m_arr[nSize-1];
		pDC->FillSolidRect(pt.x-3,pt.y-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
	}
}

void CPenc::Select(CPoint point)
{
	if(Track(point))
	{
		m_nStatus=STU_SELECT;
	}
	else
		m_nStatus=STU_NORMAL;
}

void CPenc::Offset(int x,int y)
{
	int i=0,nSize=m_arr.GetSize();
	while(i<nSize)
	{
		m_arr[i++].Offset(x,y);
	}
}

BOOL CPenc::Track(CPoint point)
{
	int i=0,nSize=m_arr.GetSize();
	while(i<nSize)
	{
		CPoint& pt=m_arr[i];
		int cx=pt.x-point.x;
		int cy=pt.y-point.y;
		if(sqrt(cx*cx+cy*cy)<15)
			return true;
		i++;

	}
	return false;
}


void CPenc::OnLButtonDblClk(UINT nFlags, CPoint point)
{

}
