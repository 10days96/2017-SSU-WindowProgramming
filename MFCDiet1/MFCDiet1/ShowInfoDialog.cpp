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
#include <Windows.h>


// CShowInfoDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CShowInfoDialog, CDialog)

CShowInfoDialog::CShowInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SHOWINFO, pParent)
	, m_D1_EDIT_Name(_T(""))
	//, m_Info_Amount(1)
	, m_Info_Carbo(0)
	, m_Info_Protein(0)
	, m_Info_Fat(0)
	, m_Info_Cholest(0)
	, m_Info_Fiber(0)
	, m_Info_Na(0)
	, m_Info_Calory(0)
	, m_Info_Amount(_T("1"))
	, m_Info_Date(_T(""))
{
	//m_Info_Date.Format(_T("%4d-%2d-%2d"),m_pView->date.wYear,
		//m_pView->date.wMonth,m_pView->date.wDay);
	//m_Info_Amount = 1;

}

CShowInfoDialog::~CShowInfoDialog()
{
}

void CShowInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, ID_D1_Name_Edit, m_D1_EDIT_Name);
	//DDX_Text(pDX, ID_D1_Kcal_Edit, m_D1_Kcal_Edit);
	//DDX_Text(pDX, ID_D1_Amount_Edit, m_Info_Amount);
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
}


BEGIN_MESSAGE_MAP(CShowInfoDialog, CDialog)
	ON_WM_CTLCOLOR()
	//ON_BN_CLICKED(IDCANCEL, &CShowInfoDialog::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_D1_Search, &CShowInfoDialog::OnBnClickedD1Search)
	ON_BN_CLICKED(IDC_D1_Search, &CShowInfoDialog::OnBnClickedD1Search)
	ON_EN_CHANGE(ID_D1_Amount_Edit, &CShowInfoDialog::OnEnChangeD1AmountEdit)
	ON_BN_CLICKED(IDOK, &CShowInfoDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CShowInfoDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// CShowInfoDialog 메시지 처리기입니다.

//컨트롤 색을 바꾸는 함수
/*HBRUSH CShowInfoDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (pWnd->GetDlgCtrlID() == IDOK) {
		pDC->SetTextColor(RGB(255,255,255));
		pDC->SetBkColor(RGB(0,0,0));

		return (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}*/


/*void CShowInfoDialog::OnBnClickedCancel()
{
	DestroyWindow();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialog::OnCancel();
}*/


//void CShowInfoDialog::PostNcDestroy()
//{
//	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
//	m_pView->m_pShowInfoDlg = NULL;
//	delete this;
//	//CDialog::PostNcDestroy();
//}


/*void CShowInfoDialog::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
*/

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
	m_D1_EDIT_Name = Find_Name;

	setlocale(LC_ALL, "");
	file.Open(_T("calory1.txt"),CFile::modeRead);
	while (file.ReadString(str)) {
		if (str.Find(Find_Name) != -1) {
			AfxExtractSubString(calory[0],str,1,',');
			m_Info_Calory = _wtof(calory[0]);
			SetDlgItemText(ID_D1_Kcal_Edit, calory[0]);
		
			AfxExtractSubString(calory[1], str, 2, ',');
			m_Info_Carbo = _wtof(calory[1]);
			SetDlgItemText(ID_D1_Carbo_Edit, calory[1]);

			AfxExtractSubString(calory[2], str, 3, ',');
			m_Info_Protein = _wtof(calory[2]);
			SetDlgItemText(ID_D1_Protein_Edit, calory[2]);

			AfxExtractSubString(calory[3], str, 4, ',');
			m_Info_Fat= _wtof(calory[3]);
			SetDlgItemText(ID_D1_Fat_Edit, calory[3]);

			AfxExtractSubString(calory[4], str, 5, ',');
			m_Info_Cholest = _wtof(calory[4]);
			SetDlgItemText(ID_D1_Cholest_Edit, calory[4]);

			AfxExtractSubString(calory[5], str, 6, ',');
			m_Info_Fiber = _wtof(calory[5]);
			SetDlgItemText(ID_D1_Fiber_Edit, calory[5]);

			AfxExtractSubString(calory[6], str, 7, ',');
			m_Info_Na = _wtof(calory[6]);
			SetDlgItemText(ID_D1_Na_Edit, calory[6]);
			
			break;
		}
		else {

		}
	}
	//AfxMessageBox(calory[6]);
	file.Close();
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

/*
char* CShowInfoDialog::UTF8toANSI(char* pszCode)stn 
{
	BSTR    bstrWide;
	char*   pszAnsi = NULL;
	int     nLength;
	nLength = MultiByteToWideChar(CP_UTF8, 0, pszCode, lstrlen(pszCode) + 1, NULL, NULL);
	bstrWide = SysAllocStringLen(NULL, nLength);
	MultiByteToWideChar(CP_UTF8, 0, pszCode, lstrlen(pszCode) + 1, bstrWide, nLength);
	nLength = WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, NULL, 0, NULL, NULL);
	pszAnsi = new char[nLength];
	WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, pszAnsi, nLength, NULL, NULL);
	SysFreeString(bstrWide);

	return pszAnsi;
	//return nullptr;
}
*/

void CShowInfoDialog::OnEnChangeD1AmountEdit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//UpdateData(TRUE);
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

	Info[0] = m_Info_Calory*amount;
	calory[0].Format(_T("%.1lf"), Info[0]);
	SetDlgItemText(ID_D1_Kcal_Edit, calory[0]);

	Info[1] = m_Info_Carbo*amount;
	calory[1].Format(_T("%.1lf"), Info[1]);
	SetDlgItemText(ID_D1_Carbo_Edit, calory[1]);

	Info[2] = m_Info_Protein*amount;
	calory[2].Format(_T("%.1lf"), Info[2]);
	SetDlgItemText(ID_D1_Protein_Edit, calory[2]);

	Info[3] = m_Info_Fat*amount;
	calory[3].Format(_T("%.1lf"), Info[3]);
	SetDlgItemText(ID_D1_Fat_Edit, calory[3]);

	Info[4] = m_Info_Cholest*amount;
	calory[4].Format(_T("%.1lf"), Info[4]);
	SetDlgItemText(ID_D1_Cholest_Edit, calory[4]);

	Info[5] = m_Info_Fiber*amount;
	calory[5].Format(_T("%.1lf"), Info[5]);
	SetDlgItemText(ID_D1_Fiber_Edit, calory[5]);

	Info[6] = m_Info_Na*amount;
	calory[6].Format(_T("%.1lf"), Info[6]);
	
	SetDlgItemText(ID_D1_Na_Edit, calory[6]);
}


