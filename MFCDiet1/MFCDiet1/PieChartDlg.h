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
	HICON m_hIcon;

	DECLARE_MESSAGE_MAP()

public:
	float avr[6];
	CRect rectView;
	CRect rectColor1, rectColor2, rectColor3, rectColor4, rectColor5, rectColor6;
	int InputValue[6];
	int x[6], y[6];
	int text_x[6], text_y[6];
	int init_x, init_y;
	double width, height;
	bool PiDraw;
	COLORREF pieColor[6];
	CString percent, temp;
	CString mOutput1;
	CString mOutput2;
	CString mOutput3;
	CString mOutput4;
	CString mOutput5;
	CString mOutput6;

public:
	BOOL checkName;
	BOOL checkPercent;
	afx_msg void OnStnClickedColor1();
	afx_msg void OnStnClickedColor2();
	afx_msg void OnStnClickedColor3();
	afx_msg void OnStnClickedColor4();
	afx_msg void OnStnClickedColor5();
	afx_msg void OnStnClickedColor6();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
};
