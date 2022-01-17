#include "GUI.h"
#include "Product_dlg.h"

#include "afxdialogex.h"


// Product_dlg dialog

IMPLEMENT_DYNAMIC(Product_dlg, CDialogEx)

Product_dlg::Product_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(PRODUCT_DLG, pParent)
{
	
}

Product_dlg::~Product_dlg()
{
}

void Product_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, list);
	DDX_Control(pDX, IDC_EDIT7, iD_tb);
	DDX_Control(pDX, IDC_EDIT6, name_tb);
	DDX_Control(pDX, IDC_EDIT5, type_tb);
	DDX_Control(pDX, IDC_EDIT4, cost_tb);
	DDX_Control(pDX, IDCANCEL4, update_btn);
}


BEGIN_MESSAGE_MAP(Product_dlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL3, &Product_dlg::OnBnClickedCancel3)
	ON_BN_CLICKED(IDCANCEL4, &Product_dlg::OnBnClickedCancel4)
	ON_BN_CLICKED(IDCANCEL2, &Product_dlg::OnBnClickedCancel2)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &Product_dlg::OnNMClickList2)
END_MESSAGE_MAP()


BOOL Product_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	list.InsertColumn(0, (CA2T)"ID");
	list.SetColumnWidth(0, 100);

	list.InsertColumn(1, (CA2T)"Name");
	list.SetColumnWidth(1, 100);

	list.InsertColumn(2, (CA2T)"Type");
	list.SetColumnWidth(2, 100);

	list.InsertColumn(3, (CA2T)"Cost");
	list.SetColumnWidth(3, 100);

	UpdateTable();

	if (!isAdmin) {
		update_btn.EnableWindow(false);
	}

	return TRUE;
}

// Product_dlg message handlers



void Product_dlg::UpdateTable() {

	list.DeleteAllItems();



	MyList<Product> P_list = store->GetProductList();
	int n = P_list.N();
	Product* _list = P_list.Arr();
	string s;
	for (size_t i = 0; i < n; i++)
	{
		s = _list[i].GetID();
		AddData(list, i, 0, s);
		s = _list[i].GetName();
		AddData(list, i, 1, s);
		s = _list[i].GetType();
		AddData(list, i, 2, s);
		s = to_string(  _list[i].GetCost());
		AddData(list, i, 3, s);
	}


}




void Product_dlg::OnBnClickedCancel3()
{
	// TODO: Add your control notification handler code here
	CString s;
	CString s2;
	CString s3;
	CString s4;
	iD_tb.GetWindowTextW(s);
	name_tb.GetWindowTextW(s2);
	type_tb.GetWindowTextW(s3);
	cost_tb.GetWindowTextW(s4);

	string id = (CT2CA)s;
	string fullname = (CT2CA)s2;
	string type = (CT2CA)s3;
	string cost = (CT2CA)s4;

	store->AddProduct(Product(id, fullname, type, stoi( cost)));

	UpdateTable();
}


void Product_dlg::OnBnClickedCancel4()
{
	// TODO: Add your control notification handler code here
	CString s;
	CString s2;
	CString s3;
	CString s4;
	iD_tb.GetWindowTextW(s);
	name_tb.GetWindowTextW(s2);
	type_tb.GetWindowTextW(s3);
	cost_tb.GetWindowTextW(s4);

	string id = (CT2CA)s;
	string fullname = (CT2CA)s2;
	string type = (CT2CA)s3;
	string cost = (CT2CA)s4;

	store->UpdateProduct(Product(id, fullname, type, stoi(cost)));

	UpdateTable();
}




void Product_dlg::OnBnClickedCancel2()
{
	// TODO: Add your control notification handler code here	
	POSITION pos = list.GetFirstSelectedItemPosition();
	if (pos != NULL)
	{
		int delIndex = list.GetNextSelectedItem(pos);
		string s = store->GetProductList().Arr()[delIndex].GetID();
		store->DeleteProduct(s);
		list.DeleteItem(delIndex);
	}
}



void Product_dlg::OnNMClickList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;	
	POSITION pos = list.GetFirstSelectedItemPosition();
	if (pos != NULL)
	{
		int delIndex = list.GetNextSelectedItem(pos);
		Product e = store->GetProductList().Arr()[delIndex];

		CString s(e.GetID().c_str());
		CString s2(e.GetName().c_str());
		CString s3(e.GetType().c_str());
		CString s4(to_string(e.GetCost()).c_str());

		iD_tb.SetWindowTextW(s);
		name_tb.SetWindowTextW(s2);
		type_tb.SetWindowTextW(s3);
		cost_tb.SetWindowTextW(s4);

	}
}
