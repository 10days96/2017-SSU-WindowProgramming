// DlgTab3.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "DlgTab3.h"
#include "afxdialogex.h"


// CDlgTab3 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgTab3, CDialogEx)

CDlgTab3::CDlgTab3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CDlgTab3::~CDlgTab3()
{
}

void CDlgTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_List3);
}


BEGIN_MESSAGE_MAP(CDlgTab3, CDialogEx)
END_MESSAGE_MAP()


// CDlgTab3 �޽��� ó�����Դϴ�.
