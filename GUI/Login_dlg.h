#pragma once


// Login_dlg dialog

class Login_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Login_dlg)

public:
	Login_dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Login_dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = LOGIN_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	CString user;
	CString pass;
	afx_msg void OnBnClickedOk();
};
