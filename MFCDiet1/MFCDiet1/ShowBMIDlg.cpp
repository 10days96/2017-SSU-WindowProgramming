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
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CShowBMIDlg �޽��� ó�����Դϴ�.


BOOL CShowBMIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetWindowText(_T("BMI ����"));

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
	Image.Load(_T("BMI.bmp"));
	Image.StretchBlt(dc, 0, 0, 50, 100, SRCCOPY);
	*/
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.

}


void CShowBMIDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CDialog::OnPaint()��(��) ȣ������ ���ʽÿ�.
	DrawDoubleBuffering();
}


void CShowBMIDlg::DrawDoubleBuffering()
{
	CDC* pDC = GetDC();
	CRect rect;
	GetClientRect(rect);

	CDC MemDC;
	CBitmap * pOldBitmap;
	CBitmap bmp;

	MemDC.CreateCompatibleDC(pDC);
	bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	pOldBitmap = (CBitmap *)MemDC.SelectObject(&bmp);
	MemDC.PatBlt(0, 0, rect.Width(), rect.Height(), WHITENESS);

	CBitmap bmpImage;
	BOOL tmp = bmpImage.LoadBitmapW(IDB_BITMAP1);
	MemDC.SelectObject(&bmpImage);

	BITMAP bmpImageSize;
	bmpImage.GetObject(sizeof(BITMAP), &bmpImageSize);

	pDC->StretchBlt(10, 200, rect.Width()-20, rect.Height()-300, &MemDC, 0, 0, bmpImageSize.bmWidth, bmpImageSize.bmHeight, SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
	MemDC.DeleteDC();

}
