// InfoDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "InfoDialog.h"
#include "afxdialogex.h"


// CInfoDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CInfoDialog, CDialog)

CInfoDialog::CInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_INFO, pParent)
{

}

CInfoDialog::~CInfoDialog()
{
}

void CInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInfoDialog, CDialog)
END_MESSAGE_MAP()


// CInfoDialog �޽��� ó�����Դϴ�.
