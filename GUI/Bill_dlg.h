#pragma once


// Bill_dlg dialog

class Bill_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Bill_dlg)

public:
	Bill_dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Bill_dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = BILL_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	void UpdateTable();

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl list;
	afx_msg void OnBnClickedCancel3();
	afx_msg void OnBnClickedCancel4();
	afx_msg void OnBnClickedCancel2();
	CComboBox date_cb;
	CEdit Product_count_tb;
	CEdit total_tb;
	afx_msg void OnCbnEditupdateCombo2();
	afx_msg void OnCbnSelchangeCombo2();
};
