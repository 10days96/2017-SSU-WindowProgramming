#pragma once
#include "afxwin.h"


// CUserInfoDlg 대화 상자입니다.

class CUserInfoDlg : public CDialog
{
	DECLARE_DYNAMIC(CUserInfoDlg)

public:
	CUserInfoDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CUserInfoDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USERINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit editAge;
	CEdit editLength;
	CEdit editWeight;
	CButton radioMale;
	CButton radioFemale;
	int inputAge;
	double inputLength;
	double inputWeight;
	BOOL inputGender;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
