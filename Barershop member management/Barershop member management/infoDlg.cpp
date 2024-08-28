// infoDlg.cpp: 实现文件
//

#include "pch.h"
#include "Barershop member management.h"
#include "afxdialogex.h"
#include "infoDlg.h"


// infoDlg 对话框

IMPLEMENT_DYNAMIC(infoDlg, CDialogEx)

infoDlg::infoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_infoDlg, pParent)
	, m_phone(_T(""))
	, m_name(_T(""))
	, m_sex(_T(""))
	, m_balance(0)
	, m_grade(_T(""))
{

}

infoDlg::~infoDlg()
{
}

void infoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_phone);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_sex);
	DDX_Text(pDX, IDC_EDIT4, m_balance);
	DDX_Text(pDX, IDC_EDIT5, m_grade);
}


BEGIN_MESSAGE_MAP(infoDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &infoDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// infoDlg 消息处理程序

bool CheckPhoneNumberLength(LPCTSTR phoneNumber)
{
	int length = _tcslen(phoneNumber);
	// 检查手机号是否为11位数字
	return length == 11 && _istdigit(phoneNumber[0]);
}

void infoDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	infoDlg dlg;
	if (m_phone == TEXT("") || m_sex == TEXT("") || m_name == TEXT(""))
	{
		MessageBox(TEXT("您有输入为空，请补全完整"), TEXT("提示"));
	}
	else  if (CheckPhoneNumberLength(dlg.m_phone.GetBuffer()))
	{
		MessageBox(TEXT("手机号必须为11位数字，请重新输入"), TEXT("提示"));
	}
	else if (m_sex != TEXT("男") && m_sex != TEXT("女"))
	{
		MessageBox(TEXT("性别输入错误，请重新输入"), TEXT("提示"));
	}
	else if (m_balance < 0)
	{
		MessageBox(TEXT("充值金额不能小于0，请重新输入"), TEXT("提示"));
	}
	else
	{
		OnOK();
		return;
	}
	
	
}
