// Ly.h : main header file for the LY application
//

#if !defined(AFX_LY_H__1AD0E0E2_455F_49F6_B00C_6418269EEB55__INCLUDED_)
#define AFX_LY_H__1AD0E0E2_455F_49F6_B00C_6418269EEB55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLyApp:
// See Ly.cpp for the implementation of this class
//

class CLyApp : public CWinApp
{
public:
	CLyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLyApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LY_H__1AD0E0E2_455F_49F6_B00C_6418269EEB55__INCLUDED_)
