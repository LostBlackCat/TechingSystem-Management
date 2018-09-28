
// ��ѧ�������View.cpp : C��ѧ�������View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ѧ�������.h"
#endif

#include "��ѧ�������Doc.h"
#include "��ѧ�������View.h"
#include "SignDlg.h"
#include "EditDlg.h"
#include "ScoreDlg.h";
#include "ChooseDlg.h"
#include "Student.h"
#include "ShowClassDlg.h"
#include "ShowFallDlg.h"
#include "ShowCourseDlg.h"
#include "ShowIndividual.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ѧ�������View

IMPLEMENT_DYNCREATE(C��ѧ�������View, CListView)

BEGIN_MESSAGE_MAP(C��ѧ�������View, CListView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_EDIT, &C��ѧ�������View::OnEdit)
	ON_COMMAND(ID_SHOW, &C��ѧ�������View::OnShow)
	ON_COMMAND(ID_CHOOSE, &C��ѧ�������View::OnChoose)
	ON_COMMAND(ID_SCORE, &C��ѧ�������View::OnScore)
	ON_COMMAND(ID_SHOW_COURSE, &C��ѧ�������View::OnShowCourse)
	ON_COMMAND(ID_SHOW_CLASS, &C��ѧ�������View::OnShowClass)
	ON_COMMAND(ID_SHOW_FALL, &C��ѧ�������View::OnShowFall)
	ON_COMMAND(ID_SHOW_STUDENT, &C��ѧ�������View::OnShowStudent)
	ON_COMMAND(ID_ShowAverage, &C��ѧ�������View::OnShowaverage)
END_MESSAGE_MAP()

// C��ѧ�������View ����/����

C��ѧ�������View::C��ѧ�������View()
{
	// TODO: �ڴ˴���ӹ������

}

C��ѧ�������View::~C��ѧ�������View()
{
}

BOOL C��ѧ�������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	cs.style |= LVS_SHOWSELALWAYS | LVS_REPORT;
	return CListView::PreCreateWindow(cs);
}

void C��ѧ�������View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: ���� GetListCtrl() ֱ�ӷ��� ListView ���б�ؼ���
	//  �Ӷ������������ ListView��
}

void C��ѧ�������View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C��ѧ�������View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C��ѧ�������View ���

#ifdef _DEBUG
void C��ѧ�������View::AssertValid() const
{
	CListView::AssertValid();
}

void C��ѧ�������View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

C��ѧ�������Doc* C��ѧ�������View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ѧ�������Doc)));
	return (C��ѧ�������Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ѧ�������View ��Ϣ�������




void C��ѧ�������View::OnEdit()
{
	EditDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		POSITION pos;
	    C��ѧ�������Doc* pDoc=(C��ѧ�������Doc* )GetDocument();
		CStudent* pStu=NULL;
		for(int i=0;i<(pDoc->data_table).data_student.GetCount();i++)
		{
			pos=(pDoc->data_table).data_student.FindIndex(i);
            pStu=&((pDoc->data_table).data_student.GetAt(pos));
			if(pStu->getstudent_number()==dlg.studentnumber)	
			{
				if(dlg.Edit_Name=="")
		        {
			          dlg.MessageBox("��ɾ����ѧ�ŵ�ѧ��������");
			          pDoc->data_table.data_student.RemoveAt(pos);
		        }
		        else
		        {
		              pStu->setName(dlg.Edit_Name);
		              pStu->setclass_number(dlg.Edit_class);
		        }
			}
			if(i==((pDoc->data_table).data_student.GetCount())-1&&pStu->getstudent_number()!=dlg.studentnumber)
			{
				dlg.MessageBox("δ�ҵ���ѧ��");
			}
		}
		
		OnShow();
	}

	// TODO: �ڴ���������������
}

