#pragma once
#include "afxwin.h"

class CMFCDiet1View;
// CMoreDlg 대화 상자입니다.
class CMoreDlg : public CDialog
{
	DECLARE_DYNAMIC(CMoreDlg)

public:
	CMoreDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMoreDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOWMORE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CMFCDiet1View* m_pView;
	CComboBox m_Meal_combo;
	afx_msg void OnBnClickedOk();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
};
