
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
#include "ShowInfoDialog.h"
#include "UserInfoDlg.h"
#include "ShowBMIDlg.h"
#include "PieChartDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDiet1View

IMPLEMENT_DYNCREATE(CMFCDiet1View, CFormView)

BEGIN_MESSAGE_MAP(CMFCDiet1View, CFormView)
	ON_BN_CLICKED(ID_SHOWINFO, &CMFCDiet1View::OnBnClickedShowinfo)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCDiet1View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_USERINFO, &CMFCDiet1View::OnBnClickedButtonUserinfo)
	ON_BN_CLICKED(IDC_BUTTON_BMI, &CMFCDiet1View::OnBnClickedButtonBmi)
	ON_BN_CLICKED(IDC_BUTTON_CHART, &CMFCDiet1View::OnBnClickedButtonChart)
END_MESSAGE_MAP()

// CMFCDiet1View ����/�Ҹ�

CMFCDiet1View::CMFCDiet1View()
	: CFormView(IDD_MFCDIET1_FORM)
{
	m_pShowInfoDlg = NULL;
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CMFCDiet1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

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


void CMFCDiet1View::OnBnClickedShowinfo()
{
	
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCDiet1View::OnBnClickedButton2()
{
	if (m_pShowInfoDlg != NULL)
		m_pShowInfoDlg->SetFocus();
	else {
		m_pShowInfoDlg = new CShowInfoDialog();
		m_pShowInfoDlg->m_pView = this;
		m_pShowInfoDlg->Create(IDD_SHOWINFO);
		m_pShowInfoDlg->ShowWindow(SW_SHOW);
	}
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCDiet1View::OnBnClickedButtonUserinfo()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CUserInfoDlg dlg;

	dlg.DoModal();
}


void CMFCDiet1View::OnBnClickedButtonBmi()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CShowBMIDlg dlg;
	dlg.DoModal();
}


void CMFCDiet1View::OnBnClickedButtonChart()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CPieChartDlg dlg;
	dlg.DoModal();
}
