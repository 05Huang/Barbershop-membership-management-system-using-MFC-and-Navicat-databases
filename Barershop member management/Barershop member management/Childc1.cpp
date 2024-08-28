// Childc1.cpp: 实现文件
//

#include "pch.h"
#include "Barershop member management.h"
#include "afxdialogex.h"
#include "Childc1.h"


// Childc1 对话框

IMPLEMENT_DYNAMIC(Childc1, CDialogEx)

Childc1::Childc1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Childc1, pParent)
	, m_name1(_T(""))
{

}

Childc1::~Childc1()
{
}

void Childc1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name1);
}


BEGIN_MESSAGE_MAP(Childc1, CDialogEx)
	ON_BN_CLICKED(IDOK, &Childc1::OnBnClickedOk)
END_MESSAGE_MAP()


// Childc1 消息处理程序


void Childc1::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_name1 == TEXT(""))
	{
		MessageBox(TEXT("输入不能为空"), TEXT("提示"));
		return;
	}
	CDialogEx::OnOK();
}
