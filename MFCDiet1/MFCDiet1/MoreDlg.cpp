// MoreDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "MoreDlg.h"
#include "afxdialogex.h"
#include "MFCDiet1Doc.h"
#include "MFCDiet1View.h"
#include "ShowInfoDialog.h"
#include "MainFrm.h"


// CMoreDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMoreDlg, CDialog)

CMoreDlg::CMoreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SHOWMORE, pParent)
{

}

CMoreDlg::~CMoreDlg()
{
}

void CMoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, ID_D2_Meal_combo, m_Meal_combo);
}


BEGIN_MESSAGE_MAP(CMoreDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CMoreDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMoreDlg 메시지 처리기입니다.


BOOL CMoreDlg::OnInitDialog()
{
	
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CMoreDlg::OnBnClickedOk()
{
	CDialog::OnOK();
}
