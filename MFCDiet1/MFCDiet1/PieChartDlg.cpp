// PieChartDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "PieChartDlg.h"
#include "afxdialogex.h"
#include <math.h>
#include "MainFrm.h"
#include "MFCDiet1View.h"


// CPieChartDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CPieChartDlg, CDialog)

const double pi = 3.1415926535;

CPieChartDlg::CPieChartDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PIECHART, pParent)
	, mOutput1(_T("탄수화물"))
	, mOutput2(_T("단백질"))
	, mOutput3(_T("지방"))
	, mOutput4(_T("콜레스테롤"))
	, mOutput5(_T("식이섬유"))
	, mOutput6(_T("나트륨"))
	, checkName(FALSE)
	, checkPercent(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CPieChartDlg::~CPieChartDlg()
{
}

void CPieChartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_NAME, checkName);
	DDX_Check(pDX, IDC_CHECK_PERCENT, checkPercent);
}


BEGIN_MESSAGE_MAP(CPieChartDlg, CDialog)
	ON_STN_CLICKED(IDC_COLOR1, &CPieChartDlg::OnStnClickedColor1)
	ON_STN_CLICKED(IDC_COLOR2, &CPieChartDlg::OnStnClickedColor2)
	ON_STN_CLICKED(IDC_COLOR3, &CPieChartDlg::OnStnClickedColor3)
	ON_STN_CLICKED(IDC_COLOR4, &CPieChartDlg::OnStnClickedColor4)
	ON_STN_CLICKED(IDC_COLOR5, &CPieChartDlg::OnStnClickedColor5)
	ON_STN_CLICKED(IDC_COLOR6, &CPieChartDlg::OnStnClickedColor6)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_PIECHART, &CPieChartDlg::OnBnClickedButton1)
	ON_WM_SYSCOMMAND()
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// CPieChartDlg 메시지 처리기입니다.


void CPieChartDlg::OnStnClickedColor1()
{
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CColorDialog dlg(pieColor[0]);
	if (dlg.DoModal() == IDOK)
	{
		pieColor[0] = dlg.GetColor();
		PiDraw = true;
		Invalidate();
	}
	
}

void CPieChartDlg::OnStnClickedColor2()
{
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CColorDialog dlg(pieColor[1]);
	if (dlg.DoModal() == IDOK)
	{
		pieColor[1] = dlg.GetColor();
		PiDraw = true;
		Invalidate();
	}
	
}

void CPieChartDlg::OnStnClickedColor3()
{
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CColorDialog dlg(pieColor[2]);
	if (dlg.DoModal() == IDOK)
	{
		pieColor[2] = dlg.GetColor();
		PiDraw = true;
		Invalidate();
	}
	
}

void CPieChartDlg::OnStnClickedColor4()
{
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CColorDialog dlg(pieColor[3]);
	if (dlg.DoModal() == IDOK)
	{
		pieColor[3] = dlg.GetColor();
		PiDraw = true;
		Invalidate();
	}
	
}

void CPieChartDlg::OnStnClickedColor5()
{
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CColorDialog dlg(pieColor[4]);
	if (dlg.DoModal() == IDOK)
	{
		pieColor[4] = dlg.GetColor();
		PiDraw = true;
		Invalidate();
	}
	
}



void CPieChartDlg::OnStnClickedColor6()
{
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CColorDialog dlg(pieColor[5]);
	if (dlg.DoModal() == IDOK)
	{
		pieColor[5] = dlg.GetColor();
		PiDraw = true;
		Invalidate();
	}
}


