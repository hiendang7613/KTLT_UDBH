#pragma once


// Edit_Bill_dlg dialog

class Edit_Bill_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Edit_Bill_dlg)

public:
	Edit_Bill_dlg(Bill* bill, CWnd* pParent = nullptr);   // standard constructor
	virtual ~Edit_Bill_dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = Edit_BILL_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	void UpdateTable();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl list;
	Bill* bill;
	CComboBox Product_cb;
	CEdit count_tb;
	afx_msg void OnBnClickedCancel4();
	afx_msg void OnBnClickedCancel3();
};
