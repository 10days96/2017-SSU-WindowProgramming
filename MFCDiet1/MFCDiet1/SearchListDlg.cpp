// SearchListDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "SearchListDlg.h"
#include "afxdialogex.h"
#include <locale.h>
#include "ShowInfoDialog.h"


// CSearchListDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSearchListDlg, CDialogEx)

CSearchListDlg::CSearchListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SEARCH_LIST, pParent)
{

}

CSearchListDlg::~CSearchListDlg()
{
	whichButton = FALSE;
}

void CSearchListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SEARCH, m_searchlist);
}


BEGIN_MESSAGE_MAP(CSearchListDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSearchListDlg::OnBnClickedOk)
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// CSearchListDlg 메시지 처리기입니다.


void CSearchListDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int index = m_searchlist.GetCurSel();
	if (index != LB_ERR)
	{
		m_searchlist.GetText(index, selectedName);
		whichButton = TRUE;
		CDialogEx::OnOK();
	}
	else
		AfxMessageBox(_T("식단을 선택해주세요"));
}


BOOL CSearchListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetWindowText(_T("식단 검색 결과"));

	CString name;
	POSITION pos = foodNameList.GetHeadPosition();
	while (pos!=NULL)
	{
		name = foodNameList.GetAt(pos);
		m_searchlist.AddString(name);
		name = foodNameList.GetNext(pos);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSearchListDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
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
	CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
