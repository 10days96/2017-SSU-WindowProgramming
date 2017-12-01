
// MFCDiet1View.h : CMFCDiet1View 클래스의 인터페이스
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


class CMFCDiet1View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMFCDiet1View();
	DECLARE_DYNCREATE(CMFCDiet1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCDIET1_FORM };
#endif

// 특성입니다.
public:
	CMFCDiet1Doc* GetDocument() const;
	CShowInfoDialog* m_pShowInfoDlg;

// 작업입니다.
public:
	CString str;
	CList<Food, Food> list;
// 재정의입니다.
public:
//	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CMFCDiet1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_Tab;
	int select;
	Food tmp;
	SYSTEMTIME date;
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
//	afx_msg void OnNMClickTab1(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // MFCDiet1View.cpp의 디버그 버전
inline CMFCDiet1Doc* CMFCDiet1View::GetDocument() const
   { return reinterpret_cast<CMFCDiet1Doc*>(m_pDocument); }
#endif

