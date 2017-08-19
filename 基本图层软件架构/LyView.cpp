// LyView.cpp : implementation of the CLyView class
//

#include "stdafx.h"
#include "Ly.h"

#include "LyDoc.h"
#include "LyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLyView

IMPLEMENT_DYNCREATE(CLyView, CView)

BEGIN_MESSAGE_MAP(CLyView, CView)
	//{{AFX_MSG_MAP(CLyView)
	ON_COMMAND(ID_DRAW_DRAG, OnDrawDrag)
	ON_UPDATE_COMMAND_UI(ID_DRAW_DRAG, OnUpdateDrawDrag)
	ON_COMMAND(ID_DRAW_ELLIP, OnDrawEllip)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIP, OnUpdateDrawEllip)
	ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, OnUpdateDrawLine)
	ON_COMMAND(ID_DRAW_PEN, OnDrawPen)
	ON_UPDATE_COMMAND_UI(ID_DRAW_PEN, OnUpdateDrawPen)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_COLOR, OnDrawColor)
	ON_COMMAND(ID_DRAW_RECTANGLE, OnDrawRectangle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECTANGLE, OnUpdateDrawRectangle)
	ON_COMMAND(ID_DRAW_ROUNDRECT, OnDrawRoundrect)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ROUNDRECT, OnUpdateDrawRoundrect)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_DRAW_POLYLINE, OnDrawPolyline)
	ON_UPDATE_COMMAND_UI(ID_DRAW_POLYLINE, OnUpdateDrawPolyline)
	ON_COMMAND(ID_DRAW_POLYGON, OnDrawPolygon)
	ON_UPDATE_COMMAND_UI(ID_DRAW_POLYGON, OnUpdateDrawPolygon)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLyView construction/destruction

CLyView::CLyView()
{
	// TODO: add construction code here
	m_nType=ID_DRAW_DRAG;//初始化图层的种类
	m_clText=0;//默认画笔初始颜色，可改进，在打开软件时读取上次配置
	m_endPolyLine=TRUE;
	m_startPolyLine=FALSE;

}

CLyView::~CLyView()
{
}

BOOL CLyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLyView drawing

void CLyView::OnDraw(CDC* pDC)
{
	
	//在视图类中OnDraw函数是WM_PAIT消息的回调函数
	CLyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	//遍历存储所有图层的m_ls，取出里面的图层对象并调用相应类的OnDraw函数绘制相应图形
	int i=0,nSize=m_ls.GetSize();
	CLayer *pLayer=NULL;
	while(i<nSize)
	{
		pLayer=m_ls[i++];
		pLayer->OnDraw(pDC);
	}
/*
	//采用双缓冲技术
	CLyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CDC mdc;
	mdc.CreateCompatibleDC(pDC);
	//遍历存储所有图层的m_ls，取出里面的图层对象并调用相应类的OnDraw函数绘制相应图形
	int i=0,nSize=m_ls.GetSize();
	CLayer *pLayer=NULL;
	while(i<nSize)
	{
		pLayer=m_ls[i++];
		pLayer->OnDraw(&mdc);
	}
	CRect rtClient;
	GetClientRect(&rtClient);
	pDC->BitBlt(0,0,rtClient.Width(),rtClient.Height(),&mdc,0,0,SRCCOPY);
*/	
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CLyView printing

BOOL CLyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLyView diagnostics

#ifdef _DEBUG
void CLyView::AssertValid() const
{
	CView::AssertValid();
}

void CLyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLyDoc* CLyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLyDoc)));
	return (CLyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLyView message handlers

void CLyView::OnDrawDrag() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_DRAG;//选中工具栏按钮的哪个就记录哪个

	m_endPolyLine=FALSE;
}

void CLyView::OnUpdateDrawDrag(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(ID_DRAW_DRAG==m_nType);//设置工具栏按钮下陷，代替if,else两句语句

}

void CLyView::OnDrawEllip() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_ELLIP;
	
	m_endPolyLine=FALSE;
}

