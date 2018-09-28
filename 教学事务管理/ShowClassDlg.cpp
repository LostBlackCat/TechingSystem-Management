// ShowClassDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ѧ�������.h"
#include "ShowClassDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "��ѧ�������Doc.h"
#include "��ѧ�������View.h"
// ShowClassDlg �Ի���

IMPLEMENT_DYNAMIC(ShowClassDlg, CDialogEx)

ShowClassDlg::ShowClassDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ShowClassDlg::IDD, pParent)
{

}

ShowClassDlg::~ShowClassDlg()
{
}

void ShowClassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOW_CLASS, Combox_Course);
}


BEGIN_MESSAGE_MAP(ShowClassDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &ShowClassDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ShowClassDlg ��Ϣ�������


BOOL ShowClassDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C��ѧ�������View *pView=(C��ѧ�������View *)pMain->GetActiveView();
	C��ѧ�������Doc *pDoc=(C��ѧ�������Doc *)pView->GetDocument(); 
	CComboBox* pCom=((CComboBox*)GetDlgItem(IDC_SHOW_CLASS));
	for(int i=0;i<10;i++)
	{
		if(pDoc->data_table.AllClass[i]!="")
			pCom->AddString(pDoc->data_table.AllClass[i]);
	}
	UpdateData(0);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void ShowClassDlg::OnBnClickedOk()
{

	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C��ѧ�������View *pView=(C��ѧ�������View *)pMain->GetActiveView();
	C��ѧ�������Doc *pDoc=(C��ѧ�������Doc *)pView->GetDocument(); 
	CString getCombox;
	int nIndex=Combox_Course.GetCurSel();
	Combox_Course.GetLBText(nIndex,getCombox);
	pView->ShowClassTable(getCombox);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
