// SearchListDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "SearchListDlg.h"
#include "afxdialogex.h"
#include <locale.h>
#include "ShowInfoDialog.h"


// CSearchListDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSearchListDlg, CDialogEx)

CSearchListDlg::CSearchListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SEARCH_LIST, pParent)
{

}

CSearchListDlg::~CSearchListDlg()
{
	whichButton = FALSE;
}

void CSearchListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SEARCH, m_searchlist);
}


BEGIN_MESSAGE_MAP(CSearchListDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSearchListDlg::OnBnClickedOk)
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// CSearchListDlg �޽��� ó�����Դϴ�.


void CSearchListDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int index = m_searchlist.GetCurSel();
	if (index != LB_ERR)
	{
		m_searchlist.GetText(index, selectedName);
		whichButton = TRUE;
		CDialogEx::OnOK();
	}
	else
		AfxMessageBox(_T("�Ĵ��� �������ּ���"));
}


BOOL CSearchListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	SetWindowText(_T("�Ĵ� �˻� ���"));

	CString name;
	POSITION pos = foodNameList.GetHeadPosition();
	while (pos!=NULL)
	{
		name = foodNameList.GetAt(pos);
		m_searchlist.AddString(name);
		name = foodNameList.GetNext(pos);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CSearchListDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nIDCtl == IDOK || nIDCtl == IDCANCEL)
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
	CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
