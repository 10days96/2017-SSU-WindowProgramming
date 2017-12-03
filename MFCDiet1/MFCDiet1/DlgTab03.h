#pragma once
#include "afxwin.h"


// CDlgTab03 대화 상자입니다.

class CDlgTab03 : public CDialog
{
	DECLARE_DYNAMIC(CDlgTab03)

public:
	CDlgTab03(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgTab03();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_List3;
	afx_msg void OnLbnSelchangeList1();
};
