
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
#include "MainFrm.h"
#include "MoreDlg.h"
#include "PieChartDlg.h"
#include <locale.h>

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
ON_BN_CLICKED(IDC_BUTTON3, &CMFCDiet1View::OnBnClickedButton3)
ON_WM_CLOSE()
ON_WM_DESTROY()
ON_WM_DRAWITEM()
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

	totalCarbo = 0;
	totalProtein = 0;
	totalFat = 0;
	totalCholest = 0;
	totalFiber = 0;
	totalNa = 0;
	totalCalorie = 0;
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
	DDX_Control(pDX, IDC_TOTAL_CAL, m_total_cal);
	DDX_Control(pDX, IDC_ENCOUR_CAL, m_encour_cal);
	DDX_Control(pDX, IDC_BUTTON_USERINFO, m_button_info);
	DDX_Control(pDX, IDC_BUTTON_BMI, m_button_bmi);
	DDX_Control(pDX, IDC_BUTTON_CHART, m_button_chart);
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

	////////버튼 이미지 변경/////////////
	CBitmap cButtonImg1;
	CBitmap cButtonImg2;
	CBitmap cButtonImg3;
	cButtonImg1.LoadBitmap(IDB_BITMAP3);
	cButtonImg2.LoadBitmap(IDB_BITMAP4);
	cButtonImg3.LoadBitmap(IDB_BITMAP2);
	m_button_info.SetBitmap(cButtonImg1);
	m_button_bmi.SetBitmap(cButtonImg2);
	m_button_chart.SetBitmap(cButtonImg3);

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

	CMFCDiet1Doc* pDoc = GetDocument();
	
	CStdioFile file;
	CFileException e;
	if (!file.Open(_T("my.dat"), CFile::modeRead, &e))
	{
		file.Open(_T("my.dat"), CFile::modeCreate);
	}

	///////////////불러오기///////////////////
	CString readStr, str;
	Food inputFood;
	file.ReadString(readStr);
	AfxExtractSubString(str, readStr, 0, ' ');
	pDoc->user.age = _wtoi(str);
	AfxExtractSubString(str, readStr, 1, ' ');
	pDoc->user.length = _wtof(str);
	AfxExtractSubString(str, readStr, 2, ' ');
	pDoc->user.weight = _wtof(str);
	AfxExtractSubString(str, readStr, 3, ' ');
	pDoc->user.gender = _wtoi(str);
	AfxExtractSubString(str, readStr, 4, ' ');
	pDoc->user.exercise = _wtoi(str);

	setlocale(LC_ALL, "");

	while (file.ReadString(readStr))
	{
		AfxExtractSubString(str, readStr, 0, ' ');
		inputFood.date_day = _wtoi(str);
		AfxExtractSubString(str, readStr, 1, ' ');
		inputFood.date_month = _wtoi(str);
		AfxExtractSubString(str, readStr, 2, ' ');
		inputFood.date_year = _wtoi(str);
		AfxExtractSubString(str, readStr, 3, ' ');
		inputFood.time = _wtoi(str);
		AfxExtractSubString(str, readStr, 4, ' ');
		inputFood.foodname = str;                //한글 깨짐
		AfxExtractSubString(str, readStr, 5, ' ');
		inputFood.plate = _wtof(str);
		AfxExtractSubString(str, readStr, 6, ' ');
		inputFood.cal = _wtof(str);
		AfxExtractSubString(str, readStr, 7, ' ');
		inputFood.Carbo = _wtof(str);
		AfxExtractSubString(str, readStr, 8, ' ');
		inputFood.Protein = _wtof(str);
		AfxExtractSubString(str, readStr, 9, ' ');
		inputFood.Fat = _wtof(str);
		AfxExtractSubString(str, readStr, 10, ' ');
		inputFood.Cholest = _wtof(str);
		AfxExtractSubString(str, readStr, 11, ' ');
		inputFood.Fiber = _wtof(str);
		AfxExtractSubString(str, readStr, 12, ' ');
		inputFood.Na = _wtof(str);

		pDoc->list.AddTail(inputFood);
	}

	file.Close();
	
	while (pDoc->user.age == 0 || pDoc->user.length < 0.001 || pDoc->user.weight < 0.001)
	{
		CUserInfoDlg dlg;
		dlg.DoModal();
	}

	CString cal;
	int exeState;
	if (pDoc->user.exercise == 1)
		exeState = 25;
	else if (pDoc->user.exercise == 2)
		exeState = 32;
	else if (pDoc->user.exercise == 3)
		exeState = 40;

	cal.Format(_T("%.2lf"), (pDoc->user.length-100)*0.9*exeState);
	m_encour_cal.SetWindowTextW(cal);

	m_date.GetCurSel(&date);
	ShowFoodList(pDoc);
	SumTotalCalorie(pDoc);
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
	m_pMoreDlg = new CMoreDlg();
	m_pMoreDlg->Create(IDD_SHOWMORE);
	m_pMoreDlg->ShowWindow(SW_SHOW);
	int nIndex;
	CString str;
	CString name;
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFCDiet1Doc * pDoc = (CMFCDiet1Doc *)pFrame->GetActiveDocument();
	CMFCDiet1View *pView = (CMFCDiet1View *)pFrame->GetActiveView();
	POSITION pos;
	CString input[9];
	int Select_tab =  m_Tab.GetCurSel();
	
	if (Select_tab == 0) {
		nIndex = pView->m_pDialog1->m_List1.GetCurSel();
		if (LB_ERR != nIndex) {
			pView->m_pDialog1->m_List1.GetText(nIndex, str);
			AfxExtractSubString(name, str, 0, ' ');

			pos = pDoc->list.GetHeadPosition();
			for (int i = 0; i < pDoc->list.GetCount(); i++) {
				Food tmp = (Food)pDoc->list.GetNext(pos);
				int meal;
				CString tmp_name = tmp.foodname;
				meal = tmp.time;
				if (!name.Compare(tmp_name) && meal == 0) {
					input[0].Format(_T("%.1lf"), tmp.cal);
					input[1].Format(_T("%.1lf"), tmp.plate);
					input[2].Format(_T("%.1lf"), tmp.Carbo);
					input[3].Format(_T("%.1lf"), tmp.Protein);
					input[4].Format(_T("%.1lf"), tmp.Fat);
					input[5].Format(_T("%.1lf"), tmp.Cholest);
					input[6].Format(_T("%.1lf"), tmp.Fiber);
					input[7].Format(_T("%.1lf"), tmp.Na);
					input[8] = tmp.foodname;
					break;
				}
			}
			m_pMoreDlg->SetDlgItemText(ID_D2_Amount_Edit, input[1]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Carbo_Edit, input[2]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Protein_Edit, input[3]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Fat_Edit, input[4]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Cholest_Edit, input[5]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Fiber_Edit, input[6]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Na_Edit, input[7]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Name_Edit, name);
			m_pMoreDlg->SetDlgItemText(ID_D2_Kcal_Edit, input[0]);
			m_pMoreDlg->m_Meal_combo.SetCurSel(0);
		}
	}

	if (Select_tab == 1) {
		nIndex = pView->m_pDialog2->m_List2.GetCurSel();
		if (LB_ERR != nIndex) {
			pView->m_pDialog2->m_List2.GetText(nIndex, str);
			AfxExtractSubString(name, str, 0, ' ');

			pos = pDoc->list.GetHeadPosition();
			for (int i = 0; i < pDoc->list.GetCount(); i++) {
				Food tmp = (Food)pDoc->list.GetNext(pos);
				int meal;
				CString tmp_name = tmp.foodname;
				meal = tmp.time;
				if (!name.Compare(tmp_name) && meal == 1) {
					input[0].Format(_T("%.1lf"), tmp.cal);
					input[1].Format(_T("%.1lf"), tmp.plate);
					input[2].Format(_T("%.1lf"), tmp.Carbo);
					input[3].Format(_T("%.1lf"), tmp.Protein);
					input[4].Format(_T("%.1lf"), tmp.Fat);
					input[5].Format(_T("%.1lf"), tmp.Cholest);
					input[6].Format(_T("%.1lf"), tmp.Fiber);
					input[7].Format(_T("%.1lf"), tmp.Na);
					input[8] = tmp.foodname;
					break;
				}
			}
			m_pMoreDlg->SetDlgItemText(ID_D2_Amount_Edit, input[1]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Carbo_Edit, input[2]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Protein_Edit, input[3]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Fat_Edit, input[4]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Cholest_Edit, input[5]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Fiber_Edit, input[6]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Na_Edit, input[7]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Name_Edit, name);
			m_pMoreDlg->SetDlgItemText(ID_D2_Kcal_Edit, input[0]);
			m_pMoreDlg->m_Meal_combo.SetCurSel(1);
		}
	}

	if (Select_tab == 2) {
		nIndex = pView->m_pDialog3->m_List3.GetCurSel();
		if (LB_ERR != nIndex) {
			pView->m_pDialog3->m_List3.GetText(nIndex, str);
			AfxExtractSubString(name, str, 0, ' ');

			pos = pDoc->list.GetHeadPosition();
			for (int i = 0; i < pDoc->list.GetCount(); i++) {
				Food tmp = (Food)pDoc->list.GetNext(pos);
				int meal;
				CString tmp_name = tmp.foodname;
				meal = tmp.time;
				if (!name.Compare(tmp_name) && meal == 2) {
					input[0].Format(_T("%.1lf"), tmp.cal);
					input[1].Format(_T("%.1lf"), tmp.plate);
					input[2].Format(_T("%.1lf"), tmp.Carbo);
					input[3].Format(_T("%.1lf"), tmp.Protein);
					input[4].Format(_T("%.1lf"), tmp.Fat);
					input[5].Format(_T("%.1lf"), tmp.Cholest);
					input[6].Format(_T("%.1lf"), tmp.Fiber);
					input[7].Format(_T("%.1lf"), tmp.Na);
					input[8] = tmp.foodname;
					break;
				}
			}
			m_pMoreDlg->SetDlgItemText(ID_D2_Amount_Edit, input[1]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Carbo_Edit, input[2]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Protein_Edit, input[3]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Fat_Edit, input[4]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Cholest_Edit, input[5]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Fiber_Edit, input[6]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Na_Edit, input[7]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Name_Edit, name);
			m_pMoreDlg->SetDlgItemText(ID_D2_Kcal_Edit, input[0]);
			m_pMoreDlg->m_Meal_combo.SetCurSel(2);
		}
	}

	if (Select_tab == 3) {
		nIndex = pView->m_pDialog4->m_List4.GetCurSel();
		if (LB_ERR != nIndex) {
			pView->m_pDialog4->m_List4.GetText(nIndex, str);
			AfxExtractSubString(name, str, 0, ' ');

			pos = pDoc->list.GetHeadPosition();
			for (int i = 0; i < pDoc->list.GetCount(); i++) {
				Food tmp = (Food)pDoc->list.GetNext(pos);
				int meal;
				CString tmp_name = tmp.foodname;
				meal = tmp.time;
				if (!name.Compare(tmp_name) && meal == 3) {
					input[0].Format(_T("%.1lf"), tmp.cal);
					input[1].Format(_T("%.1lf"), tmp.plate);
					input[2].Format(_T("%.1lf"), tmp.Carbo);
					input[3].Format(_T("%.1lf"), tmp.Protein);
					input[4].Format(_T("%.1lf"), tmp.Fat);
					input[5].Format(_T("%.1lf"), tmp.Cholest);
					input[6].Format(_T("%.1lf"), tmp.Fiber);
					input[7].Format(_T("%.1lf"), tmp.Na);
					input[8] = tmp.foodname;
					break;
				}
			}
			m_pMoreDlg->SetDlgItemText(ID_D2_Amount_Edit, input[1]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Carbo_Edit, input[2]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Protein_Edit, input[3]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Fat_Edit, input[4]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Cholest_Edit, input[5]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Fiber_Edit, input[6]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Na_Edit, input[7]);
			m_pMoreDlg->SetDlgItemText(ID_D2_Name_Edit, name);
			m_pMoreDlg->SetDlgItemText(ID_D2_Kcal_Edit, input[0]);
			m_pMoreDlg->m_Meal_combo.SetCurSel(3);
		}
	}
	SYSTEMTIME date;
	pView->m_date.GetCurSel(&date);
	CString m_Info_Date;
	m_Info_Date.Format(_T("%4d-%2d-%2d"), date.wYear,
		date.wMonth, date.wDay);
	m_pMoreDlg->SetDlgItemText(ID_D2_Date_Edit, m_Info_Date);
	//int select_tab = m_Tab.GetCurSel();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCDiet1View::OnBnClickedButton2()
{
	int select_tab;
	int nIndex;
	CString str;
	CString name;
	POSITION  pos;
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFCDiet1Doc * pDoc = (CMFCDiet1Doc *)pFrame->GetActiveDocument();
	Food tmp;
//	CString str;
	CString input[9];
	CString tmp_name;
	int meal;
	m_pShowInfoDlg = new CShowInfoDialog();
	m_pShowInfoDlg->m_pView = this;
	m_pShowInfoDlg->Create(IDD_SHOWINFO);
	m_pShowInfoDlg->ShowWindow(SW_SHOW);
	buttonstate = 2;
	select_tab = m_Tab.GetCurSel();

	if(select_tab == 0){
		nIndex = m_pDialog1->m_List1.GetCurSel();
		if (LB_ERR != nIndex) {
			m_pDialog1->m_List1.GetText(nIndex, str);
			AfxExtractSubString(name, str, 0, ' ');

			pos = pDoc->list.GetHeadPosition();
			for (int i = 0; i < pDoc->list.GetCount(); i++) {
				tmp = (Food)pDoc->list.GetNext(pos);
				int meal;
				tmp_name = tmp.foodname;
				meal = tmp.time;
				if (!name.Compare(tmp_name) && meal == 0) {
					input[0].Format(_T("%.1lf"), tmp.cal);
					input[1].Format(_T("%.1lf"), tmp.plate);
					input[2].Format(_T("%.1lf"), tmp.Carbo);
					input[3].Format(_T("%.1lf"), tmp.Protein);
					input[4].Format(_T("%.1lf"), tmp.Fat);
					input[5].Format(_T("%.1lf"), tmp.Cholest);
					input[6].Format(_T("%.1lf"), tmp.Fiber);
					input[7].Format(_T("%.1lf"), tmp.Na);
					input[8] = tmp.foodname;
					break;
				}
			}
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Amount_Edit, input[1]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Carbo_Edit, input[2]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Protein_Edit, input[3]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Fat_Edit, input[4]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Cholest_Edit, input[5]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Fiber_Edit, input[6]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Na_Edit, input[7]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Name_Edit, name);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Kcal_Edit, input[0]);
			m_pShowInfoDlg->m_D1_EDIT_Name = name;
			input[0].Format(_T("%.1lf"), tmp.cal/tmp.plate);
			input[1].Format(_T("%.1lf"), tmp.plate/ tmp.plate);
			input[2].Format(_T("%.1lf"), tmp.Carbo / tmp.plate);
			input[3].Format(_T("%.1lf"), tmp.Protein / tmp.plate);
			input[4].Format(_T("%.1lf"), tmp.Fat / tmp.plate);
			input[5].Format(_T("%.1lf"), tmp.Cholest / tmp.plate);
			input[6].Format(_T("%.1lf"), tmp.Fiber / tmp.plate);
			input[7].Format(_T("%.1lf"), tmp.Na / tmp.plate);
			m_pShowInfoDlg->m_Info_Combo.SetCurSel(0);
			m_pShowInfoDlg->m_Info_Calory = input[0];
			m_pShowInfoDlg->m_Info_Carbo = input[2];
			m_pShowInfoDlg->m_Info_Protein = input[3];
			m_pShowInfoDlg->m_Info_Fat = input[4];
			m_pShowInfoDlg->m_Info_Cholest = input[5];
			m_pShowInfoDlg->m_Info_Fiber = input[6];
			m_pShowInfoDlg->m_Info_Na = input[7];
		}
	}
	if (select_tab == 1) {
		nIndex = m_pDialog2->m_List2.GetCurSel();
		if (LB_ERR != nIndex) {
			m_pDialog2->m_List2.GetText(nIndex, str);
			AfxExtractSubString(name, str, 0, ' ');

			pos = pDoc->list.GetHeadPosition();
			for (int i = 0; i < pDoc->list.GetCount(); i++) {
				tmp = (Food)pDoc->list.GetNext(pos);
				int meal;
				tmp_name = tmp.foodname;
				meal = tmp.time;
				if (!name.Compare(tmp_name) && meal == 1) {
					input[0].Format(_T("%.1lf"), tmp.cal);
					input[1].Format(_T("%.1lf"), tmp.plate);
					input[2].Format(_T("%.1lf"), tmp.Carbo);
					input[3].Format(_T("%.1lf"), tmp.Protein);
					input[4].Format(_T("%.1lf"), tmp.Fat);
					input[5].Format(_T("%.1lf"), tmp.Cholest);
					input[6].Format(_T("%.1lf"), tmp.Fiber);
					input[7].Format(_T("%.1lf"), tmp.Na);
					input[8] = tmp.foodname;
					break;
				}
			}
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Amount_Edit, input[1]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Carbo_Edit, input[2]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Protein_Edit, input[3]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Fat_Edit, input[4]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Cholest_Edit, input[5]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Fiber_Edit, input[6]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Na_Edit, input[7]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Name_Edit, name);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Kcal_Edit, input[0]);
			input[0].Format(_T("%.1lf"), tmp.cal / tmp.plate);
			input[1].Format(_T("%.1lf"), tmp.plate / tmp.plate);
			input[2].Format(_T("%.1lf"), tmp.Carbo / tmp.plate);
			input[3].Format(_T("%.1lf"), tmp.Protein / tmp.plate);
			input[4].Format(_T("%.1lf"), tmp.Fat / tmp.plate);
			input[5].Format(_T("%.1lf"), tmp.Cholest / tmp.plate);
			input[6].Format(_T("%.1lf"), tmp.Fiber / tmp.plate);
			input[7].Format(_T("%.1lf"), tmp.Na / tmp.plate);
			m_pShowInfoDlg->m_Info_Combo.SetCurSel(1);
			m_pShowInfoDlg ->m_D1_EDIT_Name = name;
			m_pShowInfoDlg->m_Info_Calory = input[0];
			m_pShowInfoDlg->m_Info_Carbo = input[2];
			m_pShowInfoDlg->m_Info_Protein = input[3];
			m_pShowInfoDlg->m_Info_Fat = input[4];
			m_pShowInfoDlg->m_Info_Cholest = input[5];
			m_pShowInfoDlg->m_Info_Fiber = input[6];
			m_pShowInfoDlg->m_Info_Na = input[7];
		}
	}

	if (select_tab == 2) {
		nIndex = m_pDialog3->m_List3.GetCurSel();
		if (LB_ERR != nIndex) {
			m_pDialog3->m_List3.GetText(nIndex, str);
			AfxExtractSubString(name, str, 0, ' ');

			pos = pDoc->list.GetHeadPosition();
			for (int i = 0; i < pDoc->list.GetCount(); i++) {
				tmp = (Food)pDoc->list.GetNext(pos);
				int meal;
				tmp_name = tmp.foodname;
				meal = tmp.time;
				if (!name.Compare(tmp_name) && meal == 2) {
					input[0].Format(_T("%.1lf"), tmp.cal);
					input[1].Format(_T("%.1lf"), tmp.plate);
					input[2].Format(_T("%.1lf"), tmp.Carbo);
					input[3].Format(_T("%.1lf"), tmp.Protein);
					input[4].Format(_T("%.1lf"), tmp.Fat);
					input[5].Format(_T("%.1lf"), tmp.Cholest);
					input[6].Format(_T("%.1lf"), tmp.Fiber);
					input[7].Format(_T("%.1lf"), tmp.Na);
					input[8] = tmp.foodname;
					break;
				}
			}
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Amount_Edit, input[1]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Carbo_Edit, input[2]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Protein_Edit, input[3]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Fat_Edit, input[4]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Cholest_Edit, input[5]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Fiber_Edit, input[6]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Na_Edit, input[7]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Name_Edit, name);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Kcal_Edit, input[0]);
			input[0].Format(_T("%.1lf"), tmp.cal / tmp.plate);
			input[1].Format(_T("%.1lf"), tmp.plate / tmp.plate);
			input[2].Format(_T("%.1lf"), tmp.Carbo / tmp.plate);
			input[3].Format(_T("%.1lf"), tmp.Protein / tmp.plate);
			input[4].Format(_T("%.1lf"), tmp.Fat / tmp.plate);
			input[5].Format(_T("%.1lf"), tmp.Cholest / tmp.plate);
			input[6].Format(_T("%.1lf"), tmp.Fiber / tmp.plate);
			input[7].Format(_T("%.1lf"), tmp.Na / tmp.plate);
			m_pShowInfoDlg->m_Info_Combo.SetCurSel(2);
			m_pShowInfoDlg->m_D1_EDIT_Name = name;
			m_pShowInfoDlg->m_Info_Calory = input[0];
			m_pShowInfoDlg->m_Info_Carbo = input[2];
			m_pShowInfoDlg->m_Info_Protein = input[3];
			m_pShowInfoDlg->m_Info_Fat = input[4];
			m_pShowInfoDlg->m_Info_Cholest = input[5];
			m_pShowInfoDlg->m_Info_Fiber = input[6];
			m_pShowInfoDlg->m_Info_Na = input[7];
		}
	}

	if (select_tab == 3) {
		nIndex = m_pDialog4->m_List4.GetCurSel();
		if (LB_ERR != nIndex) {
			m_pDialog4->m_List4.GetText(nIndex, str);
			AfxExtractSubString(name, str, 0, ' ');

			pos = pDoc->list.GetHeadPosition();
			for (int i = 0; i < pDoc->list.GetCount(); i++) {
				tmp = (Food)pDoc->list.GetNext(pos);
				int meal;
				tmp_name = tmp.foodname;
				meal = tmp.time;
				if (!name.Compare(tmp_name) && meal == 3) {
					input[0].Format(_T("%.1lf"), tmp.cal);
					input[1].Format(_T("%.1lf"), tmp.plate);
					input[2].Format(_T("%.1lf"), tmp.Carbo);
					input[3].Format(_T("%.1lf"), tmp.Protein);
					input[4].Format(_T("%.1lf"), tmp.Fat);
					input[5].Format(_T("%.1lf"), tmp.Cholest);
					input[6].Format(_T("%.1lf"), tmp.Fiber);
					input[7].Format(_T("%.1lf"), tmp.Na);
					input[8] = tmp.foodname;
					break;
				}
			}
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Amount_Edit, input[1]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Carbo_Edit, input[2]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Protein_Edit, input[3]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Fat_Edit, input[4]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Cholest_Edit, input[5]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Fiber_Edit, input[6]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Na_Edit, input[7]);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Name_Edit, name);
			m_pShowInfoDlg->SetDlgItemText(ID_D1_Kcal_Edit, input[0]);
			input[0].Format(_T("%.1lf"), tmp.cal / tmp.plate);
			input[1].Format(_T("%.1lf"), tmp.plate / tmp.plate);
			input[2].Format(_T("%.1lf"), tmp.Carbo / tmp.plate);
			input[3].Format(_T("%.1lf"), tmp.Protein / tmp.plate);
			input[4].Format(_T("%.1lf"), tmp.Fat / tmp.plate);
			input[5].Format(_T("%.1lf"), tmp.Cholest / tmp.plate);
			input[6].Format(_T("%.1lf"), tmp.Fiber / tmp.plate);
			input[7].Format(_T("%.1lf"), tmp.Na / tmp.plate);
			m_pShowInfoDlg->m_Info_Combo.SetCurSel(3);
			m_pShowInfoDlg->m_D1_EDIT_Name = name;
			m_pShowInfoDlg->m_Info_Calory = input[0];
			m_pShowInfoDlg->m_Info_Carbo = input[2];
			m_pShowInfoDlg->m_Info_Protein = input[3];
			m_pShowInfoDlg->m_Info_Fat = input[4];
			m_pShowInfoDlg->m_Info_Cholest = input[5];
			m_pShowInfoDlg->m_Info_Fiber = input[6];
			m_pShowInfoDlg->m_Info_Na = input[7];
		}
	}
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCDiet1View::OnBnClickedButtonUserinfo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMFCDiet1Doc* pDoc = GetDocument();
	CUserInfoDlg dlg;
	dlg.DoModal();

	while (pDoc->user.age == 0 || pDoc->user.length < 0.001 || pDoc->user.weight < 0.001)
		dlg.DoModal();

	CString str;
	int exeState;

	if (pDoc->user.exercise == 1)
		exeState = 25;
	else if (pDoc->user.exercise == 2)
		exeState = 32;
	else if (pDoc->user.exercise == 3)
		exeState = 40;

	str.Format(_T("%.2lf"), (pDoc->user.length - 100)*0.9*exeState);
	m_encour_cal.SetWindowTextW(str);
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
	m_pDialog1->ShowWindow(SW_SHOW);
	m_pDialog2->ShowWindow(SW_HIDE);
	m_pDialog3->ShowWindow(SW_HIDE);
	m_pDialog4->ShowWindow(SW_HIDE);

	*pResult = 0;

	totalCarbo = 0;
	totalProtein = 0;
	totalFat = 0;
	totalCholest = 0;
	totalFiber = 0;
	totalNa = 0;

	CString str;

	// Calender에 선택된 날짜정보를 얻는다.
	m_date.GetCurSel(&date);

	CMFCDiet1Doc *pDoc = GetDocument();

	tmp.date_day = date.wDay;
	tmp.date_month = date.wMonth;
	tmp.date_year = date.wYear;

	SumTotalCalorie(pDoc);

	m_pDialog1->m_List1.ResetContent();
	m_pDialog2->m_List2.ResetContent();
	m_pDialog3->m_List3.ResetContent();
	m_pDialog4->m_List4.ResetContent();


	ShowFoodList(pDoc);
	
}