void C��ѧ�������View::OnShow()
{
	CListCtrl& ListCtrl = GetListCtrl();
	while(ListCtrl.DeleteColumn(0)){};
	ListCtrl.DeleteAllItems();

	ListCtrl.InsertColumn(0,"Student Number");
	ListCtrl.SetColumnWidth(0,150);
	ListCtrl.InsertColumn(1,"Name");
	ListCtrl.SetColumnWidth(1,200);
	ListCtrl.InsertColumn(2,"Class");
	ListCtrl.SetColumnWidth(2,100);
	ListCtrl.InsertColumn(3,"Current Course");
	ListCtrl.SetColumnWidth(3,400);
	ListCtrl.InsertColumn(4,"Score");
	ListCtrl.SetColumnWidth(4,400);

	POSITION pos;
	C��ѧ�������Doc* pDoc=(C��ѧ�������Doc* )GetDocument();
	for(int i=0;i<(pDoc->data_table).data_student.GetCount();i++)
	{
		pos=(pDoc->data_table).data_student.FindIndex(i);
		ListCtrl.InsertItem(i,"");
		for(int j=0;j<5;j++)
		{
			if(j==0)
			{
				CStudent* pStu=&((pDoc->data_table).data_student.GetAt(pos));
				CString pSn=pStu->student_number;
				ListCtrl.SetItemText(i,j,pSn);
				
			}
			if(j==1)
			{
				CStudent* pStu=&((pDoc->data_table).data_student.GetAt(pos));
				CString pSn=pStu->Name;
				ListCtrl.SetItemText(i,j,pSn);
			}
			if(j==2)
			{
				CStudent* pStu=&((pDoc->data_table).data_student.GetAt(pos));
				CString pSn=pStu->class_number;
				ListCtrl.SetItemText(i,j,pSn);
			}
			if(j==3)
			{
				CStudent* pStu=&((pDoc->data_table).data_student.GetAt(pos));
				CString pSn="";
				for(int n=0;n<5;n++)
					pSn=(pSn+pStu->course[n])+" / " ;
				ListCtrl.SetItemText(i,j,pSn);
			}
			if(j==4)
			{
				CStudent* pStu=&((pDoc->data_table).data_student.GetAt(pos));
				CString pSn="";
				for(int n=0;n<5;n++)
				{
					CString tem="";
					if(pStu->course_score[n]!=-1)
					{
					    tem.Format(_T("%.2f"),(pStu->course_score[n]));
					}
					pSn=pSn+tem+" / ";
				}
				ListCtrl.SetItemText(i,j,pSn);
			}
		}
	}
}




void C��ѧ�������View::OnChoose()
{
	ChooseDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		POSITION pos;
	    C��ѧ�������Doc* pDoc=(C��ѧ�������Doc* )GetDocument();
		CStudent* pStu=NULL;
		for(int i=0;i<(pDoc->data_table).data_student.GetCount();i++)
		{
			pos=(pDoc->data_table).data_student.FindIndex(i);
            pStu=&((pDoc->data_table).data_student.GetAt(pos));
			if(pStu->getstudent_number()==dlg.studentnumber)
			{
				bool ifin=true;
				for(int i=0;i<5;i++)
				{
					if(dlg.coursenumber!=""&&dlg.coursenumber==pStu->course[i])
					{
						dlg.MessageBox("��ѧ����ѡ�˿�");
						ifin=false;
					}
				}
				if(ifin)
				    pStu->setcourse(dlg.coursenumber);
		        for(int i=0;i<10;i++)
		        {
					
			        if(dlg.coursenumber!=""&&dlg.coursenumber==pDoc->data_table.AllCourse[i])
				        break;
			        if(dlg.coursenumber!=pDoc->data_table.AllCourse[i]&&pDoc->data_table.AllCourse[i]=="")
			        {
				        pDoc->data_table.AllCourse[i]=dlg.coursenumber;
				        break;
			        }
		        }
				break;
			}
			if(i==((pDoc->data_table).data_student.GetCount())-1&&pStu->getstudent_number()!=dlg.studentnumber)
			{
				dlg.MessageBox("δ�ҵ���ѧ��");
			}
		}
		
		OnShow();
	}
	// TODO: �ڴ���������������
}


