
// ��ѧ�������Doc.h : C��ѧ�������Doc ��Ľӿ�
//


#pragma once
#include "CTable.h"

class C��ѧ�������Doc : public CDocument
{
protected: // �������л�����
	C��ѧ�������Doc();
	DECLARE_DYNCREATE(C��ѧ�������Doc)

// ����
public:
	Table data_table;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~C��ѧ�������Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnSign();
};
