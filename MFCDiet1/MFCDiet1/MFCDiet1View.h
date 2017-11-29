
// MFCDiet1View.h : CMFCDiet1View Ŭ������ �������̽�
//

#pragma once
#include "afxcmn.h"
#include "DlgTab1.h"
#include "DlgTab2.h"
#include "DlgTab3.h"
#include "DlgTab4.h"


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
	afx_msg void OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	CDlgTab1 *m_pDialog1;
	CDlgTab2 *m_pDialog2;
	CDlgTab3 *m_pDialog3;
	CDlgTab4 *m_pDialog4;
};

#ifndef _DEBUG  // MFCDiet1View.cpp�� ����� ����
inline CMFCDiet1Doc* CMFCDiet1View::GetDocument() const
   { return reinterpret_cast<CMFCDiet1Doc*>(m_pDocument); }
#endif

