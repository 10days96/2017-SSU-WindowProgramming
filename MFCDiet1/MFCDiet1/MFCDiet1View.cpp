
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
END_MESSAGE_MAP()

// CMFCDiet1View ����/�Ҹ�

CMFCDiet1View::CMFCDiet1View()
	: CFormView(IDD_MFCDIET1_FORM)
	, m_edit1(_T(""))
	, m_edit2(_T(""))
	, m_edit3(_T(""))
{
	m_pShowInfoDlg = NULL;
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
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
}

//BOOL CMFCDiet1View::PreCreateWindow(CREATESTRUCT& cs)
//{
//	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
//	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.
//
//	return CFormView::PreCreateWindow(cs);
//}

void CMFCDiet1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_Tab.DeleteAllItems();
	m_Tab.InsertItem(0, L"��ħ", 0);
	m_Tab.InsertItem(1, L"����", 0);
	m_Tab.InsertItem(2, L"����", 0);
	m_Tab.InsertItem(3, L"����", 0);

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
		e.ReportError();
		return;
	}

	///////////////�ҷ�����///////////////////
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
		inputFood.foodname = str;                //�ѱ� ����
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


void CMFCDiet1View::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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

	// Calender�� ���õ� ��¥������ ��´�.
	m_date.GetCurSel(&date);

	CMFCDiet1Doc *pDoc = GetDocument();
	//Food tmp;

	tmp.date_day = date.wDay;
	tmp.date_month = date.wMonth;
	tmp.date_year = date.wYear;

	SumTotalCalorie(pDoc);
	//str.Format(_T("%d �� %d �� %d ��"), date.wYear, date.wMonth, date.wDay);

	m_pDialog1->m_List1.ResetContent();
	m_pDialog2->m_List2.ResetContent();
	m_pDialog3->m_List3.ResetContent();
	m_pDialog4->m_List4.ResetContent();

	POSITION pos = pDoc->list.GetHeadPosition();

	while (pos != NULL) {
		tmp = pDoc->list.GetAt(pos);
		str.Format(_T("%s   %.3lfkcal  %.2lf�κ�"), tmp.foodname, tmp.cal, tmp.plate);

		if (tmp.date_day == date.wDay && tmp.date_month == date.wMonth && tmp.date_year == date.wYear ) {
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
			totalCholest += tmp.Cholest;
			totalFiber += tmp.Fiber;
			totalNa += tmp.Na;
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

		tmp = pDoc->list.GetNext(pos);
	}
	
}


void CMFCDiet1View::OnBnClickedButton9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//CDlgTab01 *Tab1;
	//m_pDialog1 = new CDlgTab01;
	CMFCDiet1Doc *pDoc = GetDocument();

	//if (m_pShowInfoDlg != NULL) {
		//m_pShowInfoDlg->SetFocus();
		//AfxMessageBox(_T("ȣ��"));
	//}
	m_date.GetCurSel(&date);
	tmp.date_day = date.wDay;
	tmp.date_month = date.wMonth;
	tmp.date_year = date.wYear;
	//else {
		m_pShowInfoDlg = new CShowInfoDialog();
		m_pShowInfoDlg->m_pView = this;
		m_pShowInfoDlg->meal = tmp.time;
		m_pShowInfoDlg->Create(IDD_SHOWINFO);
		m_pShowInfoDlg->ShowWindow(SW_SHOW);
	//}// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	//CMFCDiet1Doc *pDoc = GetDocument();
	//Food tmp;
	//CShowInfoDialog dlg;
	//m_pShowInfoDlg ->DoModal();
	CString str;
	

	CString SelectDate;
	

	//c_edit1.GetWindowText(str);
	//str.Format(_T(" %s "), str);

	//tmp.foodname = str;

	//c_edit2.GetWindowText(str);
	//double input_cal = _wtof(str);
	//tmp.cal = input_cal;

	//tmp.a_date = date;

	//c_edit3.GetWindowText(str);
	//double input_plate = _wtof(str);
	//tmp.plate = input_plate;
	//pDoc->list.AddTail(tmp);

		
	/*str.Format(_T("%s     %.3lfkcal     %.2lf�κ�"), tmp.foodname, tmp.cal, tmp.plate);
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
	//}*/
	SumTotalCalorie(pDoc);
}