void C��ѧ�������View::OnScore()
{
	ScoreDlg dlg;
	dlg.DoModal();
}



void C��ѧ�������View::OnShowCourse()
{
	ShowCourseDlg dlg;
	dlg.DoModal();
	// TODO: �ڴ���������������
}

void C��ѧ�������View::OnShowClass()
{
	ShowClassDlg dlg;
	dlg.DoModal();
	// TODO: �ڴ���������������
}


void C��ѧ�������View::ShowClassTable(CString class_name)
{
	CListCtrl& ListCtrl = GetListCtrl();
	while(ListCtrl.DeleteColumn(0)){};
	ListCtrl.DeleteAllItems();

	ListCtrl.InsertColumn(0,"Student Number");
	ListCtrl.SetColumnWidth(0,150);
	ListCtrl.InsertColumn(1,"Name");
	ListCtrl.SetColumnWidth(1,200);
	ListCtrl.InsertColumn(2,"Class");
	ListCtrl.SetColumnWidth(2,100);
	ListCtrl.InsertColumn(3,"Current Course");
	ListCtrl.SetColumnWidth(3,400);
	ListCtrl.InsertColumn(4,"Score");
	ListCtrl.SetColumnWidth(4,400);

	POSITION pos;
	C��ѧ�������Doc* pDoc=(C��ѧ�������Doc* )GetDocument();
    CStudent* pStu=NULL;
	int n=0;
	for(int i=0;i<(pDoc->data_table).data_student.GetCount();i++)
	{
		pos=(pDoc->data_table).data_student.FindIndex(i);
        pStu=&((pDoc->data_table).data_student.GetAt(pos));
		if(pStu->class_number==class_name)
		{
			ListCtrl.InsertItem(n,"");
		    for(int j=0;j<5;j++)
		    {
			    if(j==0)
			    {
				    CString pSn=pStu->student_number;
				    ListCtrl.SetItemText(n,j,pSn);
				
			    }
			    if(j==1)
			    {
				    CString pSn=pStu->Name;
				    ListCtrl.SetItemText(n,j,pSn);
			    }
			    if(j==2)
			    {
				    CString pSn=pStu->class_number;
				    ListCtrl.SetItemText(n,j,pSn);
			    }
			    if(j==3)
			    {
				    CString pSn="";
				    for(int n=0;n<5;n++)
					     pSn=(pSn+pStu->course[n])+" / " ;
				    ListCtrl.SetItemText(n,j,pSn);
			    }
			    if(j==4)
			    {
				    CString pSn="";
				    for(int n=0;n<5;n++)
				    {
					    CString tem="";
					    if(pStu->course_score[n]!=-1)
					    {
					       tem.Format(_T("%.2f"),(pStu->course_score[n]));
					    }
					    pSn=pSn+tem+" / ";
				    }
				    ListCtrl.SetItemText(n,j,pSn);
			    }
		    }
			n++;
		}

	}



}


void C��ѧ�������View::OnShowFall()
{
	ShowFallDlg dlg;
	dlg.DoModal();
	// TODO: �ڴ���������������
}


