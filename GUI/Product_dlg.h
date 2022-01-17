#pragma once


// Product_dlg dialog

class Product_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Product_dlg)

public:
	Product_dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Product_dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = PRODUCT_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void UpdateTable();
	virtual BOOL Product_dlg::OnInitDialog();


	DECLARE_MESSAGE_MAP()
public:
	CListCtrl list;
	CEdit iD_tb;
	CEdit name_tb;
	CEdit type_tb;
	CEdit cost_tb;
	afx_msg void OnBnClickedCancel3();
	afx_msg void OnBnClickedCancel4();
	afx_msg void OnBnClickedCancel2();
	afx_msg void OnNMClickList2(NMHDR* pNMHDR, LRESULT* pResult);
	CButton update_btn;
};
