// DlgTab2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "DlgTab2.h"
#include "afxdialogex.h"


// CDlgTab2 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgTab2, CDialogEx)

CDlgTab2::CDlgTab2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CDlgTab2::~CDlgTab2()
{
}

void CDlgTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_List2);
}


BEGIN_MESSAGE_MAP(CDlgTab2, CDialogEx)
END_MESSAGE_MAP()


// CDlgTab2 메시지 처리기입니다.
