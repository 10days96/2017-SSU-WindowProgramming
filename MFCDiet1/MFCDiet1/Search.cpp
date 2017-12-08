// Search.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "Search.h"
#include "afxdialogex.h"


// CSearch 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSearch, CDialog)

CSearch::CSearch(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SEARCH_CHECK, pParent)
{

}

CSearch::~CSearch()
{
}

void CSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSearch, CDialog)
END_MESSAGE_MAP()


// CSearch 메시지 처리기입니다.
