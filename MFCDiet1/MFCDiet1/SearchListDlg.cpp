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
