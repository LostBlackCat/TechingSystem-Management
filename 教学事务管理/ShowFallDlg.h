#pragma once
#include "afxwin.h"


// ShowFallDlg �Ի���

class ShowFallDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShowFallDlg)

public:
	ShowFallDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ShowFallDlg();

// �Ի�������
	enum { IDD = IDD_SHOW_FALL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox Combox_Course;
	afx_msg void OnBnClickedOk();
};
