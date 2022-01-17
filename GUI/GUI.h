#pragma once
#include "Store.h"
#include "framework.h"

#include "resource.h"		// main symbolsz


// CGUIApp:
// See GUI.cpp for the implementation of this class
//

extern Store* store;
extern bool isAdmin;


class CGUIApp : public CWinApp
{
public:
	CGUIApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CGUIApp theApp;
void AddData(CListCtrl& ctrl, int row, int col, string s);
