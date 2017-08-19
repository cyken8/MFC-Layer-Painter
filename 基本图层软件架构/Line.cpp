// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ly.h"
#include "Line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine()
{
	//在构造函数中初始化成员变量
	m_ptn=m_pts=CPoint(-1,-1);
}

CLine::~CLine()
{

}

void CLine::OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC)
{
	m_pts=point;
}


void CLine::OnMouseMove(UINT nFlags,CPoint point,CDC* pDC)
{
	if(!(nFlags&MK_LBUTTON))
		return;
	pDC->SetROP2(R2_NOT);	//绘制新线段过程使用反色技术
	if(m_ptn.x>=0)
	{
		//两次反色，对上次移动留下的反色线复原
		pDC->MoveTo(m_pts);
		pDC->LineTo(m_ptn);
	}
	pDC->MoveTo(m_pts);
	pDC->LineTo(point);
	m_ptn=point;
}


void CLine::OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC)
{
	//鼠标左键释放是赋值线段终点
	m_ptn=point;
}
void CLine::OnDraw(CDC* pDC)
{
	//在WM_PAINT消息回调时绘制一个从起点到终点的线段
	CPen pen(PS_SOLID,2,m_clText);
	CPen* pOldpen=pDC->SelectObject(&pen);

	pDC->MoveTo(m_pts);
	pDC->LineTo(m_ptn);

	pDC->SelectObject(&pOldpen);
	if(m_nStatus==STU_SELECT)//如果图层被选中的话，显示被选中时的设置样式
	{
		//当选段处于选择状态，线段两个端点显示
		pDC->FillSolidRect(m_pts.x-3,m_pts.y-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_ptn.x-3,m_ptn.y-3,6,6,
			::GetSysColor(COLOR_HIGHLIGHT));
	}
}

void CLine::Select(CPoint point)
{
	//根据鼠标单击的位置，判断单个线段是否被选中
	if(Track(point))
	{
		m_nStatus=STU_SELECT;
	}
	else
		m_nStatus=STU_NORMAL;
}
void CLine::Offset(int x,int y)
{
	//将单个线段位置平移
	m_pts.Offset(x,y);
	m_ptn.Offset(x,y);
}

BOOL CLine::Track(CPoint point)
{
	//未完善，只能检测到光标是否在直线的矩形内，而不能判断
	//光标是否在直线上
	CRect rect(m_pts,m_ptn);
	rect.NormalizeRect();
	return rect.PtInRect(point);
}

void CLine::OnLButtonDblClk(UINT nFlags, CPoint point)
{

}
