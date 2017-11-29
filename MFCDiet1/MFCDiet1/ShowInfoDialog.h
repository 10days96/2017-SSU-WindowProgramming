#pragma once
class CMFCDiet1View;

// CShowInfoDialog 대화 상자입니다.

class CShowInfoDialog : public CDialog
{
	DECLARE_DYNAMIC(CShowInfoDialog)

public:
	CShowInfoDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CShowInfoDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CMFCDiet1View* m_pView;
	//afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedCancel();
};
