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
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// CMoreDlg 메시지 처리기입니다.


BOOL CMoreDlg::OnInitDialog()
{
	
	CDialog::OnInitDialog();
	SetWindowText(_T("식단 정보"));
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CMoreDlg::OnBnClickedOk()
{
	//
	CDialog::OnOK();
}


void CMoreDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
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
