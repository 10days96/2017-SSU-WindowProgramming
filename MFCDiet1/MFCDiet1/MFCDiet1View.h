
// MFCDiet1View.h : CMFCDiet1View Ŭ������ �������̽�
//

#pragma once
#include "afxcmn.h"
#include "DlgTab01.h"
#include "DlgTab02.h"
#include "DlgTab03.h"
#include "DlgTab04.h"
#include "afxdtctl.h"
#include "afxwin.h"
class CShowInfoDialog;
class CMoreDlg;

class CMFCDiet1View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CMFCDiet1View();
	DECLARE_DYNCREATE(CMFCDiet1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCDIET1_FORM };
#endif

// Ư���Դϴ�.
public:
	CMFCDiet1Doc* GetDocument() const;

// �۾��Դϴ�.
public:
	CString str;

// �������Դϴ�.
public:
//	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CMFCDiet1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_Tab;
	int select;
	//Food tmp;
	SYSTEMTIME date;
	SYSTEMTIME date1;
	afx_msg void OnBnClickedShowinfo();
	afx_msg void OnBnClickedButton2();
//<<<<<<< Updated upstream
	afx_msg void OnBnClickedButtonUserinfo();
	afx_msg void OnBnClickedButtonBmi();
	afx_msg void OnBnClickedButtonChart();
	CDlgTab01 *m_pDialog1;
	CDlgTab02 *m_pDialog2;
	CDlgTab03 *m_pDialog3;
	CDlgTab04 *m_pDialog4;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnMcnSelectMonthcalendar1(NMHDR *pNMHDR, LRESULT *pResult);
	CMonthCalCtrl m_date;
	CEdit c_edit1;
	CEdit c_edit2;
	CEdit c_edit3;
	CString m_edit1;
	CString m_edit2;
	CString m_edit3;
	afx_msg void OnBnClickedButton9();
	Food tmp;
	CShowInfoDialog* m_pShowInfoDlg;
	int buttonstate;
	CMoreDlg* m_pMoreDlg;
//	afx_msg void OnNMClickTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton3();
};

#ifndef _DEBUG  // MFCDiet1View.cpp�� ����� ����
inline CMFCDiet1Doc* CMFCDiet1View::GetDocument() const
   { return reinterpret_cast<CMFCDiet1Doc*>(m_pDocument); }
#endif

