// Search.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "Search.h"
#include "afxdialogex.h"


// CSearch ��ȭ �����Դϴ�.

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


// CSearch �޽��� ó�����Դϴ�.
