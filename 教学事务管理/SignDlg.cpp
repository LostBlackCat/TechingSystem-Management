// SignDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ѧ�������.h"
#include "SignDlg.h"
#include "afxdialogex.h"


// SignDlg �Ի���

IMPLEMENT_DYNAMIC(SignDlg, CDialogEx)

SignDlg::SignDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SignDlg::IDD, pParent)
{
	s_name="xxx";
	s_student_number="0000";
	s_class="00";
}

SignDlg::~SignDlg()
{
}

void SignDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_SIGN_NAME,s_name);
	DDX_Text(pDX,IDC_SIGN_STUDENT_NUMBER,s_student_number);
	DDX_Text(pDX,IDC_SIGN_CLASS,s_class);
}


BEGIN_MESSAGE_MAP(SignDlg, CDialogEx)
END_MESSAGE_MAP()


// SignDlg ��Ϣ�������
