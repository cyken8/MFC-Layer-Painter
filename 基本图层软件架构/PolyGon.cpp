// PolyGon.cpp: implementation of the CPolyGon class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ly.h"
#include "PolyGon.h"
#include <math.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPolyGon::CPolyGon()
{
	m_LastPoint=(-1,-1);
}

CPolyGon::~CPolyGon()
{

}

void CPolyGon::OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC)
{
	m_arr.Add(point);	
}


void CPolyGon::OnMouseMove(UINT nFlags,CPoint point,CDC* pDC)
{
	int nSize=m_arr.GetSize();
	if(!nSize)
		return;
	CPoint &pt=m_arr[nSize-1];
	pDC->SetROP2(R2_NOT);
	if(pt.x>0)
	{
		pDC->MoveTo(pt);
		pDC->LineTo(point);
		pDC->MoveTo(pt);
		if(m_LastPoint.x!=-1&&m_LastPoint.y!=-1)
			pDC->LineTo(m_LastPoint);
	}
	
	m_LastPoint=point;
}



void CPolyGon::OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC)
{

}

void CPolyGon::OnDraw(CDC* pDC)
{
	int i=0,nSize=m_arr.GetSize();
	if(!nSize)
		return ;
	CBrush br(RGB(255,0,0));
	CBrush* pOldBrush=pDC->SelectObject(&br);
	CPen pen(PS_SOLID,2,m_clText);
	CPen* pOldPen=pDC->SelectObject(&pen);
	pDC->Polygon(m_arr.GetData(),nSize);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CPolyGon::Select(CPoint point)
{
	if(Track(point))
	{
		m_nStatus=STU_SELECT;
	}
	else
		m_nStatus=STU_NORMAL;
}

void CPolyGon::Offset(int x,int y)
{
	int i=0,nSize=m_arr.GetSize();
	while(i<nSize)
	{
		m_arr[i++].Offset(x,y);
	}
}

BOOL CPolyGon::Track(CPoint point)
{
	//并未完善，鼠标只是在经过端点时才改变图标，需要精细的话需要
	//修改为判断鼠标是在在由端点值组成的线段上
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


void CPolyGon::OnLButtonDblClk(UINT nFlags, CPoint point)
{

}

