#pragma once
#include "afxwin.h"


// CUserInfoDlg ��ȭ �����Դϴ�.

class CUserInfoDlg : public CDialog
{
	DECLARE_DYNAMIC(CUserInfoDlg)

public:
	CUserInfoDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CUserInfoDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USERINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
