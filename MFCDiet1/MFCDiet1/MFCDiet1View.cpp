
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
#include "ShowInfoDialog.h"
#include "UserInfoDlg.h"
#include "ShowBMIDlg.h"
#include "PieChartDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define SAFE_DELETE(p) {if(p){delete p; p=NULL;}}


// CMFCDiet1View

IMPLEMENT_DYNCREATE(CMFCDiet1View, CFormView)

BEGIN_MESSAGE_MAP(CMFCDiet1View, CFormView)
	ON_BN_CLICKED(ID_SHOWINFO, &CMFCDiet1View::OnBnClickedShowinfo)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCDiet1View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_USERINFO, &CMFCDiet1View::OnBnClickedButtonUserinfo)
	ON_BN_CLICKED(IDC_BUTTON_BMI, &CMFCDiet1View::OnBnClickedButtonBmi)
	ON_BN_CLICKED(IDC_BUTTON_CHART, &CMFCDiet1View::OnBnClickedButtonChart)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMFCDiet1View::OnTcnSelchangeTab1)
	ON_NOTIFY(MCN_SELECT, IDC_MONTHCALENDAR1, &CMFCDiet1View::OnMcnSelectMonthcalendar1)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCDiet1View::OnBnClickedButton9)
//	ON_NOTIFY(NM_CLICK, IDC_TAB1, &CMFCDiet1View::OnNMClickTab1)
END_MESSAGE_MAP()

// CMFCDiet1View 생성/소멸

CMFCDiet1View::CMFCDiet1View()
	: CFormView(IDD_MFCDIET1_FORM)
	, m_edit1(_T(""))
	, m_edit2(_T(""))
	, m_edit3(_T(""))
{
	m_pShowInfoDlg = NULL;
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
	DDX_Control(pDX, IDC_MONTHCALENDAR1, m_date);
	DDX_Control(pDX, IDC_EDIT1, c_edit1);
	DDX_Control(pDX, IDC_EDIT2, c_edit2);
	DDX_Control(pDX, IDC_EDIT3, c_edit3);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
}

//BOOL CMFCDiet1View::PreCreateWindow(CREATESTRUCT& cs)
//{
//	// TODO: CREATESTRUCT cs를 수정하여 여기에서
//	//  Window 클래스 또는 스타일을 수정합니다.
//
//	return CFormView::PreCreateWindow(cs);
//}

void CMFCDiet1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_Tab.DeleteAllItems();
	m_Tab.InsertItem(0, L"아침", 0);
	m_Tab.InsertItem(1, L"점심", 0);
	m_Tab.InsertItem(2, L"저녁", 0);
	m_Tab.InsertItem(3, L"간식", 0);

	CRect rect;

	m_pDialog1 = new CDlgTab01;
	m_pDialog1->Create(IDD_TAB1, &m_Tab);
	m_pDialog1->GetWindowRect(&rect);
	m_pDialog1->MoveWindow(5, 25, rect.Width(), rect.Height());
	m_pDialog1->ShowWindow(SW_SHOW);

	m_pDialog2 = new CDlgTab02;
	m_pDialog2->Create(IDD_TAB2, &m_Tab);
	m_pDialog2->GetWindowRect(&rect);
	m_pDialog2->MoveWindow(5, 25, rect.Width(), rect.Height());
	m_pDialog2->ShowWindow(SW_SHOW);

	m_pDialog3 = new CDlgTab03;
	m_pDialog3->Create(IDD_TAB3, &m_Tab);
	m_pDialog3->GetWindowRect(&rect);
	m_pDialog3->MoveWindow(5, 25, rect.Width(), rect.Height());
	m_pDialog3->ShowWindow(SW_SHOW);

	m_pDialog4 = new CDlgTab04;
	m_pDialog4->Create(IDD_TAB4, &m_Tab);
	m_pDialog4->GetWindowRect(&rect);
	m_pDialog4->MoveWindow(5, 25, rect.Width(), rect.Height());
	m_pDialog4->ShowWindow(SW_SHOW);

	m_pDialog1->ShowWindow(SW_SHOW);
	m_pDialog2->ShowWindow(SW_HIDE);
	m_pDialog3->ShowWindow(SW_HIDE);
	m_pDialog4->ShowWindow(SW_HIDE);

	UpdateData(FALSE);
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


void CMFCDiet1View::OnBnClickedShowinfo()
{
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCDiet1View::OnBnClickedButtonUserinfo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CUserInfoDlg dlg;

	dlg.DoModal();
}


void CMFCDiet1View::OnBnClickedButtonBmi()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CShowBMIDlg dlg;
	dlg.DoModal();
}


void CMFCDiet1View::OnBnClickedButtonChart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CPieChartDlg dlg;
	dlg.DoModal();
}


