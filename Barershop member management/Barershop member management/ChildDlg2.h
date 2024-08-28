#pragma once
#include "afxdialogex.h"


// ChildDlg2 对话框

class ChildDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(ChildDlg2)

public:
	ChildDlg2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChildDlg2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Child2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_chongzhi;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
};
