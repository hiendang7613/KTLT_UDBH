#include "GUI.h"
#include "Login_dlg.h"
#include "afxdialogex.h"
#include "Menu_dlg.h"


// Login_dlg dialog

IMPLEMENT_DYNAMIC(Login_dlg, CDialogEx)

Login_dlg::Login_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(LOGIN_DLG, pParent)
	, user(_T(""))
	, pass(_T(""))
{

}

Login_dlg::~Login_dlg()
{
}

void Login_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, user);
	DDX_Text(pDX, IDC_EDIT2, pass);
}


BEGIN_MESSAGE_MAP(Login_dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Login_dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Login_dlg message handlers



void Login_dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	Employee x(
		"", 
		"", 
		string((CT2CA)user),
		string((CT2CA)pass), 0);

	if (store->IsHaveAccount(x,isAdmin)) {
		Menu_dlg menu_dlg;
		menu_dlg.DoModal();
	}

}
