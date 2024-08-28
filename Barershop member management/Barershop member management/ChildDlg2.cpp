// ChildDlg2.cpp: 实现文件
//

#include "pch.h"
#include "Barershop member management.h"
#include "afxdialogex.h"
#include "ChildDlg2.h"


// ChildDlg2 对话框

IMPLEMENT_DYNAMIC(ChildDlg2, CDialogEx)

ChildDlg2::ChildDlg2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Child2, pParent)
	, m_chongzhi(0)
{

}

ChildDlg2::~ChildDlg2()
{
}

void ChildDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_chongzhi);
}


BEGIN_MESSAGE_MAP(ChildDlg2, CDialogEx)
	ON_BN_CLICKED(IDOK, &ChildDlg2::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &ChildDlg2::OnEnChangeEdit1)
END_MESSAGE_MAP()


// ChildDlg2 消息处理程序


void ChildDlg2::OnBnClickedOk()
{
	UpdateData(TRUE);
	if (m_chongzhi <= 0)
	{
		MessageBox(TEXT("充值金额不可以小于0，请重新输入"), TEXT("提示"));
	}
	else
	{

		OnOK();
		return;
	}
	// TODO: 在此添加控件通知处理程序代码
}


void ChildDlg2::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
