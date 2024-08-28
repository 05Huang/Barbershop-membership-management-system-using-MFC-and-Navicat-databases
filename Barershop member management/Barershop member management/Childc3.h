#pragma once
#include "afxdialogex.h"


// Childc3 对话框

class Childc3 : public CDialogEx
{
	DECLARE_DYNAMIC(Childc3)

public:
	Childc3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Childc3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Childc3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_sex1;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
};
