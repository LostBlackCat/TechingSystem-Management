
// ��ѧ�������View.h : C��ѧ�������View ��Ľӿ�
//

#pragma once


class C��ѧ�������View : public CListView
{
protected: // �������л�����
	C��ѧ�������View();
	DECLARE_DYNCREATE(C��ѧ�������View)

// ����
public:
	C��ѧ�������Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C��ѧ�������View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEdit();
	afx_msg void OnShow();
	afx_msg void OnChoose();
	afx_msg void OnScore();
	afx_msg void OnShowCourse();
	afx_msg void OnShowClass();
	void ShowClassTable(CString class_name);
	afx_msg void OnShowFall();
	void ShowFallTable(CString course_name);
	void ShowCourseTable(CString course_name);
	afx_msg void OnShowStudent();
	void ShowIndividualTable(CString stundent_number);
	afx_msg void OnShowaverage();
};

#ifndef _DEBUG  // ��ѧ�������View.cpp �еĵ��԰汾
inline C��ѧ�������Doc* C��ѧ�������View::GetDocument() const
   { return reinterpret_cast<C��ѧ�������Doc*>(m_pDocument); }
#endif

