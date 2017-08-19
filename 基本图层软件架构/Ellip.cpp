// Ellip.cpp: implementation of the CEllip class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ly.h"
#include "Ellip.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEllip::CEllip()
{
	m_rect.SetRect(-1,-1,-1,-1);
}


CEllip::~CEllip()
{


}

void CEllip::OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC)
{
	m_rect.left=point.x;
	m_rect.top=point.y;
}


void CEllip::OnMouseMove(UINT nFlags,CPoint point,CDC* pDC)
{
	if(!(nFlags&MK_LBUTTON))//判断鼠标左键是否按下
		return;
	pDC->SetROP2(R2_NOT);
	pDC->SelectStockObject(NULL_BRUSH);
	if(m_rect.right>=0)//把上一次的椭圆用反色的方法擦除掉
		pDC->Ellipse(m_rect);
	m_rect.right=point.x;
	m_rect.bottom=point.y;
	pDC->Ellipse(m_rect);
	
}


void CEllip::OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC)
{
	m_rect.right=point.x;
	m_rect.bottom=point.y;
	m_rect.NormalizeRect();//使不正常的矩形变得正常
}


void CEllip::OnDraw(CDC* pDC)
{
	CPen pen(PS_SOLID,2,m_clText);
	CPen* pOldpen=pDC->SelectObject(&pen);

	pDC->Ellipse(m_rect);
	pDC->SelectObject(pOldpen);

	if(STU_SELECT==m_nStatus)
	{
		pDC->FillSolidRect(m_rect.left-3,m_rect.top-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_rect.right-3,m_rect.top-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_rect.left-3,m_rect.bottom-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_rect.right-3,m_rect.bottom-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
		
	}
}

void CEllip::Select(CPoint point)
{
	if(m_rect.PtInRect(point))
		m_nStatus=STU_SELECT;
	else
		m_nStatus=STU_NORMAL;
}
void CEllip::Offset(int x,int y)
{
	m_rect.OffsetRect(x,y);
}

BOOL CEllip::Track(CPoint point)
{
	return m_rect.PtInRect(point);
}


void CEllip::OnLButtonDblClk(UINT nFlags, CPoint point)
{

}
