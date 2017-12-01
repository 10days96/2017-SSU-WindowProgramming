// ShowBMIDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "ShowBMIDlg.h"
#include "afxdialogex.h"
#include "MFCDiet1Doc.h"
#include "MainFrm.h"


// CShowBMIDlg ��ȭ �����Դϴ�.

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


// CShowBMIDlg �޽��� ó�����Դϴ�.


BOOL CShowBMIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFCDiet1Doc * pDoc = (CMFCDiet1Doc *)pFrame->GetActiveDocument();

	double bmi = pDoc->user.weight/((pDoc->user.length/100)*(pDoc->user.length/100));
	CString str;
	str.Format(_T("%.2lf"), bmi);
	SetDlgItemText(IDC_EDIT_BMI, str);

	if (bmi < 18.5)
		SetDlgItemText(IDC_EDIT_STATE, _T("ü�ߺ���"));
	else if(bmi < 23.0)
		SetDlgItemText(IDC_EDIT_STATE, _T("����"));
	else if (bmi  <25.0)
		SetDlgItemText(IDC_EDIT_STATE, _T("��ü��"));
	else
		SetDlgItemText(IDC_EDIT_STATE, _T("��"));
	/*
	CClientDC dc(this);
	CImage Image;
	Image.Load(_T("BMI.png"));
	Image.BitBlt(dc.m_hDC, 0, 400);
	*/
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