void CShowInfoDialog::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	m_pView->tmp.foodname = m_D1_EDIT_Name;
	m_pView->tmp.plate=_wtof(m_Info_Amount);
	m_pView->tmp.cal = m_Info_Calory;
	CString Cal_str;
	Cal_str.Format(_T("%.1lf"),m_Info_Calory);
	m_pView->c_edit1.SetWindowText(m_D1_EDIT_Name);
	m_pView->c_edit2.SetWindowText(Cal_str);
	m_pView->c_edit3.SetWindowText(m_Info_Amount);
	
	
	CString str;
	str.Format(_T("%s     %.3lfkcal     %.2lf인분"), m_pView->tmp.foodname,m_pView-> tmp.cal, m_pView->tmp.plate);
	m_pView->m_pDialog1->m_List1.AddString(str);
	CDialog::OnOK();
}



void CShowInfoDialog::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pView->m_pShowInfoDlg = NULL;
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
	SYSTEMTIME date;
	//::ZeroMemory(reinterpret_cast<void*>(&time),sizeof(date));
	m_pView -> m_date.GetCurSel(&date);
	m_Info_Date.Format(_T("%4d-%2d-%2d"), date.wYear,
		date.wMonth, date.wDay);
	SetDlgItemText(ID_D1_Date_Edit,m_Info_Date);
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
