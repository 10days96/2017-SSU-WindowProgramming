#pragma once
#include "afxwin.h"


// CDlgTab02 ��ȭ �����Դϴ�.

class CDlgTab02 : public CDialog
{
	DECLARE_DYNAMIC(CDlgTab02)

public:
	CDlgTab02(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgTab02();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB2};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_List2;
};
