
// MFCDietView.h : CMFCDietView Ŭ������ �������̽�
//

#pragma once


class CMFCDietView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CMFCDietView();
	DECLARE_DYNCREATE(CMFCDietView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCDIET_FORM };
#endif

// Ư���Դϴ�.
public:
	CMFCDietDoc* GetDocument() const;

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
	virtual ~CMFCDietView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCDietView.cpp�� ����� ����
inline CMFCDietDoc* CMFCDietView::GetDocument() const
   { return reinterpret_cast<CMFCDietDoc*>(m_pDocument); }
#endif