void CMFCDiet1View::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	select = m_Tab.GetCurSel();
	switch (select)
	{
	case 0:
		m_pDialog1->ShowWindow(SW_SHOW);
		m_pDialog2->ShowWindow(SW_HIDE);
		m_pDialog3->ShowWindow(SW_HIDE);
		m_pDialog4->ShowWindow(SW_HIDE);
		tmp.time = 0;
		break;
	case 1:
		m_pDialog1->ShowWindow(SW_HIDE);
		m_pDialog2->ShowWindow(SW_SHOW);
		m_pDialog3->ShowWindow(SW_HIDE);
		m_pDialog4->ShowWindow(SW_HIDE);
		tmp.time = 1;
		break;
	case 2:
		m_pDialog1->ShowWindow(SW_HIDE);
		m_pDialog2->ShowWindow(SW_HIDE);
		m_pDialog3->ShowWindow(SW_SHOW);
		m_pDialog4->ShowWindow(SW_HIDE);
		tmp.time = 2;
		break;
	case 3:
		m_pDialog1->ShowWindow(SW_HIDE);
		m_pDialog2->ShowWindow(SW_HIDE);
		m_pDialog3->ShowWindow(SW_HIDE);
		m_pDialog4->ShowWindow(SW_SHOW);
		tmp.time = 3;
		break;
	}
	*pResult = 0;
}


void CMFCDiet1View::OnMcnSelectMonthcalendar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMSELCHANGE pSelChange = reinterpret_cast<LPNMSELCHANGE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_Tab.SetCurSel(0);
	tmp.time = 0;

	*pResult = 0;

	SYSTEMTIME date;
	CString str;

	// Calender에 선택된 날짜정보를 얻는다.
	m_date.GetCurSel(&date);

	CMFCDiet1Doc *pDoc = GetDocument();
	//Food tmp;

	tmp.date_day = date.wDay;

	//str.Format(_T("%d 년 %d 월 %d 일"), date.wYear, date.wMonth, date.wDay);

	
	m_pDialog1->m_List1.ResetContent();
	m_pDialog2->m_List2.ResetContent();
	m_pDialog3->m_List3.ResetContent();
	m_pDialog4->m_List4.ResetContent();

	POSITION pos = list.GetHeadPosition();

	while (pos != NULL) {
		tmp = list.GetNext(pos);
	
		str.Format(_T("%s   %.3lfkcal  %.2lf인분"),tmp.foodname, tmp.cal, tmp.plate);

		if (tmp.date_day == date.wDay && tmp.date_month == date.wMonth && tmp.date_year == date.wYear) {
		if(tmp.time ==0)
			m_pDialog1->m_List1.AddString(str);
		else if(tmp.time ==1)
			m_pDialog2->m_List2.AddString(str);
		else if (tmp.time == 2)
			m_pDialog3->m_List3.AddString(str);
		else if (tmp.time == 3)
			m_pDialog4->m_List4.AddString(str);
		}
		//tmp = list.GetNext(pos);
		/*
		if (tmp.time == 0 && tmp.a_date  == m_date.GetCurSel(&date)) {
			
			m_pDialog1->m_List1.AddString(str);
		}
		else if (tmp.time == 1 && tmp.a_date == m_date.GetCurSel(&date)) {
			
			m_pDialog2->m_List2.AddString(str);
		}
		else if (tmp.time == 2 && tmp.a_date == m_date.GetCurSel(&date)) {
			
			m_pDialog3->m_List3.AddString(str);
		}
		else if (tmp.time == 3 && tmp.a_date == m_date.GetCurSel(&date)) {
			
			m_pDialog4->m_List4.AddString(str);
		}
		*/
	}
	
	
}


void CMFCDiet1View::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDlgTab01 *Tab1;
	//m_pDialog1 = new CDlgTab01;



	CMFCDiet1Doc *pDoc = GetDocument();
	//Food tmp;
	CString str;
	//SYSTEMTIME date;
	//CTime date_day;
	m_date.GetCurSel(&date);
	tmp.date_day = date.wDay;
	tmp.date_month = date.wMonth;
	tmp.date_year = date.wYear;
	CString SelectDate;
	

	c_edit1.GetWindowText(str);
	str.Format(_T(" %s "), str);

	tmp.foodname = str;

	c_edit2.GetWindowText(str);
	double input_cal = _wtof(str);
	tmp.cal = input_cal;

	//tmp.a_date = date;

	c_edit3.GetWindowText(str);
	double input_plate = _wtof(str);
	tmp.plate = input_plate;
	list.AddTail(tmp);

		
	str.Format(_T("%s     %.3lfkcal     %.2lf인분"), tmp.foodname, tmp.cal, tmp.plate);
		if (tmp.time == 0 ) {
			m_pDialog1->m_List1.AddString(str);
		}
		else if (tmp.time == 1) {
			m_pDialog2->m_List2.AddString(str);
		}
		else if (tmp.time == 2 ) {
			m_pDialog3->m_List3.AddString(str);
		}
		else if (tmp.time == 3) {
			m_pDialog4->m_List4.AddString(str);
		}
	//}
	
}


//void CMFCDiet1View::OnNMClickTab1(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	int selectTab = m_Tab.GetCurSel();
//	*pResult = 0;
//}
