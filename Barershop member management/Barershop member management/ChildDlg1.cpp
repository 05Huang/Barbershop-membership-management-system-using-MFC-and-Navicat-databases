// ChildDlg1.cpp: 实现文件
//

#include "pch.h"
#include "Barershop member management.h"
#include "afxdialogex.h"
#include "ChildDlg1.h"


// ChildDlg1 对话框

IMPLEMENT_DYNAMIC(ChildDlg1, CDialogEx)

ChildDlg1::ChildDlg1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Child1, pParent)
	, m_money(0)
{

}

ChildDlg1::~ChildDlg1()
{
}

void ChildDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_money);
}


BEGIN_MESSAGE_MAP(ChildDlg1, CDialogEx)
	ON_BN_CLICKED(IDOK, &ChildDlg1::OnBnClickedOk)
END_MESSAGE_MAP()


// ChildDlg1 消息处理程序


void ChildDlg1::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_money <= 0)
	{
		MessageBox(TEXT("消费金额不可以小于0，请重新输入"), TEXT("提示"));
	}
	else
	{

		OnOK();
		return;
	}
}