BOOL CPieChartDlg::OnInitDialog()
{
	
	CDialog::OnInitDialog();

	SetWindowText(_T("섭취한 영양소 원형차트"));

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	//pie 틀
	GetDlgItem(IDC_VIEW)->GetWindowRect(&rectView);
	ScreenToClient(&rectView);

	//RGB 선택
	GetDlgItem(IDC_COLOR1)->GetWindowRect(&rectColor1);
	ScreenToClient(&rectColor1);
	GetDlgItem(IDC_COLOR2)->GetWindowRect(&rectColor2);
	ScreenToClient(&rectColor2);
	GetDlgItem(IDC_COLOR3)->GetWindowRect(&rectColor3);
	ScreenToClient(&rectColor3);
	GetDlgItem(IDC_COLOR4)->GetWindowRect(&rectColor4);
	ScreenToClient(&rectColor4);
	GetDlgItem(IDC_COLOR5)->GetWindowRect(&rectColor5);
	ScreenToClient(&rectColor5);
	GetDlgItem(IDC_COLOR6)->GetWindowRect(&rectColor6);
	ScreenToClient(&rectColor6);

	x[0] = rectView.CenterPoint().x;
	y[0] = rectView.CenterPoint().y;
	init_x = rectView.CenterPoint().x;
	init_y = rectView.CenterPoint().y;
	width = rectView.Width() / 2.0;
	height = rectView.Height() / 2.0;
	InputValue[0] = 0;
	InputValue[1] = 0;
	InputValue[2] = 0;
	InputValue[3] = 0;
	InputValue[4] = 0;
	InputValue[5] = 0;
	PiDraw = false;
	percent = _T("%");
	pieColor[0] = RGB(247, 182, 204);
	pieColor[1] = RGB(182, 1185, 237);
	pieColor[2] = RGB(149, 225, 247);
	pieColor[3] = RGB(245, 247, 184);
	pieColor[4] = RGB(186, 235, 213);
	pieColor[5] = RGB(247, 205, 130);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CPieChartDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}

	CClientDC dc(this);
	CPen pen2, pen1;
	pen1.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	pen2.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	dc.SelectStockObject(NULL_PEN);

	CBrush brush[6];
	brush[0].CreateSolidBrush(pieColor[0]);
	brush[1].CreateSolidBrush(pieColor[1]);
	brush[2].CreateSolidBrush(pieColor[2]);
	brush[3].CreateSolidBrush(pieColor[3]);
	brush[4].CreateSolidBrush(pieColor[4]);
	brush[5].CreateSolidBrush(pieColor[5]);

	dc.SelectObject(&brush[0]);
	dc.SetBkMode(TRANSPARENT);

	//dc.SelectObject(&pen1);
	//intit color select
	dc.SelectObject(&brush[0]);
	dc.Rectangle(&rectColor1);
	dc.SelectObject(&brush[1]);
	dc.Rectangle(&rectColor2);
	dc.SelectObject(&brush[2]);
	dc.Rectangle(&rectColor3);
	dc.SelectObject(&brush[3]);
	dc.Rectangle(&rectColor4);
	dc.SelectObject(&brush[4]);
	dc.Rectangle(&rectColor5);
	dc.SelectObject(&brush[5]);
	dc.Rectangle(&rectColor6);

	//dc.SelectObject(&pen2);
	if (PiDraw)
	{

		if (InputValue[0])
		{
			dc.SelectObject(&brush[0]);
			dc.Ellipse(&rectView);
		}

		if (InputValue[1])
		{
			dc.SelectObject(&brush[1]);
			dc.Pie(rectView.TopLeft().x, rectView.TopLeft().y, rectView.BottomRight().x, rectView.BottomRight().y, init_x, init_y, x[0], y[0]);
		}

		if (InputValue[2])
		{
			dc.SelectObject(&brush[2]);
			dc.Pie(rectView.TopLeft().x, rectView.TopLeft().y, rectView.BottomRight().x, rectView.BottomRight().y, init_x, init_y, x[1], y[1]);
		}

		if (InputValue[3])
		{
			dc.SelectObject(&brush[3]);
			dc.Pie(rectView.TopLeft().x, rectView.TopLeft().y, rectView.BottomRight().x, rectView.BottomRight().y, init_x, init_y, x[2], y[2]);
		}

		if (InputValue[4])
		{
			dc.SelectObject(&brush[4]);
			dc.Pie(rectView.TopLeft().x, rectView.TopLeft().y, rectView.BottomRight().x, rectView.BottomRight().y, init_x, init_y, x[3], y[3]);
		}

		if (InputValue[5])
		{
			dc.SelectObject(&brush[5]);
			dc.Pie(rectView.TopLeft().x, rectView.TopLeft().y, rectView.BottomRight().x, rectView.BottomRight().y, init_x, init_y, x[4], y[4]);
		}
		//캡션
		if (InputValue[0] && checkName)
		{
			dc.TextOut(text_x[0], text_y[0], _T("탄수화물"));
		}

		if (InputValue[1] && checkName)
		{
			dc.TextOut(text_x[1], text_y[1], _T("단백질"));
		}

		if (InputValue[2] && checkName)
		{
			dc.TextOut(text_x[2], text_y[2], _T("지방"));
		}

		if (InputValue[3] && checkName)
		{
			dc.TextOut(text_x[3], text_y[3], _T("콜레스테롤"));
		}

		if (InputValue[4] && checkName)
		{
			dc.TextOut(text_x[4], text_y[4], _T("식이섬유"));
		}

		if (InputValue[5] && checkName)
		{
			dc.TextOut(text_x[5], text_y[5], _T("나트륨"));
		}

		//값
		if (checkName)
		{
			if (InputValue[0] && checkPercent)
			{
				temp.Format(_T("%.1f"), avr[0]);
				dc.TextOutW(text_x[0], text_y[0] + 15, temp + percent);
			}

			if (InputValue[1] && checkPercent)
			{
				temp.Format(_T("%.1f"), avr[1]);
				dc.TextOutW(text_x[1], text_y[1] + 15, temp + percent);
			}

			if (InputValue[2] && checkPercent)
			{
				temp.Format(_T("%.1f"), avr[2]);
				dc.TextOutW(text_x[2], text_y[2] + 15, temp + percent);
			}

			if (InputValue[3] && checkPercent)
			{
				temp.Format(_T("%.1f"), avr[3]);
				dc.TextOutW(text_x[3], text_y[3] + 15, temp + percent);
			}

			if (InputValue[4] && checkPercent)
			{
				temp.Format(_T("%.1f"), avr[4]);
				dc.TextOutW(text_x[4], text_y[4] + 15, temp + percent);
			}

			if (InputValue[5] && checkPercent)
			{
				temp.Format(_T("%.1f"), avr[5]);
				dc.TextOutW(text_x[5], text_y[5] + 15, temp + percent);
			}

		}
		else
		{
			if (InputValue[0] && checkPercent)
			{
				temp.Format(_T("%.1f"), avr[0]);
				dc.TextOutW(text_x[0], text_y[0], temp + percent);
			}

			if (InputValue[1] && checkPercent)
			{
				temp.Format(_T("%.1f"), avr[1]);
				dc.TextOutW(text_x[1], text_y[1], temp + percent);
			}

			if (InputValue[2] && checkPercent)
			{
				temp.Format(_T("%.1f"), avr[2]);
				dc.TextOutW(text_x[2], text_y[2], temp + percent);
			}

			if (InputValue[3] && checkPercent)
			{
				temp.Format(_T("%.1f"), avr[3]);
				dc.TextOutW(text_x[3], text_y[3], temp + percent);
			}

			if (InputValue[4] && checkPercent)
			{
				temp.Format(_T("%.1f"), avr[4]);
				dc.TextOutW(text_x[4], text_y[4], temp + percent);
			} 

			if (InputValue[5] && checkPercent)
			{
				temp.Format(_T("%.1f"), avr[5]);
				dc.TextOutW(text_x[5], text_y[5], temp + percent);
			}
		}
		PiDraw = false;
	}
}


