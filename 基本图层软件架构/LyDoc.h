// LyDoc.h : interface of the CLyDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LYDOC_H__ED2497FE_0531_46D1_BDD3_94906D4098EE__INCLUDED_)
#define AFX_LYDOC_H__ED2497FE_0531_46D1_BDD3_94906D4098EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLyDoc : public CDocument
{
protected: // create from serialization only
	CLyDoc();
	DECLARE_DYNCREATE(CLyDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLyDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLyDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLyDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LYDOC_H__ED2497FE_0531_46D1_BDD3_94906D4098EE__INCLUDED_)
