// DlgTab4.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "DlgTab4.h"
#include "afxdialogex.h"


// CDlgTab4 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgTab4, CDialogEx)

CDlgTab4::CDlgTab4(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

CDlgTab4::~CDlgTab4()
{
}

void CDlgTab4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST4, m_List4);
}


BEGIN_MESSAGE_MAP(CDlgTab4, CDialogEx)
END_MESSAGE_MAP()


// CDlgTab4 �޽��� ó�����Դϴ�.
