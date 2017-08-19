// Rectangle.cpp: implementation of the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ly.h"
#include "Rectangle.h"
#include <math.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRectangle::CRectangle()
{
	m_Rectangle.SetRect(-1,-1,-1,-1);

}

CRectangle::~CRectangle()
{

}

void CRectangle::OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC)
{
	m_Rectangle.left=point.x;
	m_Rectangle.top=point.y;
}


void CRectangle::OnMouseMove(UINT nFlags,CPoint point,CDC* pDC)
{
	if(!(nFlags&MK_LBUTTON))
		return;
	pDC->SetROP2(R2_NOT);
	pDC->SelectStockObject(NULL_BRUSH);
	if(m_Rectangle.right>=0)//把上一次的椭圆用反色的方法擦除掉
		pDC->Rectangle(m_Rectangle);
	m_Rectangle.right = point.x;
	m_Rectangle.bottom = point.y;
		pDC->Rectangle(m_Rectangle);
}


void CRectangle::OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC)
{
	m_Rectangle.right = point.x;
	m_Rectangle.bottom = point.y;
	m_Rectangle.NormalizeRect();//使不正常的矩形变得正常	
}

void CRectangle::OnDraw(CDC* pDC)
{
	CPen pen(PS_SOLID,2,m_clText);
	CPen* pOldPen=pDC->SelectObject(&pen);
	pDC->Rectangle(m_Rectangle);
	pDC->SelectObject(pOldPen);

	if(STU_SELECT==m_nStatus)
	{

		pDC->FillSolidRect(m_Rectangle.left-3,m_Rectangle.top-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_Rectangle.right-3,m_Rectangle.top-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_Rectangle.left-3,m_Rectangle.bottom-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_Rectangle.right-3,m_Rectangle.bottom-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
	}
}

void CRectangle::Select(CPoint point)
{
	if(Track(point))
	{
		m_nStatus=STU_SELECT;
	}
	else
		m_nStatus=STU_NORMAL;
}

void CRectangle::Offset(int x,int y)
{
	m_Rectangle.OffsetRect(x,y);
}

BOOL CRectangle::Track(CPoint point)
{
/*
	CPoint p[4];
	p[0]=m_Rectangle.TopLeft();
	p[1]=m_Rectangle.BottomRight();
	p[2]=(m_Rectangle.left,m_Rectangle.bottom);
	p[3]=(m_Rectangle.right,m_Rectangle.top);

	if(MouseOnLine(point,p[0],p[2])   ||
		MouseOnLine(point,p[0],p[3]) ||
		MouseOnLine(point,p[1],p[2]) ||
		MouseOnLine(point,p[1],p[3]))
	{
		return true;
	}
	
	return false;*/
	return m_Rectangle.PtInRect(point);
}


BOOL CRectangle::MouseOnLine(CPoint a, CPoint b, CPoint c)
{
double lac = sqrt((a.x - c.x)*(a.x - c.x) + (a.y - c.y)*(a.y - c.y));
double lbc = sqrt((b.x - c.x)*(b.x - c.x) + (b.y - c.y)*(b.y - c.y));
double lab = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
return (lac + lbc < lab +10 ) ? TRUE : FALSE;
}

void CRectangle::OnLButtonDblClk(UINT nFlags, CPoint point)
{

}
