
// ��ѧ�������.h : ��ѧ������� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include "Student.h"


// C��ѧ�������App:
// �йش����ʵ�֣������ ��ѧ�������.cpp
//

class C��ѧ�������App : public CWinAppEx
{
public:
	C��ѧ�������App();
	int StudentNumber;
	CStudent* StudentArrey;


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ѧ�������App theApp;
