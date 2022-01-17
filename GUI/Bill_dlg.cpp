#include "GUI.h"
#include "Bill_dlg.h"
#include "Add_Bill_dlg.h"
#include "Edit_Bill_dlg.h"
#include "afxdialogex.h"


// Bill_dlg dialog

IMPLEMENT_DYNAMIC(Bill_dlg, CDialogEx)

Bill_dlg::Bill_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(BILL_DLG, pParent)
{

}

Bill_dlg::~Bill_dlg()
{
}

void Bill_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, list);
	DDX_Control(pDX, IDC_COMBO2, date_cb);
	DDX_Control(pDX, IDC_EDIT8, Product_count_tb);
	DDX_Control(pDX, IDC_EDIT9, total_tb);
}


BEGIN_MESSAGE_MAP(Bill_dlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL3, &Bill_dlg::OnBnClickedCancel3)
	ON_BN_CLICKED(IDCANCEL4, &Bill_dlg::OnBnClickedCancel4)
	ON_BN_CLICKED(IDCANCEL2, &Bill_dlg::OnBnClickedCancel2)
	ON_CBN_EDITUPDATE(IDC_COMBO2, &Bill_dlg::OnCbnEditupdateCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &Bill_dlg::OnCbnSelchangeCombo2)
END_MESSAGE_MAP();


// Bill_dlg message handlers


BOOL Bill_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	list.InsertColumn(0, (CA2T)"ID");
	list.SetColumnWidth(0, 100);

	list.InsertColumn(1, (CA2T)"Date");
	list.SetColumnWidth(1, 100);

	list.InsertColumn(2, (CA2T)"Total");
	list.SetColumnWidth(2, 100);

	UpdateTable();



	return TRUE;
}






void Bill_dlg::UpdateTable() {

	list.DeleteAllItems(); 
	date_cb.ResetContent();

	MyList<Bill> B_list = store->GetBillList();
	int n = B_list.N();
	Bill* _list = B_list.Arr();
	string s;
	for (size_t i = 0; i < n; i++)
	{
		s = _list[i].GetID();
		AddData(list, i, 0, s);
		s = _list[i].GetTimeString();
		AddData(list, i, 1, s);
		date_cb.AddString((CA2CT)s.c_str());
		s = to_string(_list[i].GetTotalCost());
		AddData(list, i, 2, s);
	}
}




void Bill_dlg::OnBnClickedCancel3()
{
	Add_Bill_dlg dlg;
	dlg.DoModal();
	UpdateTable();

}


void Bill_dlg::OnBnClickedCancel4()
{
	POSITION pos = list.GetFirstSelectedItemPosition();
	if (pos != NULL)
	{
		int delIndex = list.GetNextSelectedItem(pos);
		Bill* s = &store->GetBillList().Arr()[delIndex];
		Edit_Bill_dlg dlg(s);
		dlg.DoModal();
		UpdateTable();
	}

}


void Bill_dlg::OnBnClickedCancel2()
{
	POSITION pos = list.GetFirstSelectedItemPosition();
	if (pos != NULL)
	{
		int delIndex = list.GetNextSelectedItem(pos);
		string s = store->GetBillList().Arr()[delIndex].GetID();
		store->DeleteBill(s);
		list.DeleteItem(delIndex);
	}
}


void Bill_dlg::OnCbnEditupdateCombo2()
{
	int total=0;
	int count=0;

	Bill billnow;

	MyList<Bill> B_list = store->GetBillList();
	vector<int> pos = B_list.Find(billnow, Bill::CompareFuncDate);
	int n = pos.size();
	Bill* _list = B_list.Arr();

	string s;
	for (size_t i = 0; i < n; i++)
	{
		Bill bill = _list[pos[i]];
		total += bill.GetTotalCost();

		auto ProductList = bill.ProductList();

		for (auto it = ProductList->begin(); it != ProductList->end(); it++, i++)
		{
			count += it->second.count;
		}

	}
	CString cs;
	cs.Format(L"%d", total);
	total_tb.SetWindowTextW(cs);
	cs.Format(L"%d", count);
	Product_count_tb.SetWindowTextW(cs);
}


void Bill_dlg::OnCbnSelchangeCombo2()
{
	int total = 0;
	int count = 0;

	Bill billnow;

	MyList<Bill> B_list = store->GetBillList();
	vector<int> pos = B_list.Find(billnow, Bill::CompareFuncDate);
	int n = pos.size();
	Bill* _list = B_list.Arr();

	string s;
	for (size_t i = 0; i < n; i++)
	{
		Bill bill = _list[pos[i]];
		total += bill.GetTotalCost();

		auto ProductList = bill.ProductList();

		for (auto it = ProductList->begin(); it != ProductList->end(); it++)
		{
			count += it->second.count;
		}

	}
	CString cs;
	cs.Format(L"%d", total);
	total_tb.SetWindowTextW(cs);
	cs.Format(L"%d", count);
	Product_count_tb.SetWindowTextW(cs);
	// TODO: Add your control notification handler code here
}