//void CMFCDiet1View::OnNMClickTab1(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//	int selectTab = m_Tab.GetCurSel();
//	*pResult = 0;
//}


void CMFCDiet1View::OnBnClickedButton3()             //���� ��ư
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
				if (!findName.Compare(pfood.foodname) && tmp.date_year == pfood.date_year && tmp.date_month == pfood.date_month && tmp.date_day == pfood.date_day && pfood.time == 0)
				{
					pDoc->list.RemoveAt(pos);
					break;
				}
				pfood = pDoc->list.GetNext(pos);
			}
			m_pDialog1->m_List1.DeleteString(index);
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
				if (!findName.Compare(pfood.foodname) && tmp.date_year == pfood.date_year && tmp.date_month == pfood.date_month && tmp.date_day == pfood.date_day && pfood.time == 1)
				{
					pDoc->list.RemoveAt(pos);
					break;
				}
				pfood = pDoc->list.GetNext(pos);
			}
			m_pDialog2->m_List2.DeleteString(index);
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
				if (!findName.Compare(pfood.foodname) && tmp.date_year == pfood.date_year && tmp.date_month == pfood.date_month && tmp.date_day == pfood.date_day && pfood.time == 2)
				{
					pDoc->list.RemoveAt(pos);
					break;
				}
				pfood = pDoc->list.GetNext(pos);
			}
			m_pDialog3->m_List3.DeleteString(index);
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
				if (!findName.Compare(pfood.foodname) && tmp.date_year == pfood.date_year && tmp.date_month == pfood.date_month && tmp.date_day == pfood.date_day && pfood.time == 3)
				{
					pDoc->list.RemoveAt(pos);
					break;
				}
				pfood = pDoc->list.GetNext(pos);
			}
			m_pDialog4->m_List4.DeleteString(index);
		}
	}

	///////����Ʈ �� ���� ���� ���θ� ���̷� �˷��ִ� �׽�Ʈ �ڵ�///////
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
		if (tmp.date_year == pfood.date_year && tmp.date_month == pfood.date_month && tmp.date_day == pfood.date_day)
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	CFormView::OnClose();
}


void CMFCDiet1View::OnDestroy()
{
	CFormView::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	CMFCDiet1Doc* pDoc = GetDocument();
	CStdioFile file;
	CFileException e;
	if (!file.Open(_T("my.dat"), CFile::modeWrite | CFile::modeCreate, &e))
	{
		e.ReportError();
		return;
	}


	/////////////����� �� �ı� �� ����//////////////////
	CString str;
	Food pfood;
	POSITION pos = pDoc->list.GetHeadPosition();

	str.Format(_T("%d %f %f %d %d"), pDoc->user.age, pDoc->user.length, pDoc->user.weight, pDoc->user.gender, pDoc->user.exercise);
	file.WriteString(str + "\n");

	while (pos != NULL)
	{
		AfxMessageBox(_T("������"));
		pfood = pDoc->list.GetAt(pos);
		str.Format(_T("%d %d %d %d %s %lf %lf %lf %lf %lf %lf %lf %lf %lf"),
			pfood.date_day, pfood.date_month, pfood.date_year, pfood.time,
			pfood.foodname, pfood.plate, pfood.cal, pfood.Carbo, pfood.Protein, pfood.Fat, pfood.Cholest, pfood.Fiber, pfood.Na);
		file.WriteString(str + "\n");
		pfood = pDoc->list.GetNext(pos);
	}

	file.Close();
}
