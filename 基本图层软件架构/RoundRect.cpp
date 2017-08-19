// RoundRect.cpp: implementation of the CRoundRect class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ly.h"
#include "RoundRect.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRoundRect::CRoundRect()
{
	m_rtRoundRect.SetRect(-1,-1,-1,-1);
	m_degree=10;
}

CRoundRect::~CRoundRect()
{

}

void CRoundRect::OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC)
{
	m_rtRoundRect.left=point.x;
	m_rtRoundRect.top=point.y;
}


void CRoundRect::OnMouseMove(UINT nFlags,CPoint point,CDC* pDC)
{
	if(!(nFlags&MK_LBUTTON))
		return;
	pDC->SetROP2(R2_NOT);
	pDC->SelectStockObject(NULL_BRUSH);
	if(m_rtRoundRect.right>=0)
		pDC->RoundRect(m_rtRoundRect.left,m_rtRoundRect.top,
		m_rtRoundRect.right,m_rtRoundRect.bottom,m_degree,m_degree);
	m_rtRoundRect.right=point.x;
	m_rtRoundRect.bottom=point.y;
	pDC->RoundRect(m_rtRoundRect.left,m_rtRoundRect.top,
	m_rtRoundRect.right,m_rtRoundRect.bottom,m_degree,m_degree);
}


void CRoundRect::OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC)
{
	m_rtRoundRect.right=point.x;
	m_rtRoundRect.bottom=point.y;
	m_rtRoundRect.NormalizeRect();
}
void CRoundRect::OnDraw(CDC* pDC)
{
	CPen pen(PS_SOLID,2,m_clText);
	CPen* pOldPen=pDC->SelectObject(&pen);
	pDC->RoundRect(m_rtRoundRect.left,m_rtRoundRect.top,
	m_rtRoundRect.right,m_rtRoundRect.bottom,m_degree,m_degree);
	pDC->SelectObject(pOldPen);

	if(STU_SELECT==m_nStatus)
	{
		pDC->FillSolidRect(m_rtRoundRect.left-3,m_rtRoundRect.top-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_rtRoundRect.right-3,m_rtRoundRect.top-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_rtRoundRect.left-3,m_rtRoundRect.bottom-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_rtRoundRect.right-3,m_rtRoundRect.bottom-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
		
	}

}

void CRoundRect::Select(CPoint point)
{
	if(m_rtRoundRect.PtInRect(point))
		m_nStatus=STU_SELECT;
	else
		m_nStatus=STU_NORMAL;
}
void CRoundRect::Offset(int x,int y)
{
	m_rtRoundRect.OffsetRect(x,y);
}

BOOL CRoundRect::Track(CPoint point)
{
	return m_rtRoundRect.PtInRect(point);
}


void CRoundRect::OnLButtonDblClk(UINT nFlags, CPoint point)
{

}
