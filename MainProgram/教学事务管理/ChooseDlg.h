#pragma once


// ChooseDlg �Ի���

class ChooseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChooseDlg)

public:
	ChooseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	CString studentnumber;
	CString coursenumber;
	virtual ~ChooseDlg();

// �Ի�������
	enum { IDD = IDD_CHOOSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
