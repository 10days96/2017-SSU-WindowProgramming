// ShowInfoDialog.cpp : 구현 파일입니다.
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


// CShowInfoDialog 대화 상자입니다.

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
END_MESSAGE_MAP()


// CShowInfoDialog 메시지 처리기입니다.


void CShowInfoDialog::OnBnClickedD1Search()
{
	UpdateData(TRUE);
	CString str;
	CStdioFile file;
	CString Find_Name;
	CString calory[7];
	CString Amount;
	int count = 0;
	GetDlgItemText(ID_D1_Name_Edit,Find_Name);
	if (!Find_Name.Compare(_T(""))) {
		AfxMessageBox(_T("이름을 입력 해주세요."));
	};
	m_D1_EDIT_Name = Find_Name;

	setlocale(LC_ALL, "");
	file.Open(_T("calory1.txt"),CFile::modeRead);
	while (file.ReadString(str)) {
		if (str.Find(Find_Name) != -1 && Find_Name.Compare(_T(""))) {
			AfxExtractSubString(calory[0],str,1,',');
			m_Info_Calory = calory[0];
			SetDlgItemText(ID_D1_Kcal_Edit, calory[0]);
		
			AfxExtractSubString(calory[1], str, 2, ',');
			m_Info_Carbo = calory[1];
			SetDlgItemText(ID_D1_Carbo_Edit, calory[1]);

			AfxExtractSubString(calory[2], str, 3, ',');
			m_Info_Protein = calory[2];
			SetDlgItemText(ID_D1_Protein_Edit, calory[2]);

			AfxExtractSubString(calory[3], str, 4, ',');
			m_Info_Fat= calory[3];
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
			
			break;
		}
		else {

		}
	}
	file.Close();
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CShowInfoDialog::OnEnChangeD1AmountEdit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString Amount;
	double amount = 0;
	CString calory[7];
	CString str;
	double Info[7];

	GetDlgItemText(ID_D1_Amount_Edit, Amount);

	amount = _wtof(Amount);
	m_Info_Amount = Amount;
	SetDlgItemText(ID_D1_Name_Edit, m_D1_EDIT_Name);
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


void CShowInfoDialog::OnBnClickedOk()
{
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFCDiet1Doc * pDoc = (CMFCDiet1Doc *)pFrame->GetActiveDocument();
	CMFCDiet1View* m_pView = (CMFCDiet1View *)pFrame->GetActiveView();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItemText(ID_D1_Amount_Edit, m_Info_Amount);
	GetDlgItemText(ID_D1_Name_Edit, m_D1_EDIT_Name);
	GetDlgItemText(ID_D1_Kcal_Edit, m_Info_Calory);
	GetDlgItemText(ID_D1_Carbo_Edit, m_Info_Carbo);
	GetDlgItemText(ID_D1_Protein_Edit, m_Info_Protein);
	GetDlgItemText(ID_D1_Fat_Edit, m_Info_Fat);
	GetDlgItemText(ID_D1_Cholest_Edit, m_Info_Cholest);
	GetDlgItemText(ID_D1_Fiber_Edit, m_Info_Fiber);
	GetDlgItemText(ID_D1_Na_Edit, m_Info_Na);

	bool check = TRUE;
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

	if (check)
	{
		m_pView->tmp.foodname = m_D1_EDIT_Name;
		m_pView->tmp.plate = _wtof(m_Info_Amount);
		m_pView->tmp.cal = _wtof(m_Info_Calory);
		m_pView->tmp.Carbo = _wtof(m_Info_Carbo);
		m_pView->tmp.Protein = _wtof(m_Info_Protein);
		m_pView->tmp.Fat = _wtof(m_Info_Fat);
		m_pView->tmp.Cholest = _wtof(m_Info_Cholest);
		m_pView->tmp.Fiber = _wtof(m_Info_Fiber);
		m_pView->tmp.Na = _wtof(m_Info_Na);
		m_pView->c_edit1.SetWindowText(m_D1_EDIT_Name);
		m_pView->c_edit2.SetWindowText(m_Info_Calory);
		m_pView->c_edit3.SetWindowText(m_Info_Amount);

		CString str;
		str.Format(_T("%s   %.3lfkcal  %.2lf인분"), m_pView->tmp.foodname, m_pView->tmp.cal, m_pView->tmp.plate);
		CString a;
		if (m_pView->buttonstate == 9) {

		}

		if (m_pView->buttonstate == 2) {
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
		}
		pDoc->list.AddTail(m_pView->tmp);

		/////////////////////////파이차트를 위한 영양소 총 섭취량에 현재 추가한 데이터 추가하는 코드//////////////////////
		m_pView->totalCarbo += m_pView->tmp.Carbo;
		m_pView->totalCholest += (m_pView->tmp.Cholest)/1000;
		m_pView->totalFat += m_pView->tmp.Fat;
		m_pView->totalFiber += m_pView->tmp.Fiber;
		m_pView->totalNa += (m_pView->tmp.Na)/1000;
		m_pView->totalProtein += m_pView->tmp.Protein;
		m_pView->SumTotalCalorie(pDoc);
	}
	else
		AfxMessageBox(_T("동일한 이름의 음식 항목이 이미 존재합니다."));
	CDialog::OnOK();
}



void CShowInfoDialog::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	//m_pView->m_pShowInfoDlg = NULL;
	delete this;
	//CDialog::PostNcDestroy();
}


void CShowInfoDialog::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DestroyWindow();
	//CDialog::OnCancel();
}


BOOL CShowInfoDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFCDiet1View* pView = (CMFCDiet1View *)pFrame->GetActiveView();
	SetWindowText(_T("식단 정보"));

	SYSTEMTIME date;
	pView->m_date.GetCurSel(&date);
	m_Info_Date.Format(_T("%4d-%2d-%2d"), date.wYear,
		date.wMonth, date.wDay);
	SetDlgItemText(ID_D1_Date_Edit, m_Info_Date);
	m_Info_Combo.SetCurSel(0);
	//m_Info_meal = 0;
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//if (m_pView->buttonstate == 7) {
		//CMoreDlg *pDlg = (CMoreDlg*)AfxGetMainWnd();
		//pDlg->SendMessage(WM_CLOSE, 0, 0);
	//}
	//if(pView->buttonstate == 7)
		//return FALSE;
	//else
		return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
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

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
