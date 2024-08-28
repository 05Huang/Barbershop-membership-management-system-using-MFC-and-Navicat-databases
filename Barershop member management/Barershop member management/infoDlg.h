#pragma once
#include "afxdialogex.h"


// infoDlg 对话框

class infoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(infoDlg)

public:
	infoDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~infoDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_infoDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_phone;
	CString m_name;
	CString m_sex;
	double m_balance;
	CString m_grade;
	afx_msg void OnBnClickedOk();
};
