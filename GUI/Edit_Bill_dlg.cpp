#include "GUI.h"
#include "Edit_Bill_dlg.h"
#include "afxdialogex.h"


// Edit_Bill_dlg dialog

IMPLEMENT_DYNAMIC(Edit_Bill_dlg, CDialogEx)

Edit_Bill_dlg::Edit_Bill_dlg(Bill* bill, CWnd* pParent /*=nullptr*/)
	: CDialogEx(Edit_BILL_DLG, pParent)
{
	this->bill = bill;
}

Edit_Bill_dlg::~Edit_Bill_dlg()
{
}

void Edit_Bill_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list);
	DDX_Control(pDX, IDC_COMBO1, Product_cb);
	DDX_Control(pDX, IDC_EDIT5, count_tb);
}


BEGIN_MESSAGE_MAP(Edit_Bill_dlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL4, &Edit_Bill_dlg::OnBnClickedCancel4)
//	ON_BN_CLICKED(IDOK, &Edit_Bill_dlg::OnBnClickedOk)
ON_BN_CLICKED(IDCANCEL3, &Edit_Bill_dlg::OnBnClickedCancel3)
END_MESSAGE_MAP()


// Edit_Bill_dlg message handlers

BOOL Edit_Bill_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	list.InsertColumn(0, (CA2T)"ID");
	list.SetColumnWidth(0, 100);

	list.InsertColumn(1, (CA2T)"Name");
	list.SetColumnWidth(1, 100);

	list.InsertColumn(2, (CA2T)"Count");
	list.SetColumnWidth(2, 100);

	UpdateTable();

	MyList<Product> P_list = store->GetProductList();
	int n = P_list.N();
	Product* _list = P_list.Arr();
	for (size_t i = 0; i < n; i++)
	{
		string s = _list[i].GetID()+" - " + _list[i].GetName();
		CString cs(s.c_str());
		Product_cb.AddString(cs);
	}

	return TRUE;
}






void Edit_Bill_dlg::UpdateTable() {

	list.DeleteAllItems();
	auto ProductList = bill->ProductList();

	int i = 0;
	string s;

	for (auto it = ProductList->begin(); it != ProductList->end(); it++, i++)
	{
		Product_Count x = it->second;

		s = x.product.GetID();
		AddData(list, i, 0, s);
		s = x.product.GetName();
		AddData(list, i, 1, s);
		s = to_string(x.count);
		AddData(list, i, 2, s);
	}
}

void Edit_Bill_dlg::OnBnClickedCancel4()
{
	int pos = Product_cb.GetCurSel();
	Product product = store->GetProductList().Arr()[pos];

	CString cs;
	count_tb.GetWindowTextW(cs);
	string s = (CT2CA) cs;
	int n = stoi(s);
	bill->UpdateProduct(product, n);
	UpdateTable();
}


void Edit_Bill_dlg::OnBnClickedCancel3()
{
	int pos = Product_cb.GetCurSel();
	string id = store->GetProductList().Arr()[pos].GetID();
	bill->DeleteProduct(id);
	UpdateTable();
}
