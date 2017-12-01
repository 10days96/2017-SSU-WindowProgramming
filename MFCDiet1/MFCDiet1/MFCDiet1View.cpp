
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
#define SAFE_DELETE(p) {if(p){delete p; p=NULL;}}

// CMFCDiet1View

IMPLEMENT_DYNCREATE(CMFCDiet1View, CFormView)

BEGIN_MESSAGE_MAP(CMFCDiet1View, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMFCDiet1View::OnSelchangeTab1)
END_MESSAGE_MAP()

// CMFCDiet1View 생성/소멸

CMFCDiet1View::CMFCDiet1View()
	: CFormView(IDD_MFCDIET1_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_pDialog1 = NULL;
	m_pDialog2 = NULL;
	m_pDialog3 = NULL;
	m_pDialog4 = NULL;
}

CMFCDiet1View::~CMFCDiet1View()
{
	SAFE_DELETE(m_pDialog1);
	SAFE_DELETE(m_pDialog2);
	SAFE_DELETE(m_pDialog3);
	SAFE_DELETE(m_pDialog4);
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

	m_Tab.InsertItem(0, L"아침", 0);
	m_Tab.InsertItem(1, L"점심", 0);
	m_Tab.InsertItem(2, L"저녁", 0);
	m_Tab.InsertItem(3, L"간식", 0);
	m_Tab.SetCurSel(0);

	CRect rect;
	m_pDialog1 = new CDlgTab1;
	m_pDialog1->Create(IDD_DIALOG1, &m_Tab);
	m_pDialog1->GetWindowRect(&rect);
	m_pDialog1->MoveWindow(5, 25, rect.Width(), rect.Height());
	m_pDialog1->ShowWindow(SW_SHOW);

	m_pDialog2 = new CDlgTab2;
	m_pDialog2->Create(IDD_DIALOG2, &m_Tab);
	m_pDialog2->GetWindowRect(&rect);
	m_pDialog2->MoveWindow(5, 25, rect.Width(), rect.Height());
	m_pDialog2->ShowWindow(SW_SHOW);

	m_pDialog3 = new CDlgTab3;
	m_pDialog3->Create(IDD_DIALOG3, &m_Tab);
	m_pDialog3->GetWindowRect(&rect);
	m_pDialog3->MoveWindow(5, 25, rect.Width(), rect.Height());
	m_pDialog3->ShowWindow(SW_SHOW);

	m_pDialog4 = new CDlgTab4;
	m_pDialog4->Create(IDD_DIALOG4, &m_Tab);
	m_pDialog4->GetWindowRect(&rect);
	m_pDialog4->MoveWindow(5, 25, rect.Width(), rect.Height());
	m_pDialog4->ShowWindow(SW_SHOW);

	m_pDialog1->ShowWindow(SW_SHOW);
	m_pDialog2->ShowWindow(SW_HIDE);
	m_pDialog3->ShowWindow(SW_HIDE);
	m_pDialog4->ShowWindow(SW_HIDE);

	UpdateData(FALSE);;
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


void CMFCDiet1View::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int select = m_Tab.GetCurSel();

	switch (select)
	{
	case 0:
		m_pDialog1->ShowWindow(SW_SHOW);
		m_pDialog2->ShowWindow(SW_HIDE);
		m_pDialog3->ShowWindow(SW_HIDE);
		m_pDialog4->ShowWindow(SW_HIDE);
		break;
	case 1:
		m_pDialog1->ShowWindow(SW_HIDE);
		m_pDialog2->ShowWindow(SW_SHOW);
		m_pDialog3->ShowWindow(SW_HIDE);
		m_pDialog4->ShowWindow(SW_HIDE);
		break;
	case 2:
		m_pDialog1->ShowWindow(SW_HIDE);
		m_pDialog2->ShowWindow(SW_HIDE);
		m_pDialog3->ShowWindow(SW_SHOW);
		m_pDialog4->ShowWindow(SW_HIDE);
		break;
	case 3:
		m_pDialog1->ShowWindow(SW_HIDE);
		m_pDialog2->ShowWindow(SW_HIDE);
		m_pDialog3->ShowWindow(SW_HIDE);
		m_pDialog4->ShowWindow(SW_SHOW);
		break;
	}
	*pResult = 0;
}
