// ChooseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ѧ�������.h"
#include "ChooseDlg.h"
#include "afxdialogex.h"


// ChooseDlg �Ի���

IMPLEMENT_DYNAMIC(ChooseDlg, CDialogEx)

ChooseDlg::ChooseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ChooseDlg::IDD, pParent)
{

}

ChooseDlg::~ChooseDlg()
{
}

void ChooseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_CHOOSE_STUDENT_NUMBER,studentnumber);
	DDX_Text(pDX,IDC_CHOOSE_COURSE,coursenumber);
}


BEGIN_MESSAGE_MAP(ChooseDlg, CDialogEx)
END_MESSAGE_MAP()


// ChooseDlg ��Ϣ�������
