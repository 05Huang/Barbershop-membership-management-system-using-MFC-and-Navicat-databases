// Childc3.cpp: 实现文件
//

#include "pch.h"
#include "Barershop member management.h"
#include "afxdialogex.h"
#include "Childc3.h"


// Childc3 对话框

IMPLEMENT_DYNAMIC(Childc3, CDialogEx)

Childc3::Childc3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Childc3, pParent)
	, m_sex1(_T(""))
{

}

Childc3::~Childc3()
{
}

void Childc3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_sex1);
}


BEGIN_MESSAGE_MAP(Childc3, CDialogEx)
	ON_BN_CLICKED(IDOK, &Childc3::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &Childc3::OnEnChangeEdit1)
END_MESSAGE_MAP()


// Childc3 消息处理程序


void Childc3::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_sex1 == TEXT(""))
	{
		MessageBox(TEXT("输入不能为空"), TEXT("提示"));
		return;
	}
	CDialogEx::OnOK();
}


void Childc3::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