void CMFCDiet1View::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDlgTab01 *Tab1;
	//m_pDialog1 = new CDlgTab01;
	CMFCDiet1Doc *pDoc = GetDocument();
	m_date.GetCurSel(&date);
	tmp.date_day = date.wDay;
	tmp.date_month = date.wMonth;
	tmp.date_year = date.wYear;
	buttonstate = 9;
	//else {
		m_pShowInfoDlg = new CShowInfoDialog();
		m_pShowInfoDlg->m_pView = this;
		m_pShowInfoDlg->meal = tmp.time;
		m_pShowInfoDlg->Create(IDD_SHOWINFO);
		m_pShowInfoDlg->ShowWindow(SW_SHOW);
	//}// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	//CMFCDiet1Doc *pDoc = GetDocument();
	//Food tmp;
	//CShowInfoDialog dlg;
	//m_pShowInfoDlg ->DoModal();
	CString str;
	

	CString SelectDate;
	

	
	SumTotalCalorie(pDoc);
}

void CMFCDiet1View::OnBnClickedButton3()             //삭제 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int index;
	CString str, findName;
	CMFCDiet1Doc * pDoc = GetDocument();
	Food pfood;

	if (m_Tab.GetCurSel()==0)
	{
		index = m_pDialog1->m_List1.GetCurSel();
		if (LB_ERR != index)
		{
			m_pDialog1->m_List1.GetText(index, str);
			AfxExtractSubString(findName, str, 0, ' ');

			POSITION pos = pDoc->list.GetHeadPosition();

			while (pos != NULL) {
				pfood = pDoc->list.GetAt(pos);
				if (!findName.Compare(pfood.foodname) && pfood.date_day == date.wDay && pfood.date_month == date.wMonth && pfood.date_year == date.wYear && pfood.time == 0)
				{
					pDoc->list.RemoveAt(pos);
					break;
				}
				pfood = pDoc->list.GetNext(pos);
			}
			m_pDialog1->m_List1.DeleteString(index);
			c_edit1.SetWindowText(_T(""));
			c_edit2.SetWindowText(_T(""));
			c_edit3.SetWindowText(_T(""));
		}
	}
	else if (m_Tab.GetCurSel() == 1)
	{
		index = m_pDialog2->m_List2.GetCurSel();
		if (LB_ERR != index)
		{
			m_pDialog2->m_List2.GetText(index, str);
			AfxExtractSubString(findName, str, 0, ' ');

			POSITION pos = pDoc->list.GetHeadPosition();

			while (pos != NULL) {
				pfood = pDoc->list.GetAt(pos);
				if (!findName.Compare(pfood.foodname) && pfood.date_day == date.wDay && pfood.date_month == date.wMonth && pfood.date_year == date.wYear && pfood.time == 1)
				{
					pDoc->list.RemoveAt(pos);
					break;
				}
				pfood = pDoc->list.GetNext(pos);
			}
			m_pDialog2->m_List2.DeleteString(index);
			c_edit1.SetWindowText(_T(""));
			c_edit2.SetWindowText(_T(""));
			c_edit3.SetWindowText(_T(""));
		}
	}
	else if (m_Tab.GetCurSel() == 2)
	{
		index = m_pDialog3->m_List3.GetCurSel();
		if (LB_ERR != index)
		{
			m_pDialog3->m_List3.GetText(index, str);
			AfxExtractSubString(findName, str, 0, ' ');
		
			POSITION pos = pDoc->list.GetHeadPosition();

			while (pos != NULL) {
				pfood = pDoc->list.GetAt(pos);
				if (!findName.Compare(pfood.foodname) && pfood.date_day == date.wDay && pfood.date_month == date.wMonth && pfood.date_year == date.wYear && pfood.time == 2)
				{
					pDoc->list.RemoveAt(pos);
					break;
				}
				pfood = pDoc->list.GetNext(pos);
			}
			m_pDialog3->m_List3.DeleteString(index);
			c_edit1.SetWindowText(_T(""));
			c_edit2.SetWindowText(_T(""));
			c_edit3.SetWindowText(_T(""));
		}
	}
	else if (m_Tab.GetCurSel() == 3)
	{
		index = m_pDialog4->m_List4.GetCurSel();
		if (LB_ERR != index)
		{
			m_pDialog4->m_List4.GetText(index, str);
			AfxExtractSubString(findName, str, 0, ' ');

			POSITION pos = pDoc->list.GetHeadPosition();

			while (pos != NULL) {
				pfood = pDoc->list.GetAt(pos);
				if (!findName.Compare(pfood.foodname) && pfood.date_day == date.wDay && pfood.date_month == date.wMonth && pfood.date_year == date.wYear && pfood.time == 3)
				{
					pDoc->list.RemoveAt(pos);
					break;
				}
				pfood = pDoc->list.GetNext(pos);
			}
			m_pDialog4->m_List4.DeleteString(index);
			c_edit1.SetWindowText(_T(""));
			c_edit2.SetWindowText(_T(""));
			c_edit3.SetWindowText(_T(""));
		}
	}

	SumTotalCalorie(pDoc);
	ShowFoodList(pDoc);

	///////리스트 내 원소 삭제 여부를 길이로 알려주는 테스트 코드///////
	CString test;
	test.Format(_T("FoodName: %s, List Length: %d"), findName, pDoc->list.GetSize());
	AfxMessageBox(test);
}


