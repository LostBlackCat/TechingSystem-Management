#pragma once
#include "afxwin.h"


// ShowIndividual �Ի���

class ShowIndividual : public CDialogEx
{
	DECLARE_DYNAMIC(ShowIndividual)

public:
	ShowIndividual(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ShowIndividual();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox CB_Student;
	afx_msg void OnBnClickedOk();
};
