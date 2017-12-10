// ShowInfoDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "ShowInfoDialog.h"
#include "afxdialogex.h"
#include "MFCDiet1Doc.h"
#include "MFCDiet1View.h"
#include "MainFrm.h"
#include <locale.h>
#include "MoreDlg.h"
#include <Windows.h>
#include "SearchListDlg.h"


// CShowInfoDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CShowInfoDialog, CDialog)

CShowInfoDialog::CShowInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SHOWINFO, pParent)
	, m_D1_EDIT_Name(_T(""))
	//, m_Info_Amount(1)
	, m_Info_Amount(_T("1"))
	, m_Info_Date(_T(""))
	, m_Info_Calory(_T(""))
	, m_Info_Carbo(_T(""))
	, m_Info_Protein(_T(""))
	, m_Info_Fat(_T(""))
	, m_Info_Cholest(_T(""))
	, m_Info_Fiber(_T(""))
	, m_Info_Na(_T(""))
{
	//check_input = TRUE;
}

CShowInfoDialog::~CShowInfoDialog()
{
}

void CShowInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, ID_D1_Name_Edit, m_D1_EDIT_Name);
	DDX_Text(pDX, ID_D1_Amount_Edit, m_Info_Amount);
	DDX_Text(pDX, ID_D1_Carbo_Edit, m_Info_Carbo);
	DDX_Text(pDX, ID_D1_Protein_Edit, m_Info_Protein);
	DDX_Text(pDX, ID_D1_Fat_Edit, m_Info_Fat);
	DDX_Text(pDX, ID_D1_Cholest_Edit, m_Info_Cholest);
	DDX_Text(pDX, ID_D1_Fiber_Edit, m_Info_Fiber);
	DDX_Text(pDX, ID_D1_Na_Edit, m_Info_Na);
	DDX_Text(pDX, ID_D1_Kcal_Edit, m_Info_Calory);
	DDX_Text(pDX, ID_D1_Amount_Edit, m_Info_Amount);
	DDX_Text(pDX, ID_D1_Date_Edit, m_Info_Date);
	DDX_Control(pDX, ID_D1_Meal_combo, m_Info_Combo);
	DDX_Text(pDX, ID_D1_Kcal_Edit, m_Info_Calory);
	DDX_Text(pDX, ID_D1_Carbo_Edit, m_Info_Carbo);
	DDX_Text(pDX, ID_D1_Protein_Edit, m_Info_Protein);
	DDX_Text(pDX, ID_D1_Fat_Edit, m_Info_Fat);
	DDX_Text(pDX, ID_D1_Cholest_Edit, m_Info_Cholest);
	DDX_Text(pDX, ID_D1_Fiber_Edit, m_Info_Fiber);
	DDX_Text(pDX, ID_D1_Na_Edit, m_Info_Na);
}


BEGIN_MESSAGE_MAP(CShowInfoDialog, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_D1_Search, &CShowInfoDialog::OnBnClickedD1Search)
	ON_BN_CLICKED(IDC_D1_Search, &CShowInfoDialog::OnBnClickedD1Search)
	ON_EN_CHANGE(ID_D1_Amount_Edit, &CShowInfoDialog::OnEnChangeD1AmountEdit)
	ON_BN_CLICKED(IDOK, &CShowInfoDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CShowInfoDialog::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_RESET, &CShowInfoDialog::OnBnClickedReset)
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// CShowInfoDialog �޽��� ó�����Դϴ�.