void C��ѧ�������View::ShowFallTable(CString course_name)
{
	CListCtrl& ListCtrl = GetListCtrl();
	while(ListCtrl.DeleteColumn(0)){};
	ListCtrl.DeleteAllItems();

	ListCtrl.InsertColumn(0,"Student Number");
	ListCtrl.SetColumnWidth(0,150);
	ListCtrl.InsertColumn(1,"Name");
	ListCtrl.SetColumnWidth(1,200);
	ListCtrl.InsertColumn(2,"Class");
	ListCtrl.SetColumnWidth(2,100);
	ListCtrl.InsertColumn(3,"Course");
	ListCtrl.SetColumnWidth(3,200);
	ListCtrl.InsertColumn(4,"Score");
	ListCtrl.SetColumnWidth(4,200);


	POSITION pos;
	C��ѧ�������Doc* pDoc=(C��ѧ�������Doc* )GetDocument();
    CStudent* pStu=NULL;
	int n=0;
	for(int i=0;i<(pDoc->data_table).data_student.GetCount();i++)
	{
		pos=(pDoc->data_table).data_student.FindIndex(i);
        pStu=&((pDoc->data_table).data_student.GetAt(pos));
		for(int j=0;j<5;j++)
		{
			if(pStu->course[j]!=""&&pStu->course[j]==course_name)
			{
				if(pStu->course_score[j]!=-1&&pStu->course_score[j]<60)
				{
					ListCtrl.InsertItem(n,"");
					for(int k=0;k<5;k++)
					{
						if(k==0)
			            {
				             CString pSn=pStu->student_number;
				             ListCtrl.SetItemText(n,k,pSn);
				
			            }
						if(k==1)
						{
							CString pSn=pStu->Name;
							ListCtrl.SetItemText(n,k,pSn);
						}
						if(k==2)
						{
							CString pSn=pStu->class_number;
							ListCtrl.SetItemText(n,k,pSn);
						}
						if(k==3)
						{
							CString pSn=pStu->course[j];
							ListCtrl.SetItemText(n,k,pSn);
						}
						if(k==4)
						{
							CString pSn="";
							pSn.Format(_T("%.2f"),(pStu->course_score[j]));
							ListCtrl.SetItemText(n,k,pSn);
						}
					}
					n++;
				}
			}
		}
	}
}




void C��ѧ�������View::ShowCourseTable(CString course_name)
{
	CListCtrl& ListCtrl = GetListCtrl();
	while(ListCtrl.DeleteColumn(0)){};
	ListCtrl.DeleteAllItems();

	ListCtrl.InsertColumn(0,"Student Number");
	ListCtrl.SetColumnWidth(0,200);
	ListCtrl.InsertColumn(1,"Name");
	ListCtrl.SetColumnWidth(1,100);
	ListCtrl.InsertColumn(2,"Class");
	ListCtrl.SetColumnWidth(2,200);
	ListCtrl.InsertColumn(3,"Score");
	ListCtrl.SetColumnWidth(3,200);
	POSITION pos;
	C��ѧ�������Doc* pDoc=(C��ѧ�������Doc* )GetDocument();
    CStudent* pStu=NULL;
	int n=0;

	for(int i=0;i<(pDoc->data_table).data_student.GetCount();i++)
	{
		pos=(pDoc->data_table).data_student.FindIndex(i);
        pStu=&((pDoc->data_table).data_student.GetAt(pos));
		for(int j=0;j<5;j++)
		{
		    if(pStu->course[j]!=""&&pStu->course[j]==course_name)
		    {
				ListCtrl.InsertItem(n,"");

				for(int k=0;k<4;k++)
				{
						if(k==0)
			            {
				             CString pSn=pStu->student_number;
				             ListCtrl.SetItemText(n,k,pSn);
				
			            }
						if(k==1)
						{
							CString pSn=pStu->Name;
							ListCtrl.SetItemText(n,k,pSn);
						}
						if(k==2)
						{
							CString pSn=pStu->class_number;
							ListCtrl.SetItemText(n,k,pSn);
						}
						if(k==3)
						{
							CString pSn="";
							pSn.Format(_T("%.2f"),(pStu->course_score[j]));
							ListCtrl.SetItemText(n,k,pSn);
						}
						
				}
				n++;
			}
		}
	}

}


void C��ѧ�������View::OnShowStudent()
{
	ShowIndividual dlg;
	dlg.DoModal();
	// TODO: �ڴ���������������
}




