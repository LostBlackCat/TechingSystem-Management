#pragma once
#include "afxwin.h"


// ScoreDlg �Ի���

class ScoreDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ScoreDlg)

public:
	ScoreDlg(CWnd* pParent = NULL);   // ��׼���캯��
	CString studentnumber;
	CString thiscourse;
	CString thisscore;
	virtual ~ScoreDlg();

// �Ի�������
	enum { IDD = IDD_Score };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox CB_Course;
	afx_msg void OnBnClickedUpdate();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
