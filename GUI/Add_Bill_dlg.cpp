#include "GUI.h"
#include "Add_Bill_dlg.h"
#include "afxdialogex.h"


// Add_Bill_dlg dialog

IMPLEMENT_DYNAMIC(Add_Bill_dlg, CDialogEx)

Add_Bill_dlg::Add_Bill_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(ADD_BILL_DLG, pParent)
	, bill_ID_tb(_T(""))
{

}

Add_Bill_dlg::~Add_Bill_dlg()
{
}

void Add_Bill_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT8, bill_ID_tb);
}


BEGIN_MESSAGE_MAP(Add_Bill_dlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL3, &Add_Bill_dlg::OnBnClickedCancel3)
END_MESSAGE_MAP()


// Add_Bill_dlg message handlers


void Add_Bill_dlg::OnBnClickedCancel3()
{
	CDialog::OnOK();
	string s = (CT2CA)bill_ID_tb;
	store->AddBill(Bill(s));
	// TODO: Add your control notification handler code here
}
