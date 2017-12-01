
// MFCDiet1View.cpp : CMFCDiet1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// CMFCDiet1View ����/�Ҹ�

CMFCDiet1View::CMFCDiet1View()
	: CFormView(IDD_MFCDIET1_FORM)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CMFCDiet1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_Tab.InsertItem(0, L"��ħ", 0);
	m_Tab.InsertItem(1, L"����", 0);
	m_Tab.InsertItem(2, L"����", 0);
	m_Tab.InsertItem(3, L"����", 0);
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


// CMFCDiet1View ����

#ifdef _DEBUG
void CMFCDiet1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCDiet1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCDiet1Doc* CMFCDiet1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDiet1Doc)));
	return (CMFCDiet1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDiet1View �޽��� ó����


void CMFCDiet1View::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