void CLyView::OnUpdateDrawEllip(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetCheck(ID_DRAW_ELLIP==m_nType);
		
}

void CLyView::OnDrawLine() 
{
	// TODO: Add your command handler code here
		m_nType=ID_DRAW_LINE;
		
	m_endPolyLine=FALSE;
}

void CLyView::OnUpdateDrawLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetCheck(ID_DRAW_LINE==m_nType);
}

void CLyView::OnDrawPen() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_PEN;
	
	m_endPolyLine=FALSE;
}

void CLyView::OnUpdateDrawPen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetCheck(ID_DRAW_PEN==m_nType);
}


void CLyView::OnDrawRectangle() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_RECTANGLE;
	
	m_endPolyLine=FALSE;
}

void CLyView::OnUpdateDrawRectangle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(ID_DRAW_RECTANGLE==m_nType);
}


void CLyView::OnDrawRoundrect() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_ROUNDRECT;
	
	m_endPolyLine=FALSE;
}

void CLyView::OnUpdateDrawRoundrect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nType==ID_DRAW_ROUNDRECT);
	
}

void CLyView::OnDrawPolyline() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_POLYLINE;
	
	m_startPolyLine=TRUE;
	
}

void CLyView::OnUpdateDrawPolyline(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(ID_DRAW_POLYLINE==m_nType);
}


void CLyView::OnDrawPolygon() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_POLYGON;

	m_endPolyLine=TRUE;
}

void CLyView::OnUpdateDrawPolygon(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(ID_DRAW_POLYGON==m_nType);
}


void CLyView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CLayer* pLayer=NULL;
	CClientDC dc(this);
	if(ID_DRAW_DRAG!=m_nType)
	{
		//根据当前类型创建一个新图层,如果是折线图层，需要特殊处理，因为每次鼠标按下都会新建一个图层，当折线图层单击多次都可能属于同一个折线图层
		if(ID_DRAW_POLYLINE!=m_nType&&ID_DRAW_POLYGON!=m_nType)//既不是拖拉工具又不是折线图层
		{
			m_endPolyLine=TRUE;
			pLayer=CLayer::Create(m_nType);
			pLayer->m_clText=m_clText;//将LyView类中的前景颜色赋值给创建的图形类的前景颜色
			pLayer->OnLButtonDown(nFlags,point,&dc);
			m_ls.Add(pLayer);//	添加新的图层
			return ;
		}
		else
		{
			if(m_endPolyLine)//是折线图层并且在鼠标左键单击后双击结束
			{
				m_endPolyLine=FALSE;
				pLayer=CLayer::Create(m_nType);
				pLayer->m_clText=m_clText;//将LyView类中的前景颜色赋值给创建的图形类的前景颜色
				pLayer->OnLButtonDown(nFlags,point,&dc);
				m_ls.Add(pLayer);//	添加新的图层
				return ;
			}
			else
			{
				int nSize=m_ls.GetSize();
				pLayer=m_ls[nSize-1];
				pLayer->m_clText=m_clText;//将LyView类中的前景颜色赋值给创建的图形类的前景颜色
				pLayer->OnLButtonDown(nFlags,point,&dc);
				return;
			}
		}

	}
	//如果选择拖拉工具，并且鼠标按下
	int i=0;
	while(i<m_ls.GetSize())
	{
		//将点中的图层设为选中状态
		pLayer=(CLayer*)m_ls[i];
		pLayer->Select(point);
		i++;
	}
	Invalidate();
	m_point=point;//如果要拖动，这里先设置拖动的起点

//	CView::OnLButtonDown(nFlags, point);
}

