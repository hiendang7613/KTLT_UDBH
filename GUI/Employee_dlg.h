#pragma once


// Employee_dlg dialog

class Employee_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Employee_dlg)

public:
	Employee_dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Employee_dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = EMPLOYEE_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	void UpdateTable();

		 
public:
	CListCtrl list;
	CEdit iD_tb;
	afx_msg void OnBnClickedCancel3();
	afx_msg void OnBnClickedOk();
	CEdit name_tb;
	CEdit user_tb;
	CEdit pass_tb;


	afx_msg void OnBnClickedCancel4();
	afx_msg void OnNMClickList4(NMHDR* pNMHDR, LRESULT* pResult);
	CButton update_btn;
};

