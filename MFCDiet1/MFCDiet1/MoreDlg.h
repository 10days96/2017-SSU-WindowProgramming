#pragma once
#include "afxwin.h"

class CMFCDiet1View;
// CMoreDlg ��ȭ �����Դϴ�.
class CMoreDlg : public CDialog
{
	DECLARE_DYNAMIC(CMoreDlg)

public:
	CMoreDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMoreDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOWMORE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CMFCDiet1View* m_pView;
	CComboBox m_Meal_combo;
	afx_msg void OnBnClickedOk();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
};
