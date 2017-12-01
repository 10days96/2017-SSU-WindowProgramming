#pragma once


// CDlgTab01 대화 상자입니다.

class CDlgTab01 : public CDialog
{
	DECLARE_DYNAMIC(CDlgTab01)

public:
	CDlgTab01(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgTab01();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB1};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