void CMFCDiet1View::SumTotalCalorie(CMFCDiet1Doc* pDoc)
{
	POSITION pos = pDoc->list.GetHeadPosition();
	Food pfood;
	totalCalorie = 0;

	while (pos != NULL) {
		pfood = pDoc->list.GetAt(pos);
		if (pfood.date_day == date.wDay && pfood.date_month == date.wMonth && pfood.date_year == date.wYear)
		{
			totalCalorie += pfood.cal;
		}
		pfood = pDoc->list.GetNext(pos);
	}
	CString str;
	str.Format(_T("%.2lf"), totalCalorie);
	m_total_cal.SetWindowText(str);
}


void CMFCDiet1View::OnClose()
{
	CMFCDiet1Doc* pDoc = GetDocument();
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	CFormView::OnClose();
}


void CMFCDiet1View::OnDestroy()
{
	CFormView::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CMFCDiet1Doc* pDoc = GetDocument();
	CStdioFile file;
	CFileException e;
	if (!file.Open(_T("my.dat"), CFile::modeWrite | CFile::modeCreate, &e))
	{
		e.ReportError();
		return;
	}


	/////////////종료시 뷰 파괴 전 저장//////////////////
	CString str;
	Food pfood;
	POSITION pos = pDoc->list.GetHeadPosition();

	str.Format(_T("%d %f %f %d %d"), pDoc->user.age, pDoc->user.length, pDoc->user.weight, pDoc->user.gender, pDoc->user.exercise);
	file.WriteString(str + "\n");

	while (pos != NULL)
	{
		pfood = pDoc->list.GetAt(pos);
		str.Format(_T("%d %d %d %d %s %lf %lf %lf %lf %lf %lf %lf %lf"),
			pfood.date_day, pfood.date_month, pfood.date_year, pfood.time,
			pfood.foodname, pfood.plate, pfood.cal, pfood.Carbo, pfood.Protein, pfood.Fat, pfood.Cholest, pfood.Fiber, pfood.Na);
		file.WriteString(str + "\n");
		pfood = pDoc->list.GetNext(pos);
	}

	file.Close();
}


