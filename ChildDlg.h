#pragma once
#include "afxdialogex.h"


// ChildDlg 对话框

class ChildDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChildDlg)

public:
	ChildDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChildDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ChildDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnEnChangeEdit9();
	CString s_id;
	CString s_name;
	CString s_gender;
	CString s_depart;
	CString s_age;
	CString s_salary;
	afx_msg void OnEnChangeButton4();
	CString s_date;
	CString s_title;
	CString s_vitae;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
