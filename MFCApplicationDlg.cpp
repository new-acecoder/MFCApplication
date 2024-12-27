
// MFCApplicationDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication.h"
#include "MFCApplicationDlg.h"
#include "afxdialogex.h"
#include"ChildDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplicationDlg 对话框



CMFCApplicationDlg::CMFCApplicationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION_DIALOG, pParent)
	, s_find(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, s_list);
	DDX_Text(pDX, IDC_EDIT1, s_find);
}

BEGIN_MESSAGE_MAP(CMFCApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CMFCApplicationDlg::OnLvnItemchangedList1)

	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplicationDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplicationDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplicationDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplicationDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplicationDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplicationDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplicationDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplicationDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CMFCApplicationDlg 消息处理程序

BOOL CMFCApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//设置ListCtrl风格
	DWORD dwStyle = s_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;	//选中某行使整行高亮（只适用与report风格的ListCtrl） 
	dwStyle |= LVS_EX_GRIDLINES;	   //网格线（只适用与report风格的ListCtrl） 
	s_list.SetExtendedStyle(dwStyle); //设置扩展风格 

	s_list.InsertColumn(0, TEXT("职工编号"), 2, 120);
	s_list.InsertColumn(1, TEXT("职工姓名"), 2, 120);
	s_list.InsertColumn(2, TEXT("职工性别"), 2, 120);
	s_list.InsertColumn(3, TEXT("所在部门"), 2, 120);
	s_list.InsertColumn(4, TEXT("职工年龄"), 2, 120);
	s_list.InsertColumn(5, TEXT("工作时间"), 2, 120);
	s_list.InsertColumn(6, TEXT("基本工资"), 2, 120);
	s_list.InsertColumn(7, TEXT("职称"), 2, 120);
	s_list.InsertColumn(8, TEXT("简历"), 2, 420);
	isOpen = false;



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CMFCApplicationDlg::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMFCApplicationDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	 // 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		 //如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		DataInterface.Open(strFilePath);
		isOpen = true;
		UpdateList();
		//MessageBox(TEXT("123"));
	}

	
}

void CMFCApplicationDlg::UpdateList()
{
	s_list.DeleteAllItems();
	CString str;
	for (int i = 0; i < DataInterface.Infos.size(); i++) {
		str.Format(TEXT("%lld"), DataInterface.Infos[i].s_id);
		s_list.InsertItem(i, str);
		s_list.SetItemText(i, 1, DataInterface.Infos[i].s_name.c_str());
		s_list.SetItemText(i, 2, DataInterface.Infos[i].s_gender.c_str());
		s_list.SetItemText(i, 3, DataInterface.Infos[i].s_depart.c_str());
		str.Format(TEXT("%d"), DataInterface.Infos[i].s_age);
		s_list.SetItemText(i, 4, str);
		s_list.SetItemText(i, 5, DataInterface.Infos[i].s_date.c_str());
		str.Format(TEXT("%lf"), DataInterface.Infos[i].s_salary);
		s_list.SetItemText(i, 6, str);
		s_list.SetItemText(i, 7, DataInterface.Infos[i].s_title.c_str());
		s_list.SetItemText(i, 8, DataInterface.Infos[i].s_vitae.c_str());


		//s_list.SetItemText(i, 1, str);
	}
}





void CMFCApplicationDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isOpen) {
		ChildDlg dlg;
		if (IDOK == dlg.DoModal()) {
			// 从 ChildDlg 中获取数据，并将 CString 转换为 std::string 或其他合适类型
			long long id = _ttoi64(dlg.s_id);  // CString 转 long long
			string name(CT2A(dlg.s_name));  // CString 转 std::string
			string gender(CT2A(dlg.s_gender));  // CString 转 std::string
			string depart(CT2A(dlg.s_depart));  // CString 转 std::string
			int age = _ttoi(dlg.s_age);  // CString 转 int
			string date(CT2A(dlg.s_date));  // CString 转 std::string
			float salary = static_cast<float>(_ttof(dlg.s_salary));  // CString 转 float
			string title(CT2A(dlg.s_title));  // CString 转 std::string
			string vitae(CT2A(dlg.s_vitae));  // CString 转 std::string

			// 创建 CInfo 对象并使用有参构造函数
			CInfo info(id, name, gender, depart, age, date, salary, title, vitae);

			// 添加到 DataInterface
			DataInterface.Add(info);
			UpdateList();
		}
	}
	else {
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));
	}
	
}


