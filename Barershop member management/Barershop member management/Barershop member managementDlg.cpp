
// Barershop member managementDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Barershop member management.h"
#include "Barershop member managementDlg.h"
#include "afxdialogex.h"
#include "infoDlg.h"
#include "ChildDlg1.h"
#include "ChildDlg2.h"
#include "Childc1.h"
#include "Childc2.h"
#include "Childc3.h"
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


// CBarershopmembermanagementDlg 对话框



CBarershopmembermanagementDlg::CBarershopmembermanagementDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BARERSHOP_MEMBER_MANAGEMENT_DIALOG, pParent)
	, m_aver(_T(""))
	, m_sum(0)
	, m_num(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBarershopmembermanagementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST4, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_sex);
	DDX_Control(pDX, IDC_COMBO2, m_grade);
	DDX_Text(pDX, IDC_EDIT1, m_aver);
	DDX_Text(pDX, IDC_EDIT2, m_sum);
	DDX_Text(pDX, IDC_EDIT3, m_num);
	DDX_Control(pDX, IDC_COMBO3, m_rule1);
	DDX_Control(pDX, IDC_COMBO4, m_ctype);
}

BEGIN_MESSAGE_MAP(CBarershopmembermanagementDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CBarershopmembermanagementDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CBarershopmembermanagementDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CBarershopmembermanagementDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CBarershopmembermanagementDlg::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CBarershopmembermanagementDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON6, &CBarershopmembermanagementDlg::OnBnClickedButton6)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CBarershopmembermanagementDlg::OnCbnSelchangeCombo3)
	ON_BN_CLICKED(IDC_BUTTON7, &CBarershopmembermanagementDlg::OnBnClickedButton7)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CBarershopmembermanagementDlg::OnCbnSelchangeCombo4)
	ON_BN_CLICKED(IDC_BUTTON5, &CBarershopmembermanagementDlg::OnBnClickedButton5)
	ON_EN_CHANGE(IDC_EDIT1, &CBarershopmembermanagementDlg::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CBarershopmembermanagementDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CBarershopmembermanagementDlg 消息处理程序

BOOL CBarershopmembermanagementDlg::OnInitDialog()
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
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	// 整行选择、网格线
	m_list.InsertColumn(0, _T("手机号"), LVCFMT_LEFT, 200);	// 插入第2列的列名
	m_list.InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 100);	// 插入第3列的列名
	m_list.InsertColumn(2, _T("性别"), LVCFMT_LEFT, 100);	// 插入第4列的列名
	m_list.InsertColumn(3, _T("余额"), LVCFMT_LEFT, 100);	// 插入第5列的列名
	m_list.InsertColumn(4, _T("等级"), LVCFMT_LEFT, 100);	// 插入第6列的列名
	
	m_sex.AddString(TEXT("男"));
	m_sex.AddString(TEXT("女"));
	m_sex.AddString(TEXT("全部"));
	m_sex.SetCurSel(2);

	m_grade.AddString(TEXT("vip"));
	m_grade.AddString(TEXT("svip"));
	m_grade.AddString(TEXT("svip+"));
	m_grade.AddString(TEXT("全部"));
	m_grade.SetCurSel(3);

	m_rule1.AddString(TEXT("按充值金额降序"));
	m_rule1.AddString(TEXT("按充值金额升序"));
	m_rule1.AddString(TEXT("按会员等级分类"));
	m_rule1.AddString(TEXT("按性别分类"));

	m_ctype.AddString(TEXT("姓名"));
	m_ctype.AddString(TEXT("手机号"));
	m_ctype.AddString(TEXT("性别"));
	m_ctype.SetCurSel(1);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CBarershopmembermanagementDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBarershopmembermanagementDlg::OnPaint()
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
HCURSOR CBarershopmembermanagementDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBarershopmembermanagementDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (SQL.Connect_MySQL())
	{
		Info = SQL.Get_All_Info();
		CString str;
		UpdateList();
	}
	else
	{
		return;
	}
}


void CBarershopmembermanagementDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_list.GetSelectionMark();
	if (index == -1)
	{
		MessageBox(TEXT("请先选择要消费的会员！"), TEXT("提示"));
		return;
	}
	else
	{
		ChildDlg1 dlg;
		if (dlg.DoModal()==IDOK)
		{

			if (SQL.Update_info(Info[index],MemberInfo(Info[index].m_phone, Info[index].m_name, Info[index].m_sex, Info[index].m_balance-dlg.m_money, Info[index].m_grade)))
			{
				MessageBox(TEXT("消费成功！"), TEXT("提示"));
				Info[index].m_balance = Info[index].m_balance - dlg.m_money;
				UpdateList();
			}
		}
		
	}
}


void CBarershopmembermanagementDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	infoDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CString grade;
		if (dlg.m_balance < 500)
			grade = TEXT("普通");
		else if (dlg.m_balance <= 1000)
			grade = TEXT("VIP");
		else if (dlg.m_balance <= 2000)
			grade = TEXT("SVIP");
		else
			grade = TEXT("SVIP+");
		dlg.m_grade = grade;
		if (SQL.Add_Info(MemberInfo(dlg.m_phone.GetBuffer(), dlg.m_name.GetBuffer(), dlg.m_sex.GetBuffer(), dlg.m_balance, dlg.m_grade.GetBuffer())))
		{
			
			MessageBox(TEXT("添加成功！"), TEXT("提示"));
			Info.push_back(MemberInfo(dlg.m_phone.GetBuffer(), dlg.m_name.GetBuffer(), dlg.m_sex.GetBuffer(), dlg.m_balance, dlg.m_grade.GetBuffer()));
			UpdateList();
		}
	}
	
}

void CBarershopmembermanagementDlg::UpdateList()
{
	m_list.DeleteAllItems();
	CString str;
	for (int i = 0; i < Info.size(); i++)
	{
		m_list.InsertItem(i, Info[i].m_phone.c_str());
		m_list.SetItemText(i, 1, Info[i].m_name.c_str());
		m_list.SetItemText(i, 2, Info[i].m_sex.c_str());
		str.Format(TEXT("%.1lf"), Info[i].m_balance);
		m_list.SetItemText(i, 3, str);
		m_list.SetItemText(i, 4, Info[i].m_grade.c_str());

	}
}


void CBarershopmembermanagementDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_list.GetSelectionMark();
	if (index == -1)
	{
		MessageBox(TEXT("请先选择要删除的数据！"), TEXT("提示"));
		return;
	}
	else
	{
		UINT i;
		i = MessageBox(_T("确定要删除这条信息吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			if (SQL.Del_Info(Info[index]))
			{
				MessageBox(TEXT("删除成功！"), TEXT("提示"));
				Info.erase(Info.begin() + index);
				UpdateList();
			}
		}
	}
}


void CBarershopmembermanagementDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CBarershopmembermanagementDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	int num = 0;
	double sum = 0;
	int current_sex = m_sex.GetCurSel();
	int current_grade = m_grade.GetCurSel();
	vector<double> moneys;
	for (int i = 0; i < Info.size(); i++)
	{
		if (current_sex == 0&& current_grade==0)
		{
			if (Info[i].m_sex == TEXT("男")&&Info[i].m_grade==TEXT("VIP"))
			{
				moneys.push_back(Info[i].m_balance);
			}
		}
		if (current_sex == 0 && current_grade == 1)
		{
			if (Info[i].m_sex == TEXT("男") && Info[i].m_grade == TEXT("SVIP"))
			{
				moneys.push_back(Info[i].m_balance);
			}
		}
		if (current_sex == 0 && current_grade == 2)
		{
			if (Info[i].m_sex == TEXT("男") && Info[i].m_grade == TEXT("SVIP+"))
			{
				moneys.push_back(Info[i].m_balance);
			}
		}
		if (current_sex == 0 && current_grade == 3)
		{
			if (Info[i].m_sex == TEXT("男"))
			{
				moneys.push_back(Info[i].m_balance);
			}
		}
		if (current_sex == 1 && current_grade == 0)
		{
			if (Info[i].m_sex == TEXT("女") && Info[i].m_grade == TEXT("VIP"))
			{
				moneys.push_back(Info[i].m_balance);
			}
		}
		if (current_sex == 1 && current_grade == 1)
		{
			if (Info[i].m_sex == TEXT("女") && Info[i].m_grade == TEXT("SVIP"))
			{
				moneys.push_back(Info[i].m_balance);
			}
		}
		if (current_sex == 1 && current_grade == 2)
		{
			if (Info[i].m_sex == TEXT("女") && Info[i].m_grade == TEXT("SVIP+"))
			{
				moneys.push_back(Info[i].m_balance);
			}
		}
		if (current_sex == 1 && current_grade == 3)
		{
			if (Info[i].m_sex == TEXT("女"))
			{
				moneys.push_back(Info[i].m_balance);
			}
		}
		if (current_sex == 2 && current_grade == 0)
		{
			if (Info[i].m_grade == TEXT("VIP"))
			{
				moneys.push_back(Info[i].m_balance);
			}
		}
		if (current_sex == 2 && current_grade == 1)
		{
			if (Info[i].m_grade == TEXT("SVIP"))
			{
				moneys.push_back(Info[i].m_balance);
			}
		}
		if (current_sex == 2 && current_grade == 2)
		{
			if (Info[i].m_grade == TEXT("SVIP+"))
			{
				moneys.push_back(Info[i].m_balance);
			}
		}
		if (current_sex == 2 && current_grade == 3)
		{
				moneys.push_back(Info[i].m_balance);
		}
	}
	num = moneys.size();
	for (int i = 0; i < moneys.size(); i++)
	{
		sum += moneys[i];
	}
	m_aver.Format(TEXT("%.2lf"), sum / num);
	m_sum = sum;
	m_num = num;
	UpdateData(FALSE);
}
bool cmp1(MemberInfo a, MemberInfo b)
{
	return a.m_balance > b.m_balance;
}

