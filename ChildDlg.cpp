// ChildDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication.h"
#include "afxdialogex.h"
#include "ChildDlg.h"


// ChildDlg 对话框

IMPLEMENT_DYNAMIC(ChildDlg, CDialogEx)

ChildDlg::ChildDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChildDlg, pParent)
	, s_id(_T(""))
	, s_name(_T(""))
	, s_gender(_T(""))
	, s_depart(_T(""))
	, s_age(_T(""))
	, s_salary(_T(""))
	, s_date(_T(""))
	, s_title(_T(""))
	, s_vitae(_T(""))
{

}

ChildDlg::~ChildDlg()
{
}

void ChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s_id);
	DDX_Text(pDX, IDC_EDIT2, s_name);
	DDX_Text(pDX, IDC_EDIT3, s_gender);
	DDX_Text(pDX, IDC_EDIT4, s_depart);
	DDX_Text(pDX, IDC_EDIT5, s_age);
	DDX_Text(pDX, IDC_EDIT7, s_salary);
	DDX_Text(pDX, IDC_EDIT6, s_date);
	DDX_Text(pDX, IDC_EDIT8, s_title);
	DDX_Text(pDX, IDC_EDIT9, s_vitae);
}


BEGIN_MESSAGE_MAP(ChildDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT8, &ChildDlg::OnEnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT9, &ChildDlg::OnEnChangeEdit9)
	ON_EN_CHANGE(IDC_BUTTON4, &ChildDlg::OnEnChangeButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &ChildDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ChildDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// ChildDlg 消息处理程序


void ChildDlg::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChildDlg::OnEnChangeEdit9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChildDlg::OnEnChangeButton4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChildDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (s_id == TEXT("") || s_name == TEXT("") || s_gender == TEXT("") || s_depart == TEXT("") ||
		s_age == TEXT("") || s_date == TEXT("") || s_salary == TEXT("") || s_title == TEXT("") ||
		s_vitae == TEXT("")) {
		MessageBox(TEXT("您有输入为空，请补充完整"), TEXT("提示"));
	}
	else {
		OnOK();
		
		return;
	}
}


void ChildDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}
