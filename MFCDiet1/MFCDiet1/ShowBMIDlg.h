#pragma once


// CShowBMIDlg 대화 상자입니다.

class CShowBMIDlg : public CDialog
{
	DECLARE_DYNAMIC(CShowBMIDlg)

public:
	CShowBMIDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CShowBMIDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOWBMI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
