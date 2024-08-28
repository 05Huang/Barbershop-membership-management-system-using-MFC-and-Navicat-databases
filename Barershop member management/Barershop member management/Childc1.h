#pragma once
#include "afxdialogex.h"


// Childc1 对话框

class Childc1 : public CDialogEx
{
	DECLARE_DYNAMIC(Childc1)

public:
	Childc1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Childc1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Childc1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_name1;
	afx_msg void OnBnClickedOk();
};
