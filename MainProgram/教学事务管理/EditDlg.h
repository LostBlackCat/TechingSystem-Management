#pragma once


// EditDlg �Ի���

class EditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EditDlg)

public:
	EditDlg(CWnd* pParent = NULL);// ��׼���캯��
	CString studentnumber;
	CString Edit_Name;
	CString Edit_class;
	virtual ~EditDlg();

// �Ի�������
	enum { IDD = IDD_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
