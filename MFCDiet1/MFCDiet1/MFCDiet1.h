
// MFCDiet1.h : MFCDiet1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFCDiet1App:
// �� Ŭ������ ������ ���ؼ��� MFCDiet1.cpp�� �����Ͻʽÿ�.
//

class CMFCDiet1App : public CWinApp
{
public:
	CMFCDiet1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCDiet1App theApp;