void C��ѧ�������View::ShowIndividualTable(CString stundent_number)
{
	CListCtrl& ListCtrl = GetListCtrl();
	while(ListCtrl.DeleteColumn(0)){};
	ListCtrl.DeleteAllItems();

	ListCtrl.InsertColumn(0,"��Ŀ");
	ListCtrl.SetColumnWidth(0,300);
	ListCtrl.InsertColumn(1,"����");
	ListCtrl.SetColumnWidth(1,300);
	ListCtrl.InsertColumn(2,"����");
	ListCtrl.SetColumnWidth(2,300);

	POSITION pos;
	C��ѧ�������Doc* pDoc=(C��ѧ�������Doc* )GetDocument();
    CStudent* pStu=NULL;
	for(int i=0;i<(pDoc->data_table).data_student.GetCount();i++)
	{
		pos=(pDoc->data_table).data_student.FindIndex(i);
        pStu=&((pDoc->data_table).data_student.GetAt(pos));
		if(pStu->student_number==stundent_number)
			break;
	}
	int n_course=0;
	for(int i=0;i<5;i++)
	{
		if(pStu->course[i]!="")
			n_course++;
	}
	for(int i=0;i<3+n_course;i++)
		ListCtrl.InsertItem(i,"");
	ListCtrl.SetItemText(0,0,"����");
	ListCtrl.SetItemText(0,1,pStu->Name);
	ListCtrl.SetItemText(1,0,"ѧ��");
	ListCtrl.SetItemText(1,1,pStu->student_number);
	ListCtrl.SetItemText(2,0,"�༶");
	ListCtrl.SetItemText(2,1,pStu->class_number);
	for(int i=0;i<n_course;i++)
	{
		CString n;
		n.Format(_T("%d"),i+1);
		CString kemu="��Ŀ"+n;
		ListCtrl.SetItemText(3+i,0,kemu);
		ListCtrl.SetItemText(3+i,1,pStu->course[i]);
		CString pSn="";
		pSn.Format(_T("%.2f"),(pStu->course_score[i]));
		ListCtrl.SetItemText(3+i,2,pSn);
	}

}


void C��ѧ�������View::OnShowaverage()
{
	CListCtrl& ListCtrl = GetListCtrl();
	while(ListCtrl.DeleteColumn(0)){};
	ListCtrl.DeleteAllItems();

	ListCtrl.InsertColumn(0,"�༶/��Ŀ");
	ListCtrl.SetColumnWidth(0,200);
	POSITION pos;
	C��ѧ�������Doc* pDoc=(C��ѧ�������Doc* )GetDocument();
	int n_class=0;
	int n_course=0;
	for(int i=0;i<10;i++)
	{
		if(pDoc->data_table.AllClass[i]!="")
		{
			CString banji="�༶"+pDoc->data_table.AllClass[i];
			ListCtrl.InsertColumn(i+1,banji);
			ListCtrl.SetColumnWidth(i+1,100);
			n_class++;
		}

	}
	for(int i=0;i<10;i++)
	{
		if(pDoc->data_table.AllCourse[i]!="")
		{
			ListCtrl.InsertItem(i,"");
			CString kemu="��Ŀ"+pDoc->data_table.AllCourse[i];
			ListCtrl.SetItemText(i,0,kemu);
			n_course++;
		}
	}

	for(int i=0;i<n_class;i++)
	{
		for(int j=0;j<n_course;j++)
		{
			double average=0;
			int n_student=0;
			for(int n=0;n<(pDoc->data_table).data_student.GetCount();n++)
			{
				pos=pDoc->data_table.data_student.FindIndex(n);
				CStudent* pStu=&(pDoc->data_table.data_student.GetAt(pos));
				if(pStu->class_number==pDoc->data_table.AllClass[i])
				{
					
					for(int l=0;l<5;l++)
					{
						if(pStu->course[l]==pDoc->data_table.AllCourse[j])
						{
							average=average+pStu->course_score[l];
							n_student++;
						}
					}
				}
			}
			CString ave;
			if(n_student!=0)
			    ave.Format(_T("%.2f"),average/n_student);
			else
				ave="�˰�����ѡ�˿�";
			ListCtrl.SetItemText(j,i+1,ave);
		}
	}


	// TODO: �ڴ���������������
}
