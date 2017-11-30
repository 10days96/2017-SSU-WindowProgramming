// PieChartDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "PieChartDlg.h"
#include "afxdialogex.h"


// CPieChartDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CPieChartDlg, CDialog)

CPieChartDlg::CPieChartDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PIECHART, pParent)
{

}

CPieChartDlg::~CPieChartDlg()
{
}

void CPieChartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPieChartDlg, CDialog)
END_MESSAGE_MAP()


// CPieChartDlg 메시지 처리기입니다.