void CMFCDiet1View::ShowFoodList(CMFCDiet1Doc* pDoc)
{
	POSITION pos = pDoc->list.GetHeadPosition();

	totalCarbo = 0;
	totalProtein = 0;
	totalFat = 0;
	totalCholest = 0;
	totalFiber = 0;
	totalNa = 0;

	m_pDialog1->m_List1.ResetContent();
	m_pDialog2->m_List2.ResetContent();
	m_pDialog3->m_List3.ResetContent();
	m_pDialog4->m_List4.ResetContent();

	while (pos != NULL) {
		tmp = pDoc->list.GetAt(pos);
		str.Format(_T("%s   %.3lfkcal  %.2lf인분"), tmp.foodname, tmp.cal, tmp.plate);

		if (tmp.date_day == date.wDay && tmp.date_month == date.wMonth && tmp.date_year == date.wYear) {
			if (tmp.time == 0)
				m_pDialog1->m_List1.AddString(str);
			else if (tmp.time == 1)
				m_pDialog2->m_List2.AddString(str);
			else if (tmp.time == 2)
				m_pDialog3->m_List3.AddString(str);
			else if (tmp.time == 3)
				m_pDialog4->m_List4.AddString(str);

			totalCarbo += tmp.Carbo;
			totalProtein += tmp.Protein;
			totalFat += tmp.Fat;
			totalCholest += (tmp.Cholest)/1000;
			totalFiber += tmp.Fiber;
			totalNa += (tmp.Na)/1000;
		}
		tmp = pDoc->list.GetNext(pos);
	}
}