void CMFCApplicationDlg::OnBnClickedButton5()
{	// TODO: 在此添加控件通知处理程序代码
	if (isOpen) {
		int index=s_list.GetSelectionMark();
		/*CString str;
		str.Format(TEXT("%d"), index);
		MessageBox(str);*/
		if (index > -1) {
			UINT i;
			i = MessageBox(_T("确定要删除这个员工信息吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
			if (i == IDYES)
			{
				DataInterface.Del(index);
				MessageBox(TEXT("删除成功"), TEXT("提示"));
				UpdateList();
			}

		}
		else {
			MessageBox(TEXT("请先选中需要删除的一行"), TEXT("提示"));
		}
	}
	else {
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));
	}
	
	

	 

}


void CMFCApplicationDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isOpen) {
		int index = s_list.GetSelectionMark();
	
		if (index > -1) {

			ChildDlg dlg;
			dlg.s_id.Format(_T("%lld"), DataInterface.Infos[index].s_id);
			dlg.s_name = DataInterface.Infos[index].s_name.c_str(); // std::string 转 CString
			dlg.s_gender = DataInterface.Infos[index].s_gender.c_str();
			dlg.s_depart = DataInterface.Infos[index].s_depart.c_str();
			dlg.s_age.Format(_T("%d"), DataInterface.Infos[index].s_age); // int 转 CString
			dlg.s_date = DataInterface.Infos[index].s_date.c_str();
			dlg.s_salary.Format(_T("%.2f"), DataInterface.Infos[index].s_salary); // float 转 CString
			dlg.s_title = DataInterface.Infos[index].s_title.c_str();
			dlg.s_vitae = DataInterface.Infos[index].s_vitae.c_str();
			if (IDOK == dlg.DoModal()) {
				// 从 ChildDlg 中获取数据，并将 CString 转换为 std::string 或其他合适类型
				long long id = _ttoi64(dlg.s_id);  // CString 转 long long
				string name(CT2A(dlg.s_name));  // CString 转 std::string
				string gender(CT2A(dlg.s_gender));  // CString 转 std::string
				string depart(CT2A(dlg.s_depart));  // CString 转 std::string
				int age = _ttoi(dlg.s_age);  // CString 转 int
				string date(CT2A(dlg.s_date));  // CString 转 std::string
				float salary = static_cast<float>(_ttof(dlg.s_salary));  // CString 转 float
				string title(CT2A(dlg.s_title));  // CString 转 std::string
				string vitae(CT2A(dlg.s_vitae));  // CString 转 std::string

				// 创建 CInfo 对象并使用有参构造函数
				CInfo Info(id, name, gender, depart, age, date, salary, title, vitae);

				// 添加到 DataInterface
				DataInterface.Amend(index,Info);
				UpdateList();
			}

		}
		else {
			MessageBox(TEXT("请先选中需要修改的一行"), TEXT("提示"));
		}
	}
	else {
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));
	}
	
}


void CMFCApplicationDlg::OnBnClickedButton7()
{
	if (isOpen) {
		// 更新控件数据
		UpdateData(TRUE);

		// 转换输入的 ID 为 long long
		long long id = _ttoi64(s_find);

		// 查找员工信息
		CInfo FindInfo = DataInterface.Find(id);

		// 判断是否找到
		if (FindInfo.s_id == -1) {
			MessageBox(TEXT("没有该员工"), TEXT("提示"));
		}
		else {
			CString str;
			str.Format(TEXT("查找成功!\n\n员工编号: %lld\n员工姓名: %s\n员工性别: %s\n所在部门: %s\n员工年龄: %d\n工作时间: %s\n员工工资: %.2f\n职称: %s\n简历: %s"),
				FindInfo.s_id,
				FindInfo.s_name.c_str(),
				FindInfo.s_gender.c_str(),
				FindInfo.s_depart.c_str(),
				FindInfo.s_age,
				FindInfo.s_date.c_str(),
				FindInfo.s_salary,
				FindInfo.s_title.c_str(),
				FindInfo.s_vitae.c_str());
			MessageBox(str, TEXT("提示"));
		}
	}
	else {
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));
	}
	
}



void CMFCApplicationDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isOpen) {
		if (DataInterface.Save(strFilePath)) {
			MessageBox(TEXT("已保存"), TEXT("提示"));
		}
		else {
			MessageBox(TEXT("保存失败"), TEXT("提示"));
		}
	}
	else {
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));
	}
	
}


void CMFCApplicationDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT i;
	i = MessageBox(_T("确定退出吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
	if (i == IDYES)
	{
		exit(0);
	}
	else {
		return;
	}
}


void CMFCApplicationDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	DataInterface.SortByID();

	// 提示用户
	MessageBox(TEXT("员工信息已按编号升序排序"), TEXT("提示"));

	// 更新界面上的列表（假设你有一个列表控件显示员工信息）
	UpdateList();
}
