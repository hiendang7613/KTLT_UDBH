#pragma once

#include "framework.h"
// Menu_dlg dialog

class Menu_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Menu_dlg)
	
public:
	Menu_dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Menu_dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = MENU_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP();
	void UpdateTable();
public:
	afx_msg void OnBnClickedCancel2();
	afx_msg void OnBnClickedCancel3();
	afx_msg void OnBnClickedCancel4();
	CListBox Employee_list;
	CListBox Product_list;
	CListBox Bill_list;
	afx_msg void OnBnClickedCancel5();
	afx_msg void OnBnClickedCancel6();
};
