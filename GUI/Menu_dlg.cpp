#include "GUI.h"
#include "afxdialogex.h"

#include "Menu_dlg.h"
#include "Employee_dlg.h"
#include "Product_dlg.h"
#include "Bill_dlg.h"


// Menu_dlg dialog



IMPLEMENT_DYNAMIC(Menu_dlg, CDialogEx)

Menu_dlg::Menu_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(MENU_DLG, pParent)
{

}

Menu_dlg::~Menu_dlg()
{

}

void Menu_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, Employee_list);
	DDX_Control(pDX, IDC_LIST2, Product_list);
	DDX_Control(pDX, IDC_LIST1, Bill_list);
}

BOOL Menu_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	UpdateTable();

	return TRUE;
}


BEGIN_MESSAGE_MAP(Menu_dlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL2, &Menu_dlg::OnBnClickedCancel2)
	ON_BN_CLICKED(IDCANCEL3, &Menu_dlg::OnBnClickedCancel3)
	ON_BN_CLICKED(IDCANCEL4, &Menu_dlg::OnBnClickedCancel4)
	ON_BN_CLICKED(IDCANCEL5, &Menu_dlg::OnBnClickedCancel5)
	ON_BN_CLICKED(IDCANCEL6, &Menu_dlg::OnBnClickedCancel6)
END_MESSAGE_MAP()

//====================
void Menu_dlg::UpdateTable() {

	Employee_list.ResetContent();
	MyList<Employee> E_list = store->GetEmployeeList();
	int n = E_list.N();
	for (size_t i = 0; i < n; i++)
	{
		string s = E_list.Arr()[i].GetName();
		CString cs(s.c_str());
		Employee_list.AddString(cs);
	}


	Product_list.ResetContent();
	MyList<Product> P_list = store->GetProductList();
	n = P_list.N();
	for (size_t i = 0; i < n; i++)
	{
		string s = P_list.Arr()[i].GetName();
		CString cs(s.c_str());
		Product_list.AddString(cs);
	}

	Bill_list.ResetContent();
	MyList<Bill> B_list = store->GetBillList();
	n = B_list.N();
	for (size_t i = 0; i < B_list.N(); i++)
	{
		string s = B_list.Arr()[i].GetID();
		CString cs(s.c_str());
		Bill_list.AddString(cs);
	}

}



// Menu_dlg message handlers


void Menu_dlg::OnBnClickedCancel2()
{
	Product_dlg dlg;
	dlg.DoModal();
	UpdateTable();
}

void Menu_dlg::OnBnClickedCancel3()
{
	Employee_dlg dlg;
	INT_PTR nResponse = dlg.DoModal();
	UpdateTable();
}

void Menu_dlg::OnBnClickedCancel4()
{
	Bill_dlg dlg;
	dlg.DoModal();
	UpdateTable();
}

void Menu_dlg::OnBnClickedCancel5()
{
	store->Import("store.bin");
	UpdateTable();

}


void Menu_dlg::OnBnClickedCancel6()
{
	store->Export("store.bin");
}