void CShowInfoDialog::OnBnClickedD1Search()
{
	UpdateData(TRUE);
	CSearchListDlg sdlg;
	CString str;
	CStdioFile file;
	CString Find_Name, foodName;
	CString calory[7];
	CString Amount;
	int count = 0;
	BOOL showSdlg = FALSE;

	GetDlgItemText(ID_D1_Name_Edit,Find_Name);
	if (!Find_Name.Compare(_T(""))) {
		AfxMessageBox(_T("�̸��� �Է� ���ּ���."));
		return;
	};
	//m_D1_EDIT_Name = Find_Name;

	///////////////////////////////SearchListDlg ����//////////////////////////////////
	sdlg.selectedName = Find_Name;
	setlocale(LC_ALL, "");
	file.Open(_T("calory1.txt"),CFile::modeRead);
	while (file.ReadString(str)) {
		if (str.Find(Find_Name) != -1) {
			AfxExtractSubString(foodName, str, 0, ',');
			sdlg.foodNameList.AddTail(foodName);
		}
	}
	if (sdlg.foodNameList.GetCount() == 0)
		AfxMessageBox(_T("�˻� ����� �����ϴ�."));
	else
	{
		sdlg.DoModal();
		Find_Name = sdlg.selectedName;
	}

	m_D1_EDIT_Name = Find_Name;
	SetDlgItemText(ID_D1_Name_Edit, Find_Name);

	/////////////////////////////SearchListDlg�� ���� �̸��� ���õ� ��쿡�� �Ĵ� �˻�//////////////////////
	if (sdlg.whichButton)
	{
		file.SeekToBegin();
		while (file.ReadString(str)) {
			AfxExtractSubString(foodName, str, 0, ',');
			if (!Find_Name.Compare(foodName)) {
				AfxExtractSubString(calory[0], str, 1, ',');
				m_Info_Calory = calory[0];
				SetDlgItemText(ID_D1_Kcal_Edit, calory[0]);

				AfxExtractSubString(calory[1], str, 2, ',');
				m_Info_Carbo = calory[1];
				SetDlgItemText(ID_D1_Carbo_Edit, calory[1]);

				AfxExtractSubString(calory[2], str, 3, ',');
				m_Info_Protein = calory[2];
				SetDlgItemText(ID_D1_Protein_Edit, calory[2]);

				AfxExtractSubString(calory[3], str, 4, ',');
				m_Info_Fat = calory[3];
				SetDlgItemText(ID_D1_Fat_Edit, calory[3]);

				AfxExtractSubString(calory[4], str, 5, ',');
				m_Info_Cholest = calory[4];
				SetDlgItemText(ID_D1_Cholest_Edit, calory[4]);

				AfxExtractSubString(calory[5], str, 6, ',');
				m_Info_Fiber = calory[5];
				SetDlgItemText(ID_D1_Fiber_Edit, calory[5]);

				AfxExtractSubString(calory[6], str, 7, ',');
				m_Info_Na = calory[6];
				SetDlgItemText(ID_D1_Na_Edit, calory[6]);

				m_Info_Amount = _T("1.0");
				SetDlgItemText(ID_D1_Amount_Edit, _T("1.0"));
				break;
			}
		}
	}
	file.Close();
	
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CShowInfoDialog::OnEnChangeD1AmountEdit(){
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString Amount;
	double amount = 0;
	CString calory[7];
	CString str;
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFCDiet1View* pView = (CMFCDiet1View *)pFrame->GetActiveView();
	double Info[7];
	CString name;// = m_D1_EDIT_Name;
	CString calory1[7];
	GetDlgItemText(ID_D1_Name_Edit,name);
	GetDlgItemText(ID_D1_Amount_Edit, Amount);
	GetDlgItemText(ID_D1_Kcal_Edit,calory1[0]);
	GetDlgItemText(ID_D1_Carbo_Edit,calory1[1]);
	GetDlgItemText(ID_D1_Protein_Edit, calory1[2]);
	GetDlgItemText(ID_D1_Fat_Edit,calory1[3]);
	GetDlgItemText(ID_D1_Cholest_Edit,calory1[4]);
	GetDlgItemText(ID_D1_Fiber_Edit,calory1[5]);
	GetDlgItemText(ID_D1_Na_Edit,calory1[6]);

	amount = _wtof(Amount);
	m_Info_Amount = Amount;
	if (pView->buttonstate == 2) {
		//GetDlgItem(ID_D1_Name_Edit)->SendMessage(EM_SETREADONLY,1,0);
		GetDlgItemText(ID_D1_Amount_Edit, Amount);
		SetDlgItemText(ID_D1_Name_Edit, name);

		UpdateData(FALSE);

		Info[0] = _wtof(m_Info_Calory)*amount;
		calory[0].Format(_T("%.1lf"), Info[0]);
		SetDlgItemText(ID_D1_Kcal_Edit, calory[0]);

		Info[1] = _wtof(m_Info_Carbo)*amount;
		calory[1].Format(_T("%.1lf"), Info[1]);
		SetDlgItemText(ID_D1_Carbo_Edit, calory[1]);

		Info[2] = _wtof(m_Info_Protein)*amount;
		calory[2].Format(_T("%.1lf"), Info[2]);
		SetDlgItemText(ID_D1_Protein_Edit, calory[2]);

		Info[3] = _wtof(m_Info_Fat)*amount;
		calory[3].Format(_T("%.1lf"), Info[3]);
		SetDlgItemText(ID_D1_Fat_Edit, calory[3]);

		Info[4] = _wtof(m_Info_Cholest)*amount;
		calory[4].Format(_T("%.1lf"), Info[4]);
		SetDlgItemText(ID_D1_Cholest_Edit, calory[4]);

		Info[5] = _wtof(m_Info_Fiber)*amount;
		calory[5].Format(_T("%.1lf"), Info[5]);
		SetDlgItemText(ID_D1_Fiber_Edit, calory[5]);

		Info[6] = _wtof(m_Info_Na)*amount;
		calory[6].Format(_T("%.1lf"), Info[6]);
		SetDlgItemText(ID_D1_Na_Edit, calory[6]);
	}
	

	else if (pView->buttonstate == 9) {
		UpdateData(FALSE);
			SetDlgItemText(ID_D1_Name_Edit, name);
			//����ڰ� �Է� �ϴ� ���
			if (_wtof(m_Info_Calory) == 0){
				m_Info_Calory = calory1[0];
				SetDlgItemText(ID_D1_Kcal_Edit,m_Info_Calory);
			}
			else {
				Info[0] = _wtof(m_Info_Calory)*amount;
				calory[0].Format(_T("%.1lf"), Info[0]);
				SetDlgItemText(ID_D1_Kcal_Edit, calory[0]);
			}

			if (_wtof(m_Info_Carbo) == 0 ){
				m_Info_Carbo = calory1[1];
				SetDlgItemText(ID_D1_Carbo_Edit, m_Info_Carbo);
			}
			else {
				Info[1] = _wtof(m_Info_Carbo)*amount;
				calory[1].Format(_T("%.1lf"), Info[1]);
				SetDlgItemText(ID_D1_Carbo_Edit, calory[1]);
			}

			if (_wtof(m_Info_Protein) == 0){
				m_Info_Protein = calory1[2];
				SetDlgItemText(ID_D1_Protein_Edit,m_Info_Protein);
			}

			else {
				Info[2] = _wtof(m_Info_Protein)*amount;
				calory[2].Format(_T("%.1lf"), Info[2]);
				SetDlgItemText(ID_D1_Protein_Edit, calory[2]);
			}
			if (_wtof(m_Info_Fat) == 0){
				m_Info_Fat = calory1[3];
				SetDlgItemText(ID_D1_Fat_Edit,m_Info_Fat);
			}

			else {
				Info[3] = _wtof(m_Info_Fat)*amount;
				calory[3].Format(_T("%.1lf"), Info[3]);
				SetDlgItemText(ID_D1_Fat_Edit, calory[3]);
			}

			if (_wtof(m_Info_Cholest) == 0){
				m_Info_Cholest = calory1[4];
				SetDlgItemText(ID_D1_Cholest_Edit,m_Info_Cholest);
			}

			else {
				Info[4] = _wtof(m_Info_Cholest)*amount;
				calory[4].Format(_T("%.1lf"), Info[4]);
				SetDlgItemText(ID_D1_Cholest_Edit, calory[4]);
			}

			if (_wtof(m_Info_Fiber) == 0){
				m_Info_Fiber = calory1[5];
				SetDlgItemText(ID_D1_Fiber_Edit,m_Info_Fiber);
			}

			else {
				Info[5] = _wtof(m_Info_Fiber)*amount;
				calory[5].Format(_T("%.1lf"), Info[5]);
				SetDlgItemText(ID_D1_Fiber_Edit, calory[5]);
			}

			if (_wtof(m_Info_Na) == 0){
				m_Info_Na = calory1[6];
				SetDlgItemText(ID_D1_Na_Edit,m_Info_Na);
			}

			else {
				Info[6] = _wtof(m_Info_Na)*amount;
				calory[6].Format(_T("%.1lf"), Info[6]);
				SetDlgItemText(ID_D1_Na_Edit, calory[6]);
			}
	}
}


void CShowInfoDialog::OnBnClickedOk()
{
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFCDiet1Doc * pDoc = (CMFCDiet1Doc *)pFrame->GetActiveDocument();
	CMFCDiet1View* m_pView = (CMFCDiet1View *)pFrame->GetActiveView();
	int nIndex = 0;
	CString name;
	CString str;
	SYSTEMTIME date;
	m_pView->m_date.GetCurSel(&date);

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	GetDlgItemText(ID_D1_Amount_Edit, m_Info_Amount);
	GetDlgItemText(ID_D1_Name_Edit, m_D1_EDIT_Name);
	GetDlgItemText(ID_D1_Kcal_Edit, m_Info_Calory);
	GetDlgItemText(ID_D1_Carbo_Edit, m_Info_Carbo);
	GetDlgItemText(ID_D1_Protein_Edit, m_Info_Protein);
	GetDlgItemText(ID_D1_Fat_Edit, m_Info_Fat);
	GetDlgItemText(ID_D1_Cholest_Edit, m_Info_Cholest);
	GetDlgItemText(ID_D1_Fiber_Edit, m_Info_Fiber);
	GetDlgItemText(ID_D1_Na_Edit, m_Info_Na);

	//////////////////////////�ߺ��� ���� �׸��� �̹� �����ϴ��� Ȯ��//////////////////////////
	bool check = TRUE;
	CString listFoodName, listFood;

	if (m_pView->buttonstate == 9)
	{
		if (m_Info_Combo.GetCurSel() == 0)
		{
			for (int i = 0; i < m_pView->m_pDialog1->m_List1.GetCount(); i++)
			{
				m_pView->m_pDialog1->m_List1.GetText(i, listFood);
				AfxExtractSubString(listFoodName, listFood, 0, ' ');

				if (!m_D1_EDIT_Name.Compare(listFoodName))
				{
					check = FALSE;
					break;
				}
			}
		}
		else if (m_Info_Combo.GetCurSel() == 1)
		{
			for (int i = 0; i < m_pView->m_pDialog2->m_List2.GetCount(); i++)
			{
				m_pView->m_pDialog2->m_List2.GetText(i, listFood);
				AfxExtractSubString(listFoodName, listFood, 0, ' ');

				if (!m_D1_EDIT_Name.Compare(listFoodName))
				{
					check = FALSE;
					break;
				}
			}
		}
		else if (m_Info_Combo.GetCurSel() == 2)
		{
			for (int i = 0; i < m_pView->m_pDialog3->m_List3.GetCount(); i++)
			{
				m_pView->m_pDialog3->m_List3.GetText(i, listFood);
				AfxExtractSubString(listFoodName, listFood, 0, ' ');

				if (!m_D1_EDIT_Name.Compare(listFoodName))
				{
					check = FALSE;
					break;
				}
			}
		}
		else if (m_Info_Combo.GetCurSel() == 3)
		{
			for (int i = 0; i < m_pView->m_pDialog4->m_List4.GetCount(); i++)
			{
				m_pView->m_pDialog4->m_List4.GetText(i, listFood);
				AfxExtractSubString(listFoodName, listFood, 0, ' ');

				if (!m_D1_EDIT_Name.Compare(listFoodName))
				{
					check = FALSE;
					break;
				}
			}
		}

		if (!check)
		{
			AfxMessageBox(_T("������ �̸��� ���� �׸��� �̹� �����մϴ�."));
			return;
		}
	}

	m_pView->tmp.foodname = m_D1_EDIT_Name;
	m_pView->tmp.plate = _wtof(m_Info_Amount);
	m_pView->tmp.cal = _wtof(m_Info_Calory);
	m_pView->tmp.Carbo = _wtof(m_Info_Carbo);
	m_pView->tmp.Protein = _wtof(m_Info_Protein);
	m_pView->tmp.Fat = _wtof(m_Info_Fat);
	m_pView->tmp.Cholest = _wtof(m_Info_Cholest);
	m_pView->tmp.Fiber = _wtof(m_Info_Fiber);
	m_pView->tmp.Na = _wtof(m_Info_Na);
	m_pView->tmp.date_day = date.wDay;
	m_pView->tmp.date_month = date.wMonth;
	m_pView->tmp.date_year = date.wYear;

	//////////////////////�Ĵ� ������ �߸� �Է�(�� - �̸��� �������)�� ��� �߰����� �ʵ����ϴ� �ڵ�////////////////////
	if (!m_pView->tmp.foodname.Compare(_T("")) || m_pView->tmp.cal <= 0 || m_pView->tmp.plate <= 0 ||
		m_pView->tmp.Carbo < 0 || m_pView->tmp.Protein < 0 || m_pView->tmp.Fat < 0 || m_pView->tmp.Cholest < 0 || m_pView->tmp.Fiber < 0 || m_pView->tmp.Na < 0)
	{
		AfxMessageBox(_T("�̸� �Ǵ� Į�θ� ������ �ùٸ��� �ʽ��ϴ�."));
		return;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	m_pView->c_edit1.SetWindowText(m_D1_EDIT_Name);
	m_pView->c_edit2.SetWindowText(m_Info_Calory);
	m_pView->c_edit3.SetWindowText(m_Info_Amount);

	str.Format(_T("%s   %.3lfkcal  %.2lf�κ�"), m_pView->tmp.foodname, m_pView->tmp.cal, m_pView->tmp.plate);
	//AfxMessageBox(str);
	CString a;
	Food pfood;
	if (m_pView->buttonstate == 9)
	{
		POSITION pos = pDoc->list.GetHeadPosition();
		while (pos != NULL)
		{
			pfood = pDoc->list.GetAt(pos);
			check = m_D1_EDIT_Name.Compare(pfood.foodname);
			pfood = pDoc->list.GetNext(pos);
		}
	}

	//CString str;
	//str.Format(_T("%s   %.3lfkcal  %.2lf�κ�"), m_pView->tmp.foodname, m_pView->tmp.cal, m_pView->tmp.plate);
	//CString a;

	if (m_pView->buttonstate == 2) {
		CString changeFood;
		Food pfood;
		if (m_Info_Combo.GetCurSel() == 0) {
			nIndex = m_pView->m_pDialog1->m_List1.GetCurSel();
			m_pView->m_pDialog1->m_List1.GetText(nIndex, changeFood);
			AfxExtractSubString(changeFood, changeFood, 0, ' ');
		
		}
		else if (m_Info_Combo.GetCurSel() == 1) {
			nIndex = m_pView->m_pDialog2->m_List2.GetCurSel();
			m_pView->m_pDialog2->m_List2.GetText(nIndex, changeFood);
			AfxExtractSubString(changeFood, changeFood, 0, ' ');
		
		}
		else if (m_Info_Combo.GetCurSel() == 2) {
			nIndex = m_pView->m_pDialog3->m_List3.GetCurSel();
			m_pView->m_pDialog3->m_List3.GetText(nIndex, changeFood);
			AfxExtractSubString(changeFood, changeFood, 0, ' ');

			
		}
		else if (m_Info_Combo.GetCurSel() == 3) {
			nIndex = m_pView->m_pDialog4->m_List4.GetCurSel();
			m_pView->m_pDialog4->m_List4.GetText(nIndex, changeFood);
			AfxExtractSubString(changeFood, changeFood, 0, ' ');

		}
		POSITION pos = pDoc->list.GetHeadPosition();
		while (pos != NULL)
		{
			pfood = pDoc->list.GetAt(pos);
			if (!changeFood.Compare(pfood.foodname) && m_pView->tmp.time == pfood.time
				&& m_pView->tmp.date_day == pfood.date_day && m_pView->tmp.date_month == pfood.date_month && m_pView->tmp.date_year == pfood.date_year)
			{
				pDoc->list.SetAt(pos, m_pView->tmp);
				break;
			}
			pfood = pDoc->list.GetNext(pos);
		}
		m_pView->ShowFoodList(pDoc);
	}

	if (m_pView->buttonstate == 9) {
		if (m_Info_Combo.GetCurSel() == 0) {
			m_pView->m_pDialog1->m_List1.AddString(str);
			m_pView->tmp.time = 0;
		}
		else if (m_Info_Combo.GetCurSel() == 1) {
			m_pView->m_pDialog2->m_List2.AddString(str);
			m_pView->tmp.time = 1;
		}
		else if (m_Info_Combo.GetCurSel() == 2) {
			m_pView->m_pDialog3->m_List3.AddString(str);
			m_pView->tmp.time = 2;
		}
		else if (m_Info_Combo.GetCurSel() == 3) {
			m_pView->m_pDialog4->m_List4.AddString(str);
			m_pView->tmp.time = 3;
		}
		pDoc->list.AddTail(m_pView->tmp);

		/////////////////////////������Ʈ�� ���� ����� �� ���뷮�� ���� �߰��� ������ �߰��ϴ� �ڵ�//////////////////////
		m_pView->totalCarbo += m_pView->tmp.Carbo;
		m_pView->totalCholest += (m_pView->tmp.Cholest) / 1000;
		m_pView->totalFat += m_pView->tmp.Fat;
		m_pView->totalFiber += m_pView->tmp.Fiber;
		m_pView->totalNa += (m_pView->tmp.Na) / 1000;
		m_pView->totalProtein += m_pView->tmp.Protein;
		m_pView->SumTotalCalorie(pDoc);
	}
	CDialog::OnOK();
}




void CShowInfoDialog::PostNcDestroy()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	//m_pView->m_pShowInfoDlg = NULL;
	//delete this;
	//CDialog::PostNcDestroy();
}


void CShowInfoDialog::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DestroyWindow();
	//CDialog::OnCancel();
}


