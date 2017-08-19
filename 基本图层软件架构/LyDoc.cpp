// LyDoc.cpp : implementation of the CLyDoc class
//

#include "stdafx.h"
#include "Ly.h"

#include "LyDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLyDoc

IMPLEMENT_DYNCREATE(CLyDoc, CDocument)

BEGIN_MESSAGE_MAP(CLyDoc, CDocument)
	//{{AFX_MSG_MAP(CLyDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLyDoc construction/destruction

CLyDoc::CLyDoc()
{
	// TODO: add one-time construction code here

}

CLyDoc::~CLyDoc()
{
}

BOOL CLyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLyDoc serialization

void CLyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLyDoc diagnostics

#ifdef _DEBUG
void CLyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLyDoc commands
