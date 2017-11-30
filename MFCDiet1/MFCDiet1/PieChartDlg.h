#pragma once


// CPieChartDlg 대화 상자입니다.

class CPieChartDlg : public CDialog
{
	DECLARE_DYNAMIC(CPieChartDlg)

public:
	CPieChartDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CPieChartDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PIECHART };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
