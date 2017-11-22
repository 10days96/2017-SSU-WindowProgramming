
// MFCDiet1View.cpp : CMFCDiet1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCDiet1.h"
#endif

#include "MFCDiet1Doc.h"
#include "MFCDiet1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDiet1View

IMPLEMENT_DYNCREATE(CMFCDiet1View, CFormView)

BEGIN_MESSAGE_MAP(CMFCDiet1View, CFormView)
END_MESSAGE_MAP()

// CMFCDiet1View 생성/소멸

CMFCDiet1View::CMFCDiet1View()
	: CFormView(IDD_MFCDIET1_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCDiet1View::~CMFCDiet1View()
{
}

void CMFCDiet1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab);
}

BOOL CMFCDiet1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMFCDiet1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMFCDiet1View 진단

#ifdef _DEBUG
void CMFCDiet1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCDiet1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCDiet1Doc* CMFCDiet1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDiet1Doc)));
	return (CMFCDiet1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDiet1View 메시지 처리기
