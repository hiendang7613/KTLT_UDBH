#include "framework.h"
#include "GUI.h"
#include "Login_dlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CGUIApp

BEGIN_MESSAGE_MAP(CGUIApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

// CGUIApp construction

CGUIApp::CGUIApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CGUIApp object

CGUIApp theApp;


// CGUIApp initialization

BOOL CGUIApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	//==============================================DATA====================================
	
	store = new Store;

	Product p("p12", "nuoc lau san", "sunlight", 15);
	//Product p2("p13", "kem danh rang", "ps", 20);
	Product p3("p21", "tv", "sony bravia", 8000);
	Product p4("p23", "tu lanh", "sanyo", 6000);

	store->AddProduct(p);
	//store->AddProduct(p2);
	store->AddProduct(p3);
	store->AddProduct(p4);

	Employee e("e46", "nguyen van a", "a", "a", 0);
	Employee e3("e49", "tran c", "root", "root", 1);
	//Employee e2("e62", "pham thi b", "b", "b", 0);

	store->AddEmployee(e);
	//store->AddEmployee(e2);
	store->AddEmployee(e3);

	Bill b("100");
	Bill b2("101");
	//Bill b3("102");

	store->AddBill(b);
	store->AddBill(b2);
	//store->AddBill(b3);


	//==================================================================================

	Login_dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();


	if (nResponse == IDCANCEL2)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Delete the shell manager created above.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}


void AddData(CListCtrl& ctrl, int row, int col, string s)
{
	LVITEM lv;
	lv.iItem = row;
	lv.iSubItem = col;
	wstring ws(s.begin(), s.end());
	lv.pszText = (LPWSTR)ws.c_str();
	lv.mask = LVIF_TEXT;
	if (col == 0)
		ctrl.InsertItem(&lv);
	else
		ctrl.SetItem(&lv);
}