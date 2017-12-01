
// MFCDiet1View.h : CMFCDiet1View Ŭ������ �������̽�
//

#pragma once
#include "afxcmn.h"
#include "DlgTab01.h"
#include "DlgTab02.h"
#include "DlgTab03.h"
#include "DlgTab04.h"
class CShowInfoDialog;


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
	CShowInfoDialog* m_pShowInfoDlg;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
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
	afx_msg void OnBnClickedShowinfo();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButtonUserinfo();
	afx_msg void OnBnClickedButtonBmi();
	afx_msg void OnBnClickedButtonChart();
	CDlgTab01 *m_pDialog1;
	CDlgTab02 *m_pDialog2;
	CDlgTab03 *m_pDialog3;
	CDlgTab04 *m_pDialog4;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // MFCDiet1View.cpp�� ����� ����
inline CMFCDiet1Doc* CMFCDiet1View::GetDocument() const
   { return reinterpret_cast<CMFCDiet1Doc*>(m_pDocument); }
#endif