void CMFCDiet1View::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDCtl == ID_SHOWINFO || nIDCtl == IDC_BUTTON2 || nIDCtl == IDC_BUTTON3 || nIDCtl == IDC_BUTTON9)
	{
		CDC dc;
		RECT rect;
		dc.Attach(lpDrawItemStruct->hDC);	//Get the Button DC to CDC

		rect = lpDrawItemStruct->rcItem;	//Store the Button rect to local rect
		dc.Draw3dRect(&rect, RGB(200, 200, 200), RGB(20, 20, 20));
		dc.FillSolidRect(&rect, RGB(100, 100, 100));

		//Show the Effect of Click Event
		UINT state = lpDrawItemStruct->itemState;
		if ((state & ODS_SELECTED))
		{
			dc.DrawEdge(&rect, EDGE_SUNKEN, BF_RECT);
		}
		else
		{
			dc.DrawEdge(&rect, EDGE_RAISED, BF_RECT);
		}

		//Draw Color Text
		dc.SetBkColor(RGB(100, 100, 100));		//Setting the Text Background Color
		dc.SetTextColor(RGB(255, 255, 255));		//Setting the Text Color

		TCHAR buffer[MAX_PATH];
		ZeroMemory(buffer, MAX_PATH);
		::GetWindowText(lpDrawItemStruct->hwndItem, buffer, MAX_PATH);

		dc.DrawText(buffer, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		dc.Detach();							//Detach the Button DC
	}
}
