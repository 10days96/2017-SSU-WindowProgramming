// ShowBMIDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "ShowBMIDlg.h"
#include "afxdialogex.h"
#include "MFCDiet1Doc.h"
#include "MainFrm.h"


// CShowBMIDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CShowBMIDlg, CDialog)

CShowBMIDlg::CShowBMIDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SHOWBMI, pParent)
{

}

CShowBMIDlg::~CShowBMIDlg()
{
}

void CShowBMIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CShowBMIDlg, CDialog)
END_MESSAGE_MAP()


// CShowBMIDlg 메시지 처리기입니다.


BOOL CShowBMIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFCDiet1Doc * pDoc = (CMFCDiet1Doc *)pFrame->GetActiveDocument();

	double bmi = pDoc->user.weight/((pDoc->user.length/100)*(pDoc->user.length/100));
	CString str;
	str.Format(_T("%.2lf"), bmi);
	SetDlgItemText(IDC_EDIT_BMI, str);

	if (bmi < 18.5)
		SetDlgItemText(IDC_EDIT_STATE, _T("체중부족"));
	else if(bmi < 23.0)
		SetDlgItemText(IDC_EDIT_STATE, _T("정상"));
	else if (bmi  <25.0)
		SetDlgItemText(IDC_EDIT_STATE, _T("과체중"));
	else
		SetDlgItemText(IDC_EDIT_STATE, _T("비만"));
	/*
	CClientDC dc(this);
	CImage Image;
	Image.Load(_T("BMI.png"));
	Image.BitBlt(dc.m_hDC, 0, 400);
	*/
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
