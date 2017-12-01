// UserInfoDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "UserInfoDlg.h"
#include "afxdialogex.h"
#include "MFCDiet1Doc.h"
#include "MainFrm.h"


// CUserInfoDlg ��ȭ �����Դϴ�.

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


// CUserInfoDlg �޽��� ó�����Դϴ�.


void CUserInfoDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
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
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
