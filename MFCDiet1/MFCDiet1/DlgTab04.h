#pragma once
#include "afxwin.h"


// CDlgTab04 ��ȭ �����Դϴ�.

class CDlgTab04 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTab04)

public:
	CDlgTab04(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgTab04();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_List4;
};
