#pragma once
#include "afxdialogex.h"


// ChildDlg1 对话框

class ChildDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(ChildDlg1)

public:
	ChildDlg1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChildDlg1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Child1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_money;
	afx_msg void OnBnClickedOk();
};
