#pragma once
#include "afxwin.h"


// CDlgTab02 대화 상자입니다.

class CDlgTab02 : public CDialog
{
	DECLARE_DYNAMIC(CDlgTab02)

public:
	CDlgTab02(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgTab02();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB2};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_List2;
};
