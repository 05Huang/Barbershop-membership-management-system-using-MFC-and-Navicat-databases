
// Barershop member managementDlg.h: 头文件
//
#include "SQLInterface.h"
#pragma once


// CBarershopmembermanagementDlg 对话框
class CBarershopmembermanagementDlg : public CDialogEx
{
// 构造
public:
	CBarershopmembermanagementDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BARERSHOP_MEMBER_MANAGEMENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	SQLInterface SQL;
	vector<MemberInfo> Info;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	CListCtrl m_list;
	afx_msg void OnBnClickedButton2();
	void UpdateList();
	afx_msg void OnBnClickedButton3();
	CComboBox m_sex;
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox m_grade;
	CString m_aver;
	double m_sum;
	int m_num;
	afx_msg void OnBnClickedButton6();
	CComboBox m_rule1;
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnCbnSelchangeCombo4();
	CComboBox m_ctype;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnCbnSelchangeCombo1();
};
