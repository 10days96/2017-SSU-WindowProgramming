// ShowInfoDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "ShowInfoDialog.h"
#include "afxdialogex.h"
#include "MFCDiet1Doc.h"
#include "MFCDiet1View.h"
#include <locale.h>
#include <Windows.h>


// CShowInfoDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CShowInfoDialog, CDialog)

CShowInfoDialog::CShowInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SHOWINFO, pParent)
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
	ON_BN_CLICKED(IDCANCEL, &CShowInfoDialog::OnBnClickedCancel)
	//ON_BN_CLICKED(IDC_D1_Search, &CShowInfoDialog::OnBnClickedD1Search)
	ON_BN_CLICKED(IDC_D1_Search, &CShowInfoDialog::OnBnClickedD1Search)
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


void CShowInfoDialog::OnBnClickedCancel()
{
	DestroyWindow();
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//CDialog::OnCancel();
}


void CShowInfoDialog::PostNcDestroy()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_pView->m_pShowInfoDlg = NULL;
	delete this;
	//CDialog::PostNcDestroy();
}


/*void CShowInfoDialog::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
*/

void CShowInfoDialog::OnBnClickedD1Search()
{
	setlocale(LC_ALL, "korea");
	CString test = _T("");
	char* read;
	CStdioFile file;
	//CFile file;
	file.Open(_T("calory1.txt"),CFile::modeRead);
	//file.ReadString(test);
	while (1) {
		;
	}
	file.Close();
	
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

/*
char* CShowInfoDialog::UTF8toANSI(char* pszCode)stn 
{
	BSTR    bstrWide;
	char*   pszAnsi = NULL;
	int     nLength;
	nLength = MultiByteToWideChar(CP_UTF8, 0, pszCode, lstrlen(pszCode) + 1, NULL, NULL);
	bstrWide = SysAllocStringLen(NULL, nLength);
	MultiByteToWideChar(CP_UTF8, 0, pszCode, lstrlen(pszCode) + 1, bstrWide, nLength);
	nLength = WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, NULL, 0, NULL, NULL);
	pszAnsi = new char[nLength];
	WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, pszAnsi, nLength, NULL, NULL);
	SysFreeString(bstrWide);

	return pszAnsi;
	//return nullptr;
}
*/