// DlgTab2.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "DlgTab2.h"
#include "afxdialogex.h"


// CDlgTab2 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgTab2, CDialogEx)

CDlgTab2::CDlgTab2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CDlgTab2::~CDlgTab2()
{
}

void CDlgTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_List2);
}


BEGIN_MESSAGE_MAP(CDlgTab2, CDialogEx)
END_MESSAGE_MAP()


// CDlgTab2 �޽��� ó�����Դϴ�.
