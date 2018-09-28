// ScoreDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainFrm.h"
#include "��ѧ�������.h"
#include "ScoreDlg.h"
#include "afxdialogex.h"
#include "��ѧ�������Doc.h"
#include "��ѧ�������View.h"


// ScoreDlg �Ի���

IMPLEMENT_DYNAMIC(ScoreDlg, CDialogEx)

ScoreDlg::ScoreDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ScoreDlg::IDD, pParent)
{
	thiscourse="";
}

ScoreDlg::~ScoreDlg()
{
}

void ScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_COURSE, CB_Course);
	DDX_Text(pDX,IDC_SCORE_STUDENT_NUMBER,studentnumber);
	DDX_Text(pDX,IDC_SCORE_SCORE,thisscore);
}


BEGIN_MESSAGE_MAP(ScoreDlg, CDialogEx)
	ON_BN_CLICKED(IDC_UPDATE, &ScoreDlg::OnBnClickedUpdate)
	ON_BN_CLICKED(IDOK, &ScoreDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ScoreDlg ��Ϣ�������


void ScoreDlg::OnBnClickedUpdate()
{
	UpdateData(1);
	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C��ѧ�������View *pView=(C��ѧ�������View *)pMain->GetActiveView();
	C��ѧ�������Doc *pDoc=(C��ѧ�������Doc *)pView->GetDocument(); 
	POSITION pos;
	CStudent *pStu=NULL;
	CB_Course.ResetContent();
	for(int i=0;i<(pDoc->data_table).data_student.GetCount();i++)
	{
		pos=pDoc->data_table.data_student.FindIndex(i);
		pStu=&((pDoc->data_table).data_student.GetAt(pos));
		if(studentnumber==(pStu->student_number))
			break;
	}
	for(int i=0;i<5;i++)
	{
		if(pStu->course[i]!="")
			CB_Course.InsertString(i,pStu->course[i]);
	}
	UpdateData(0);

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL ScoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void ScoreDlg::OnBnClickedOk()
{
	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C��ѧ�������View *pView=(C��ѧ�������View *)pMain->GetActiveView();
	C��ѧ�������Doc *pDoc=(C��ѧ�������Doc *)pView->GetDocument(); 
	POSITION pos;
	CStudent *pStu=NULL;
	for(int i=0;i<(pDoc->data_table).data_student.GetCount();i++)
	{
		pos=(pDoc->data_table).data_student.FindIndex(i);
        pStu=&((pDoc->data_table).data_student.GetAt(pos));
		if(pStu->getstudent_number()==studentnumber)
			break;
	}
	CString CunText;
	CB_Course.GetLBText((CB_Course.GetCurSel()),CunText);
	int i=0;
	for(;i<5;i++)
	{
		if(CunText==pStu->course[i])
			break;
	}
	UpdateData(1);
	pStu->course_score[i]=_ttof(thisscore);
	pView->OnShow();
	CDialogEx::OnOK();
}
