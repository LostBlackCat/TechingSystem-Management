#pragma once


// SignDlg �Ի���

class SignDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SignDlg)

public:
	SignDlg(CWnd* pParent = NULL);// ��׼���캯��
	CString s_name;
	CString s_student_number;
	CString s_class;
	virtual ~SignDlg();

// �Ի�������
	enum { IDD = IDD_SIGN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
