// ShowBMIDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "ShowBMIDlg.h"
#include "afxdialogex.h"


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
