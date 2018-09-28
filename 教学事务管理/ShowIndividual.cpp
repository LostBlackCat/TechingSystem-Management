// ShowIndividual.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainFrm.h"
#include "��ѧ�������.h"
#include "afxdialogex.h"
#include "��ѧ�������Doc.h"
#include "��ѧ�������View.h"
#include "ShowIndividual.h"

// ShowIndividual �Ի���

IMPLEMENT_DYNAMIC(ShowIndividual, CDialogEx)

ShowIndividual::ShowIndividual(CWnd* pParent /*=NULL*/)
	: CDialogEx(ShowIndividual::IDD, pParent)
{

}

ShowIndividual::~ShowIndividual()
{
}

void ShowIndividual::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STUDENT_NUMBER, CB_Student);
}


BEGIN_MESSAGE_MAP(ShowIndividual, CDialogEx)
	ON_BN_CLICKED(IDOK, &ShowIndividual::OnBnClickedOk)
END_MESSAGE_MAP()


// ShowIndividual ��Ϣ�������


BOOL ShowIndividual::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C��ѧ�������View *pView=(C��ѧ�������View *)pMain->GetActiveView();
	C��ѧ�������Doc *pDoc=(C��ѧ�������Doc *)pView->GetDocument(); 
	
	POSITION pos;
	for(int i=0;i<pDoc->data_table.data_student.GetCount();i++)
	{
		pos=pDoc->data_table.data_student.FindIndex(i);
		CStudent* pStu=&(pDoc->data_table.data_student.GetAt(pos));
		CB_Student.AddString(pStu->student_number);
	}
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void ShowIndividual::OnBnClickedOk()
{
	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C��ѧ�������View *pView=(C��ѧ�������View *)pMain->GetActiveView();
	C��ѧ�������Doc *pDoc=(C��ѧ�������Doc *)pView->GetDocument();
	CString s_n;
	int n=CB_Student.GetCurSel();
	CB_Student.GetLBText(n,s_n);
	pView->ShowIndividualTable(s_n);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
