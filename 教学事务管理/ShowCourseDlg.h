#pragma once
#include "afxwin.h"



// ShowCourseDlg �Ի���

class ShowCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShowCourseDlg)

public:
	ShowCourseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ShowCourseDlg();

// �Ի�������
	enum { IDD = IDD_SHOW_COURSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox Combox_Course;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
