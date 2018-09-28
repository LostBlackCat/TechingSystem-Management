
// ��ѧ�������Doc.cpp : C��ѧ�������Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ѧ�������.h"
#endif

#include "MainFrm.h"
#include "��ѧ�������Doc.h"
#include "��ѧ�������View.h"
#include "Student.h"
#include "SignDlg.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C��ѧ�������Doc

IMPLEMENT_DYNCREATE(C��ѧ�������Doc, CDocument)

BEGIN_MESSAGE_MAP(C��ѧ�������Doc, CDocument)
	ON_COMMAND(ID_SIGN, &C��ѧ�������Doc::OnSign)
END_MESSAGE_MAP()


// C��ѧ�������Doc ����/����

C��ѧ�������Doc::C��ѧ�������Doc()
{
	// TODO: �ڴ����һ���Թ������

}

C��ѧ�������Doc::~C��ѧ�������Doc()
{
}

BOOL C��ѧ�������Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C��ѧ�������Doc ���л�

void C��ѧ�������Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
	data_table.Serialize(ar);
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void C��ѧ�������Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void C��ѧ�������Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C��ѧ�������Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// C��ѧ�������Doc ���

#ifdef _DEBUG
void C��ѧ�������Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C��ѧ�������Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C��ѧ�������Doc ����


void C��ѧ�������Doc::OnSign()
{
	CStudent student;
	SignDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		student.setName(dlg.s_name);
		student.setclass_number(dlg.s_class);
		student.setstudent_number(dlg.s_student_number);
		data_table.data_number++;
		data_table.data_student.AddTail(student);
		
		for(int i=0;i<10;i++)
		{
			if(student.class_number!=""&&student.class_number==data_table.AllClass[i])
				break;
			if(student.class_number!=data_table.AllClass[i]&&data_table.AllClass[i]=="")
			{
				data_table.AllClass[i]=student.class_number;
				break;
			}
		}
		CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	    C��ѧ�������View *pView=(C��ѧ�������View *)pMain->GetActiveView();
		pView->OnShow();
		
	}
	// TODO: �ڴ���������������
}
