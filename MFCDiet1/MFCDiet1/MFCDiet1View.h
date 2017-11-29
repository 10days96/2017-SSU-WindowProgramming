
// MFCDiet1View.h : CMFCDiet1View 클래스의 인터페이스
//

#pragma once
#include "afxcmn.h"
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

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
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
	afx_msg void OnBnClickedShowinfo();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // MFCDiet1View.cpp의 디버그 버전
inline CMFCDiet1Doc* CMFCDiet1View::GetDocument() const
   { return reinterpret_cast<CMFCDiet1Doc*>(m_pDocument); }
#endif

