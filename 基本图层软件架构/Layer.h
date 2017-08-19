// Layer.h: interface for the CLayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAYER_H__8F836D74_4F9B_4B3D_A82C_4476A4FEA21E__INCLUDED_)
#define AFX_LAYER_H__8F836D74_4F9B_4B3D_A82C_4476A4FEA21E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum{
	STU_DRAWING,	//绘制状态
	STU_NORMAL,		//普通状态
	STU_SELECT
	};	//图层被选中状态
class CLayer  
{
public:
	int m_nStatus;		//图层状态
	COLORREF m_clText;	//前景色
	COLORREF m_clBack;	//背景色
public:
	CLayer();
	virtual ~CLayer();
public:
	static CLayer* Create(int nType);	//创建图层
	//鼠标及显示事件处理
	virtual void OnLButtonDown(UINT nFlags,CPoint point,CDC* pDC=NULL)=0;
	virtual void OnMouseMove(UINT nFlags,CPoint point,CDC* pDC=NULL)=0;
	virtual void OnLButtonUp(UINT nFlags,CPoint point,CDC* pDC=NULL)=0;
	virtual void OnDraw(CDC* pDC)=0;

	//图层拖动过程，选择，平移和跟踪
	virtual void Select(CPoint point)=0;//单击某个图层，显示选择状态
	virtual void Offset(int x,int y)=0;//拖动图层
	virtual BOOL Track(CPoint point)=0;//光标掠过图层时改变光标形状

	virtual void OnLButtonDblClk(UINT nFlags,CPoint point )=0;

};

#endif // !defined(AFX_LAYER_H__8F836D74_4F9B_4B3D_A82C_4476A4FEA21E__INCLUDED_)
