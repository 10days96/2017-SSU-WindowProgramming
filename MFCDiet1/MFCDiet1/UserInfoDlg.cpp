// UserInfoDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "UserInfoDlg.h"
#include "afxdialogex.h"
#include "MFCDiet1Doc.h"
#include "MainFrm.h"


// CUserInfoDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CUserInfoDlg, CDialog)

CUserInfoDlg::CUserInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_USERINFO, pParent)
{

}

CUserInfoDlg::~CUserInfoDlg()
{
}

void CUserInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, editAge);
	DDX_Control(pDX, IDC_EDIT_LENGTH, editLength);
	DDX_Control(pDX, IDC_EDIT_WEIGHT, editWeight);
	DDX_Control(pDX, IDC_RADIO_MALE, radioMale);
	DDX_Control(pDX, IDC_RADIO_FEMALE, radioFemale);
	DDX_Control(pDX, IDC_RADIO_LOW, radioLow);
	DDX_Control(pDX, IDC_RADIO_NOMAL, radioNomal);
	DDX_Control(pDX, IDC_RADIO_HIGH, radioHigh);
}


BEGIN_MESSAGE_MAP(CUserInfoDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CUserInfoDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CUserInfoDlg 메시지 처리기입니다.


void CUserInfoDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFCDiet1Doc * pDoc = (CMFCDiet1Doc *)pFrame->GetActiveDocument();
	CString str;

	UpdateData(TRUE);
	GetDlgItemText(IDC_EDIT_NAME, str);
	pDoc->user.age = _wtoi(str);
	GetDlgItemText(IDC_EDIT_LENGTH, str);
	pDoc->user.length = _wtof(str);
	GetDlgItemText(IDC_EDIT_WEIGHT, str);
	pDoc->user.weight = _wtof(str);
	if (radioMale.GetCheck())
		pDoc->user.gender = FALSE;
	else if (radioFemale.GetCheck())
		pDoc->user.gender = TRUE;

	if (radioLow.GetCheck())
		pDoc->user.exercise = 1;
	else if (radioNomal.GetCheck())
		pDoc->user.exercise = 2;
	else if (radioHigh.GetCheck())
		pDoc->user.exercise = 3;

	CDialog::OnOK();
}


BOOL CUserInfoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFCDiet1Doc * pDoc = (CMFCDiet1Doc *)pFrame->GetActiveDocument();
	CString str;

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	UpdateData(TRUE);
	str.Format(_T("%d"), pDoc->user.age);
	SetDlgItemText(IDC_EDIT_NAME, str);
	str.Format(_T("%.2lf"), pDoc->user.length);
	SetDlgItemText(IDC_EDIT_LENGTH, str);
	str.Format(_T("%.2lf"), pDoc->user.weight);
	SetDlgItemText(IDC_EDIT_WEIGHT, str);
	if (pDoc->user.gender)
		radioFemale.SetCheck(1);
	else
		radioMale.SetCheck(1);

	if (pDoc->user.exercise == 1)
		radioLow.SetCheck(1);
	else if (pDoc->user.exercise == 2)
		radioNomal.SetCheck(1);
	else
		radioHigh.SetCheck(1);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
