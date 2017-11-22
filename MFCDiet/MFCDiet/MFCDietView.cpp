
// MFCDietView.cpp : CMFCDietView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MFCDiet.h"
#endif

#include "MFCDietDoc.h"
#include "MFCDietView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDietView

IMPLEMENT_DYNCREATE(CMFCDietView, CFormView)

BEGIN_MESSAGE_MAP(CMFCDietView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCDietView ����/�Ҹ�

CMFCDietView::CMFCDietView()
	: CFormView(IDD_MFCDIET_FORM)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMFCDietView::~CMFCDietView()
{
}

void CMFCDietView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMFCDietView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CMFCDietView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CMFCDietView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCDietView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCDietView ����

#ifdef _DEBUG
void CMFCDietView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCDietView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCDietDoc* CMFCDietView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDietDoc)));
	return (CMFCDietDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDietView �޽��� ó����
