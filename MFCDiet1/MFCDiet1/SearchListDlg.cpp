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