BOOL CShowInfoDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFCDiet1View* pView = (CMFCDiet1View *)pFrame->GetActiveView();
	SetWindowText(_T("�Ĵ� ����"));

	SYSTEMTIME date;
	pView->m_date.GetCurSel(&date);
	m_Info_Date.Format(_T("%4d-%2d-%2d"), date.wYear,
		date.wMonth, date.wDay);
	SetDlgItemText(ID_D1_Date_Edit, m_Info_Date);
	m_Info_Combo.SetCurSel(0);
	
		return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CShowInfoDialog::OnBnClickedReset()
{
	UpdateData(FALSE);

	SetDlgItemText(ID_D1_Name_Edit, _T(""));
	SetDlgItemText(ID_D1_Kcal_Edit, _T(""));
	SetDlgItemText(ID_D1_Carbo_Edit, _T(""));
	SetDlgItemText(ID_D1_Protein_Edit, _T(""));
	SetDlgItemText(ID_D1_Fat_Edit, _T(""));
	SetDlgItemText(ID_D1_Cholest_Edit, _T(""));
	SetDlgItemText(ID_D1_Fiber_Edit, _T(""));
	SetDlgItemText(ID_D1_Na_Edit, _T(""));

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CShowInfoDialog::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nIDCtl == IDOK || nIDCtl == IDCANCEL || nIDCtl == IDC_RESET || nIDCtl == IDC_D1_Search)
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
	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
