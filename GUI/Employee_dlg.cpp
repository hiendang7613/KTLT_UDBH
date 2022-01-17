#include "GUI.h"
#include "Employee_dlg.h"
#include "afxdialogex.h"

// Employee_dlg dialog

Store* store;
bool isAdmin;

IMPLEMENT_DYNAMIC(Employee_dlg, CDialogEx)

Employee_dlg::Employee_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(EMPLOYEE_DLG, pParent)
{

}

Employee_dlg::~Employee_dlg()
{
}

void Employee_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST4, list);
	DDX_Control(pDX, IDC_EDIT1, iD_tb);
	DDX_Control(pDX, IDC_EDIT6, name_tb);
	DDX_Control(pDX, IDC_EDIT5, user_tb);
	DDX_Control(pDX, IDC_EDIT4, pass_tb);
	DDX_Control(pDX, IDCANCEL4, update_btn);
}


BOOL Employee_dlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	list.InsertColumn(0, (CA2T)"ID");
	list.SetColumnWidth(0, 100);

	list.InsertColumn(1, (CA2T)"FullName");
	list.SetColumnWidth(1, 100);

	list.InsertColumn(2, (CA2T)"Username");
	list.SetColumnWidth(2, 100);

	list.InsertColumn(3, (CA2T)"Password");
	list.SetColumnWidth(3, 100);

	UpdateTable();

	if (!isAdmin) {
		update_btn.EnableWindow(false);
	}

	return TRUE;
}




BEGIN_MESSAGE_MAP(Employee_dlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL3, &Employee_dlg::OnBnClickedCancel3)
	ON_BN_CLICKED(IDOK, &Employee_dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL4, &Employee_dlg::OnBnClickedCancel4)
	ON_NOTIFY(NM_CLICK, IDC_LIST4, &Employee_dlg::OnNMClickList4)
END_MESSAGE_MAP()

void Employee_dlg::UpdateTable() {

	list.DeleteAllItems();

	MyList<Employee> E_list = store->GetEmployeeList();
	int n = E_list.N();
	Employee* _list = E_list.Arr();
	string s;
	for (size_t i = 0; i < n; i++)
	{
		s = _list[i].GetID();
		AddData(list, i, 0, s);
		s = _list[i].GetName();
		AddData(list, i, 1, s);
		s = _list[i].GetUsername();
		AddData(list, i, 2, s);
		s = _list[i].GetPassword();
		AddData(list, i, 3, s);
	}


}





void Employee_dlg::OnBnClickedCancel3()
{
	CString s;
	CString s2;
	CString s3;
	CString s4;
	iD_tb.GetWindowTextW(s);
	name_tb.GetWindowTextW(s2);
	user_tb.GetWindowTextW(s3);
	pass_tb.GetWindowTextW(s4);

	string id = (CT2CA)s;
	string fullname = (CT2CA)s2;
	string username = (CT2CA)s3;
	string password = (CT2CA)s4;

	store->AddEmployee(Employee(id, fullname, username, password, 0));

	UpdateTable();
}


void Employee_dlg::OnBnClickedOk()
{
	POSITION pos = list.GetFirstSelectedItemPosition();
	if (pos != NULL)
	{
		int delIndex = list.GetNextSelectedItem(pos);
		string s = store->GetEmployeeList().Arr()[delIndex].GetID();
		store->DeleteEmployee(s);
		list.DeleteItem(delIndex);
	}
}



void Employee_dlg::OnBnClickedCancel4()
{
	CString s;
	CString s2;
	CString s3;
	CString s4;
	iD_tb.GetWindowTextW(s);
	name_tb.GetWindowTextW(s2);
	user_tb.GetWindowTextW(s3);
	pass_tb.GetWindowTextW(s4);

	string id = (CT2CA)s;
	string fullname = (CT2CA)s2;
	string username = (CT2CA)s3;
	string password = (CT2CA)s4;

	store->UpdateEmployee(Employee(id, fullname, username, password, 0));

	UpdateTable();
}



void Employee_dlg::OnNMClickList4(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	POSITION pos = list.GetFirstSelectedItemPosition();
	if (pos != NULL)
	{
		int delIndex = list.GetNextSelectedItem(pos);
		Employee e = store->GetEmployeeList().Arr()[delIndex];

		CString s(e.GetID().c_str());
		CString s2(e.GetName().c_str());
		CString s3(e.GetUsername().c_str());
		CString s4(e.GetPassword().c_str());

		iD_tb.SetWindowTextW(s);
		name_tb.SetWindowTextW(s2);
		user_tb.SetWindowTextW(s3);
		pass_tb.SetWindowTextW(s4);

	}
}