//鼠标在客户区弹起的时候，记录相关信息，包括画图的终点
void CLyView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int nSize=m_ls.GetSize();//获取图层总数
	if(!nSize)//如果没有图层，则返回
		return;
	CLayer* pLayer=NULL;
	CClientDC dc(this);
	if(ID_DRAW_DRAG!=m_nType)
	{
		//完成新图层绘制
		pLayer=m_ls[nSize-1];
		pLayer->OnLButtonUp(nFlags,point,&dc);
		if(STU_DRAWING==pLayer->m_nStatus)
			pLayer->m_nStatus=STU_NORMAL;
	}
	//如果是选择拖放小工具，则实现拖放功能
	else
	{
		//完成图层拖放
		int i=0;
		while(i<nSize)
		{
			pLayer=m_ls[i];
			if(STU_SELECT==pLayer->m_nStatus)//m_nStatus在基类CLayer中定义，在各个派生类的Select()函数中被赋值
				pLayer->Offset(point.x-m_point.x,point.y-m_point.y);//m_point记录上一次鼠标按下的点，在鼠标按下时被赋值
			++i;
		}
	}
	Invalidate();//Invalideate会调用OnPaint()函数，OnPaint()会调用OnDraw函数进行绘画，OnDraw取出所有图层进行重新绘画
//	CView::OnLButtonUp(nFlags, point);
}

/*由于画PolyLine和PolyGon破坏了原本的图层架构，使得在双击鼠标左键后，虽然结束了画折线，但是如果这时候直接鼠标单击其他图层工具
然后鼠标重新移动到客户区，这时候由于还没有单击客户区开始为m_ls加入一个选择的要绘制的图层类型
，所以m_ls[nSize-1]总仍然是上一次的折线图层，这时候鼠标移动到客户区，仍然会在鼠标滑动时显示一条鼠标与
上一次双击点的连线,解决方法是在双击相应函数中为m_ls添加一个空白图层*/
void CLyView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int nSize=m_ls.GetSize();
	if(!nSize)
		return;
	CLayer* pLayer=NULL;
	if(ID_DRAW_DRAG!=m_nType)
	{
		if(ID_DRAW_POLYLINE!=m_nType&&ID_DRAW_POLYGON)
		{
			//新绘制图层鼠标光标移动过程使用临时DC避免画面频繁更新
			CClientDC dc(this);//显示绘图过程
			////在绘画之前，必须已经是选择好了图形类并且已经在鼠标在客户区按下的
			//时候就已经把这个图形类存放在了m_ls里，所有m_ls里的最后一个图形类是当前要绘制的图形
			pLayer=(CLayer*)m_ls[nSize-1];
			pLayer->OnMouseMove(nFlags,point,&dc);
			return;
		}
		else
		{
			if(!m_endPolyLine)
			{
				CClientDC dc(this);
				pLayer=(CLayer*)m_ls[nSize-1];
				pLayer->OnMouseMove(nFlags,point,&dc);
				return;
			}
			else
			{
				return;
			}
		}
	}
	//光标掠过某个图层表面显示为即将开始拖动的状态
	while(nSize--)
	{
		if(m_ls[nSize]->Track(point))
		{
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_SIZEALL));
			break;
		}
	}
	CView::OnMouseMove(nFlags, point);
}

/*颜色工具的相应函数*/
void CLyView::OnDrawColor() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	if(IDCANCEL==dlg.DoModal())
		return;

	CLayer* pLayer=NULL;
	int i=0,nSize=m_ls.GetSize();
	COLORREF cl=dlg.GetColor();
	while(i<nSize)
	{
		pLayer=m_ls[i++];
		if(STU_SELECT==pLayer->m_nStatus)
			pLayer->m_clText=cl;
	}
	m_clText=cl;//缺省颜色,实现在选择某种颜色后，之后的图形也能默认使用这种颜色
	Invalidate();
}



void CLyView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_endPolyLine=TRUE;
	
	//这两句相当于为m_ls[]增加一个空白的图层，什么都不干，只是为了弥补
	//画折线破坏了图层结构所带来的Bug,bug如OnMouseMove函数注释处所讲
	CLayer *pLayer=CLayer::Create(ID_DRAW_POLYLINE);
	m_ls.Add(pLayer);

	CView::OnLButtonDblClk(nFlags, point);
}



