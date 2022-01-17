#pragma once


// Add_Bill_dlg dialog

class Add_Bill_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Add_Bill_dlg)

public:
	Add_Bill_dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Add_Bill_dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = ADD_BILL_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString bill_ID_tb;
	afx_msg void OnBnClickedCancel3();
};
