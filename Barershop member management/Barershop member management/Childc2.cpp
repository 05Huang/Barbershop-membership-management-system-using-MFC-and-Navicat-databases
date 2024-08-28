// Childc2.cpp: 实现文件
//

#include "pch.h"
#include "Barershop member management.h"
#include "afxdialogex.h"
#include "Childc2.h"


// Childc2 对话框

IMPLEMENT_DYNAMIC(Childc2, CDialogEx)

Childc2::Childc2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Childc2, pParent)
	, m_phone1(_T(""))
{

}

Childc2::~Childc2()
{
}

void Childc2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_phone1);
}


BEGIN_MESSAGE_MAP(Childc2, CDialogEx)
	ON_BN_CLICKED(IDOK, &Childc2::OnBnClickedOk)
END_MESSAGE_MAP()


// Childc2 消息处理程序


void Childc2::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_phone1 == TEXT(""))
	{
		MessageBox(TEXT("输入不能为空"), TEXT("提示"));
		return;
	}
	CDialogEx::OnOK();
}
