// ShowFallDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainFrm.h"
#include "��ѧ�������.h"
#include "ShowFallDlg.h"
#include "afxdialogex.h"
#include "��ѧ�������Doc.h"
#include "��ѧ�������View.h"


// ShowFallDlg �Ի���

IMPLEMENT_DYNAMIC(ShowFallDlg, CDialogEx)

ShowFallDlg::ShowFallDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ShowFallDlg::IDD, pParent)
{

}

ShowFallDlg::~ShowFallDlg()
{
}

void ShowFallDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, Combox_Course);
}


BEGIN_MESSAGE_MAP(ShowFallDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &ShowFallDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ShowFallDlg ��Ϣ�������


BOOL ShowFallDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C��ѧ�������View *pView=(C��ѧ�������View *)pMain->GetActiveView();
	C��ѧ�������Doc *pDoc=(C��ѧ�������Doc *)pView->GetDocument(); 
	for(int i=0;i<10;i++)
	{
		if(pDoc->data_table.AllCourse[i]!="")
			Combox_Course.AddString(pDoc->data_table.AllCourse[i]);
	}
	UpdateData(0);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void ShowFallDlg::OnBnClickedOk()
{
	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C��ѧ�������View *pView=(C��ѧ�������View *)pMain->GetActiveView();
	C��ѧ�������Doc *pDoc=(C��ѧ�������Doc *)pView->GetDocument(); 
	int nIntex=Combox_Course.GetCurSel();
	CString combox;
	Combox_Course.GetLBText(nIntex,combox);
	pView->ShowFallTable(combox);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
