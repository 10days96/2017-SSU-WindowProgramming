// ShowBMIDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "ShowBMIDlg.h"
#include "afxdialogex.h"
#include "MFCDiet1Doc.h"
#include "MainFrm.h"


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
	ON_WM_PAINT()
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// CShowBMIDlg 메시지 처리기입니다.


BOOL CShowBMIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetWindowText(_T("BMI 정보"));

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFCDiet1Doc * pDoc = (CMFCDiet1Doc *)pFrame->GetActiveDocument();

	double bmi = pDoc->user.weight/((pDoc->user.length/100)*(pDoc->user.length/100));
	CString str;
	str.Format(_T("%.2lf"), bmi);
	SetDlgItemText(IDC_EDIT_BMI, str);

	if (bmi < 18.5)
		SetDlgItemText(IDC_EDIT_STATE, _T("체중부족"));
	else if (bmi < 23.0)
		SetDlgItemText(IDC_EDIT_STATE, _T("정상"));
	else if (bmi < 25.0)
		SetDlgItemText(IDC_EDIT_STATE, _T("과체중"));
	else if (bmi < 30.0)
		SetDlgItemText(IDC_EDIT_STATE, _T("비만"));
	else
		SetDlgItemText(IDC_EDIT_STATE, _T("고도비만"));
	/*
	CClientDC dc(this);
	CImage Image;
	Image.Load(_T("BMI.bmp"));
	Image.StretchBlt(dc, 0, 0, 50, 100, SRCCOPY);
	*/
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.

}


void CShowBMIDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
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


void CShowBMIDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDCtl == IDOK)
	{
		CDC dc;
		RECT rect;
		dc.Attach(lpDrawItemStruct->hDC);	//Get the Button DC to CDC

		rect = lpDrawItemStruct->rcItem;	//Store the Button rect to local rect
		dc.Draw3dRect(&rect, RGB(200, 200, 200), RGB(20, 20, 20));
		dc.FillSolidRect(&rect, RGB(100, 100, 100));

		//Show the Effect of Click Event
		UINT state = lpDrawItemStruct->itemState;
		if ((state & ODS_SELECTED))
		{
			dc.DrawEdge(&rect, EDGE_SUNKEN, BF_RECT);
		}
		else
		{
			dc.DrawEdge(&rect, EDGE_RAISED, BF_RECT);
		}

		//Draw Color Text
		dc.SetBkColor(RGB(100, 100, 100));		//Setting the Text Background Color
		dc.SetTextColor(RGB(255, 255, 255));		//Setting the Text Color

		TCHAR buffer[MAX_PATH];
		ZeroMemory(buffer, MAX_PATH);
		::GetWindowText(lpDrawItemStruct->hwndItem, buffer, MAX_PATH);

		dc.DrawText(buffer, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		dc.Detach();							//Detach the Button DC
	}
	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
