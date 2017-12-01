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
	, m_D1_EDIT_Name(_T(""))
	, m_D1_Kcal_Edit(_T(""))
{

}

CShowInfoDialog::~CShowInfoDialog()
{
}

void CShowInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, ID_D1_Name_Edit, m_D1_EDIT_Name);
	DDX_Text(pDX, ID_D1_Kcal_Edit, m_D1_Kcal_Edit);
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
	CString str;
	CStdioFile file;
	CString Find_Name;
	CString calory[7];
	int count = 0;
	GetDlgItemText(ID_D1_Name_Edit,Find_Name);
	setlocale(LC_ALL, "");
	file.Open(_T("calory1.txt"),CFile::modeRead);
	while (file.ReadString(str)) {
		if (str.Find(Find_Name) != -1) {
			AfxExtractSubString(calory[0],str,1,',');
			SetDlgItemText(ID_D1_Kcal_Edit,calory[0]);
			m_Info_Calory = _wtof(calory[0]);

			AfxExtractSubString(calory[1], str, 2, ',');
			SetDlgItemText(ID_D1_Carbo_Edit, calory[1]);
			m_Info_Carbo = _wtof(calory[1]);

			AfxExtractSubString(calory[2], str, 3, ',');
			SetDlgItemText(ID_D1_Protein_Edit, calory[2]);
			m_Info_Cholest= _wtof(calory[2]);

			AfxExtractSubString(calory[3], str, 4, ',');
			SetDlgItemText(ID_D1_Fat_Edit, calory[3]);
			m_Info_Fat = _wtof(calory[3]);

			AfxExtractSubString(calory[4], str, 5, ',');
			SetDlgItemText(ID_D1_Cholest_Edit, calory[4]);
			m_Info_Cholest= _wtof(calory[4]);

			AfxExtractSubString(calory[5], str, 6, ',');
			SetDlgItemText(ID_D1_Fiber_Edit, calory[5]);
			m_Info_Fiber = _wtof(calory[5]);

			AfxExtractSubString(calory[6], str, 7, ',');
			SetDlgItemText(ID_D1_Na_Edit, calory[6]);
			m_Info_Na = _wtof(calory[6]);
			break;
		}
		else {

		}
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