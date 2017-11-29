// DlgTab1.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "DlgTab1.h"
#include "afxdialogex.h"


// CDlgTab1 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgTab1, CDialog)

CDlgTab1::CDlgTab1(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG2, pParent)
{

}

CDlgTab1::~CDlgTab1()
{
}

void CDlgTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List1);
}


BEGIN_MESSAGE_MAP(CDlgTab1, CDialog)
END_MESSAGE_MAP()