bool cmp2(MemberInfo a, MemberInfo b)
{
	return a.m_balance < b.m_balance;
}

bool cmp3(MemberInfo a, MemberInfo b)
{
	return a.m_grade > b.m_grade;
}
bool cmp4(MemberInfo a, MemberInfo b)
{
	return a.m_sex > b.m_sex;
}
void CBarershopmembermanagementDlg::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
	int rule1 = m_rule1.GetCurSel();
	if (rule1 == 0)
	{
		sort(Info.begin(), Info.end(), cmp1);
	}
	if (rule1 == 1)
	{
		sort(Info.begin(), Info.end(), cmp2);
	}
	if (rule1 == 2)
	{
		sort(Info.begin(), Info.end(), cmp3);
	}
	if (rule1 == 3)
	{
		sort(Info.begin(), Info.end(), cmp4);
	}
	UpdateList();
}


void CBarershopmembermanagementDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_list.GetSelectionMark();
	if (index == -1)
	{
		MessageBox(TEXT("请先选择要充值的会员！"), TEXT("提示"));
		return;
	}
	else
	{
		ChildDlg2 dlg;
		infoDlg dlg2;
		if (dlg.DoModal()==IDOK)
		{
			if (SQL.Update_info(Info[index], MemberInfo(Info[index].m_phone, Info[index].m_name, Info[index].m_sex, Info[index].m_balance +dlg.m_chongzhi, Info[index].m_grade)))
			{
				MessageBox(TEXT("充值成功！"), TEXT("提示"));
				Info[index].m_balance = Info[index].m_balance + dlg.m_chongzhi;
				UpdateList();
			}
		}

	}
}


void CBarershopmembermanagementDlg::OnCbnSelchangeCombo4()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CBarershopmembermanagementDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	int current_ctype = m_ctype.GetCurSel();
	if (current_ctype == 0)
	{
		Childc1 dlg;
		if (dlg.DoModal())
		{
			vector<MemberInfo> result = SQL.Seek_info1(dlg.m_name1);
			if (result.empty())
			{
				MessageBox(TEXT("没有查询到该会员"), TEXT("提示"));
				return;
			}
			m_list.DeleteAllItems();
			CString str;
			for (int i = 0; i < result.size(); i++)
			{
				m_list.InsertItem(i, result[i].m_phone.c_str());
				m_list.SetItemText(i, 1, result[i].m_name.c_str());
				m_list.SetItemText(i, 2, result[i].m_sex.c_str());
				str.Format(TEXT("%.1lf"), result[i].m_balance);
				m_list.SetItemText(i, 3, str);
				m_list.SetItemText(i, 4, result[i].m_grade.c_str());

			}
		}
	}
	if (current_ctype == 1)
	{
		Childc2 dlg;
		if (dlg.DoModal())
		{
			vector<MemberInfo> result = SQL.Seek_info2(dlg.m_phone1);
			if (result.empty())
			{
				MessageBox(TEXT("没有查询到该会员"), TEXT("提示"));
				return;
			}
			m_list.DeleteAllItems();
			CString str;
			for (int i = 0; i < result.size(); i++)
			{
				m_list.InsertItem(i, result[i].m_phone.c_str());
				m_list.SetItemText(i, 1, result[i].m_name.c_str());
				m_list.SetItemText(i, 2, result[i].m_sex.c_str());
				str.Format(TEXT("%.1lf"), result[i].m_balance);
				m_list.SetItemText(i, 3, str);
				m_list.SetItemText(i, 4, result[i].m_grade.c_str());

			}
		}
	}
	if (current_ctype == 2)
	{
		Childc3 dlg;
		if (dlg.DoModal())
		{
			vector<MemberInfo> result = SQL.Seek_info3(dlg.m_sex1);
			if (result.empty())
			{
				MessageBox(TEXT("没有查询到该会员"), TEXT("提示"));
				return;
			}
			m_list.DeleteAllItems();
			CString str;
			for (int i = 0; i < result.size(); i++)
			{
				m_list.InsertItem(i, result[i].m_phone.c_str());
				m_list.SetItemText(i, 1, result[i].m_name.c_str());
				m_list.SetItemText(i, 2, result[i].m_sex.c_str());
				str.Format(TEXT("%.1lf"), result[i].m_balance);
				m_list.SetItemText(i, 3, str);
				m_list.SetItemText(i, 4, result[i].m_grade.c_str());

			}
		}
	}
}


void CBarershopmembermanagementDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CBarershopmembermanagementDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}
