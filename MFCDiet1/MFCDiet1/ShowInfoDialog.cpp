// ShowInfoDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "ShowInfoDialog.h"
#include "afxdialogex.h"
#include "MFCDiet1Doc.h"
#include "MFCDiet1View.h"


// CShowInfoDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CShowInfoDialog, CDialog)

CShowInfoDialog::CShowInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

CShowInfoDialog::~CShowInfoDialog()
{
}

void CShowInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CShowInfoDialog, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CShowInfoDialog �޽��� ó�����Դϴ�.

//��Ʈ�� ���� �ٲٴ� �Լ�
/*HBRUSH CShowInfoDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (pWnd->GetDlgCtrlID() == IDOK) {
		pDC->SetTextColor(RGB(255,255,255));
		pDC->SetBkColor(RGB(0,0,0));

		return (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}*/
