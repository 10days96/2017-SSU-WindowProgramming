// MoreDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "MoreDlg.h"
#include "afxdialogex.h"
#include "MFCDiet1Doc.h"
#include "MFCDiet1View.h"
#include "ShowInfoDialog.h"
#include "MainFrm.h"


// CMoreDlg ��ȭ �����Դϴ�.

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
END_MESSAGE_MAP()


// CMoreDlg �޽��� ó�����Դϴ�.


BOOL CMoreDlg::OnInitDialog()
{
	
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CMoreDlg::OnBnClickedOk()
{
	CDialog::OnOK();
}
