#pragma once
#include "afxwin.h"


// CDlgTab01 ��ȭ �����Դϴ�.
class CMFCDiet1View;
class CMFCDiet1Doc;
class CDlgTab01 : public CDialog
{
	DECLARE_DYNAMIC(CDlgTab01)

public:
	CDlgTab01(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgTab01();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB1};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_List1;
	CMFCDiet1View* m_pView;
	CMFCDiet1Doc* m_pDoc;
//	afx_msg void OnLbnSetfocusList1();
	afx_msg void OnLbnSelchangeList1();
};
