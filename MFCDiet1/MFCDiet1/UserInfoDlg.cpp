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
	ON_WM_DRAWITEM()
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

	SetWindowText(_T("사용자 정보"));

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

	if (pDoc->user.exercise == 3)
		radioHigh.SetCheck(1);
	else if (pDoc->user.exercise == 2)
		radioNomal.SetCheck(1);
	else
		radioLow.SetCheck(1);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CUserInfoDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDCtl == IDOK || nIDCtl == IDCANCEL)
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
