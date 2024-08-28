#pragma once
#include "afxdialogex.h"


// Childc2 对话框

class Childc2 : public CDialogEx
{
	DECLARE_DYNAMIC(Childc2)

public:
	Childc2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Childc2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Childc2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_phone1;
	afx_msg void OnBnClickedOk();
};
