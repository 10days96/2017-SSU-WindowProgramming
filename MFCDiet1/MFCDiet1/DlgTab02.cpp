// DlgTab02.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "DlgTab02.h"
#include "afxdialogex.h"


// CDlgTab02 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgTab02, CDialog)

CDlgTab02::CDlgTab02(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_TAB3, pParent)
{

}

CDlgTab02::~CDlgTab02()
{
}

void CDlgTab02::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List2);
}


BEGIN_MESSAGE_MAP(CDlgTab02, CDialog)
END_MESSAGE_MAP()


// CDlgTab02 �޽��� ó�����Դϴ�.