void CPieChartDlg::OnBnClickedButton1()
{
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFCDiet1View * pView = (CMFCDiet1View *)pFrame->GetActiveView();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double TotalSum;
	int i;

	InputValue[0] = pView->totalCarbo;
	InputValue[1] = pView->totalProtein;
	InputValue[2] = pView->totalFat;
	if(pView->totalCholest > 0.01)
		InputValue[3] = pView->totalCholest;
	InputValue[4] = pView->totalFiber;
	if (pView->totalNa > 0.01)
		InputValue[5] = pView->totalNa;
	UpdateData(1);

	TotalSum = InputValue[0] + InputValue[1] + InputValue[2] + InputValue[3] + InputValue[4] + InputValue[5];
	if (TotalSum)
	{
		for (i = 0; i < 6; i++)
		{
			avr[i] = (static_cast<float>(InputValue[i]) / TotalSum) * 100;
		}

		temp.Format(_T("%.1f"), avr[0]);
		mOutput1 = temp + percent;
		temp.Format(_T("%.1f"), avr[1]);
		mOutput2 = temp + percent;
		temp.Format(_T("%.1f"), avr[2]);
		mOutput3 = temp + percent;
		temp.Format(_T("%.1f"), avr[3]);
		mOutput4 = temp + percent;
		temp.Format(_T("%.1f"), avr[4]);
		mOutput5 = temp + percent;
		temp.Format(_T("%.1f"), avr[5]);
		mOutput6 = temp + percent;
		UpdateData(0);

		//pi 좌표
		x[0] = static_cast<int>(width * cos((360 * avr[0] / 100)*pi / 180)) + rectView.CenterPoint().x;
		y[0] = static_cast<int>(height * sin((360 * avr[0] / 100)*pi / 180)) + rectView.CenterPoint().y;

		x[1] = static_cast<int>(width * cos((360 * (avr[0] + avr[1]) / 100)*pi / 180)) + rectView.CenterPoint().x;
		y[1] = static_cast<int>(height * sin((360 * (avr[0] + avr[1]) / 100)*pi / 180)) + rectView.CenterPoint().y;

		x[2] = static_cast<int>(width * cos((360 * (avr[0] + avr[1] + avr[2]) / 100)*pi / 180)) + rectView.CenterPoint().x;
		y[2] = static_cast<int>(height * sin((360 * (avr[0] + avr[1] + avr[2]) / 100)*pi / 180)) + rectView.CenterPoint().y;

		x[3] = static_cast<int>(width * cos((360 * (avr[0] + avr[1] + avr[2] + avr[3]) / 100)*pi / 180)) + rectView.CenterPoint().x;
		y[3] = static_cast<int>(height * sin((360 * (avr[0] + avr[1] + avr[2] + avr[3]) / 100)*pi / 180)) + rectView.CenterPoint().y;

		x[4] = static_cast<int>(width * cos((360 * (avr[0] + avr[1] + avr[2] + avr[3] + avr[4]) / 100)*pi / 180)) + rectView.CenterPoint().x;
		y[4] = static_cast<int>(height * sin((360 * (avr[0] + avr[1] + avr[2] + avr[3] + avr[4]) / 100)*pi / 180)) + rectView.CenterPoint().y;

		x[5] = static_cast<int>(width * cos((360 * (avr[0] + avr[1] + avr[2] + avr[3] + avr[4] + avr[5]) / 100)*pi / 180)) + rectView.CenterPoint().x;
		y[5] = static_cast<int>(height * sin((360 * (avr[0] + avr[1] + avr[2] + avr[3] + avr[4] + avr[5]) / 100)*pi / 180)) + rectView.CenterPoint().y;

		init_x = rectView.CenterPoint().x + rectView.Width() / 2;

		PiDraw = true;

		if (checkPercent || checkName)
		{
			//text 좌표
			text_x[0] = static_cast<int>(width / 2 * cos((360 * avr[0] / 2 / 100)*pi / 180)) + rectView.CenterPoint().x;
			text_y[0] = static_cast<int>(height / 2 * sin((360 * avr[0] / 2 / 100)*pi / 180)) + rectView.CenterPoint().y;

			text_x[1] = static_cast<int>(width / 2 * cos((360 * (avr[0] + avr[1] / 2) / 100)*pi / 180)) + rectView.CenterPoint().x;
			text_y[1] = static_cast<int>(height / 2 * sin((360 * (avr[0] + avr[1] / 2) / 100)*pi / 180)) + rectView.CenterPoint().y;

			text_x[2] = static_cast<int>(width / 2 * cos((360 * (avr[0] + avr[1] + avr[2] / 2) / 100)*pi / 180)) + rectView.CenterPoint().x;
			text_y[2] = static_cast<int>(height / 2 * sin((360 * (avr[0] + avr[1] + avr[2] / 2) / 100)*pi / 180)) + rectView.CenterPoint().y;

			text_x[3] = static_cast<int>(width / 2 * cos((360 * (avr[0] + avr[1] + avr[2] + avr[3] / 2) / 100)*pi / 180)) + rectView.CenterPoint().x;
			text_y[3] = static_cast<int>(height / 2 * sin((360 * (avr[0] + avr[1] + avr[2] + avr[3] / 2) / 100)*pi / 180)) + rectView.CenterPoint().y;

			text_x[4] = static_cast<int>(width / 2 * cos((360 * (avr[0] + avr[1] + avr[2] + avr[3] + avr[4] / 2) / 100)*pi / 180)) + rectView.CenterPoint().x;
			text_y[4] = static_cast<int>(height / 2 * sin((360 * (avr[0] + avr[1] + avr[2] + avr[3] + avr[4] / 2) / 100)*pi / 180)) + rectView.CenterPoint().y;

			text_x[5] = static_cast<int>(width / 2 * cos((360 * (avr[0] + avr[1] + avr[2] + avr[3] + avr[4] + avr[5] / 2) / 100)*pi / 180)) + rectView.CenterPoint().x;
			text_y[5] = static_cast<int>(height / 2 * sin((360 * (avr[0] + avr[1] + avr[2] + avr[3] + avr[4] + avr[5] / 2) / 100)*pi / 180)) + rectView.CenterPoint().y;
		}
	}
	OnPaint();
	
}


void CPieChartDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialog::OnSysCommand(nID, lParam);
}


void CPieChartDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDCtl == IDOK || nIDCtl == IDC_BUTTON_PIECHART)
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
