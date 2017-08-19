// Layer.cpp: implementation of the CLayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ly.h"
#include "Layer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include "Line.h"
#include "Ellip.h"
#include "Penc.h"
#include "Rectangle.h"
#include "RoundRect.h"
#include "PolyLine.h"
#include "PolyGon.h"
/*所有由这个基类派生出来的图形类都会被初始化为以下状态*/
CLayer::CLayer()
{
	//默认状态是绘画
	m_nStatus=STU_DRAWING;
	m_clText=0;	//初始化前景色
	m_clBack=RGB(255,255,255);//初始化背景色
}

CLayer::~CLayer()
{

}


CLayer* CLayer::Create(int nType)	//创建图层
{
	switch(nType)
	{
	case ID_DRAW_LINE:
		return new CLine;
	case ID_DRAW_ELLIP:
		return new CEllip;
	case ID_DRAW_PEN:
		return new CPenc;
	case ID_DRAW_RECTANGLE:
		return new CRectangle;
	case ID_DRAW_ROUNDRECT:
		return new CRoundRect;
	case ID_DRAW_POLYLINE:
		return new CPolyLine;
	case ID_DRAW_POLYGON:
		return new CPolyGon;
	}
	return NULL;
}
