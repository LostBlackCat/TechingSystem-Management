// ShowCourseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MainFrm.h"
#include "教学事务管理.h"
#include "ShowFallDlg.h"
#include "afxdialogex.h"
#include "教学事务管理Doc.h"
#include "教学事务管理View.h"
#include "ShowCourseDlg.h"


// ShowCourseDlg 对话框

IMPLEMENT_DYNAMIC(ShowCourseDlg, CDialogEx)

ShowCourseDlg::ShowCourseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ShowCourseDlg::IDD, pParent)
{

}

ShowCourseDlg::~ShowCourseDlg()
{
}

void ShowCourseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, Combox_Course);
}


BEGIN_MESSAGE_MAP(ShowCourseDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &ShowCourseDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ShowCourseDlg 消息处理程序


BOOL ShowCourseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C教学事务管理View *pView=(C教学事务管理View *)pMain->GetActiveView();
	C教学事务管理Doc *pDoc=(C教学事务管理Doc *)pView->GetDocument(); 
	for(int i=0;i<10;i++)
	{
		if(pDoc->data_table.AllCourse[i]!="")
			Combox_Course.AddString(pDoc->data_table.AllCourse[i]);
	}
	UpdateData(0);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void ShowCourseDlg::OnBnClickedOk()
{
	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C教学事务管理View *pView=(C教学事务管理View *)pMain->GetActiveView();
	C教学事务管理Doc *pDoc=(C教学事务管理Doc *)pView->GetDocument(); 
	int nIntex=Combox_Course.GetCurSel();
	CString combox;
	Combox_Course.GetLBText(nIntex,combox);
	pView->ShowCourseTable(combox);

	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
