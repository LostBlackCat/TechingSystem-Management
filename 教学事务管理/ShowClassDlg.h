#pragma once
#include "afxwin.h"


// ShowClassDlg �Ի���

class ShowClassDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShowClassDlg)

public:
	ShowClassDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ShowClassDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox Combox_Course;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
