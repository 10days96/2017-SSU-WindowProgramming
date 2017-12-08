// DlgTab03.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "DlgTab03.h"
#include "MFCDiet1Doc.h"
#include "MFCDiet1View.h"
#include "MainFrm.h"
#include "afxdialogex.h"


// CDlgTab03 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgTab03, CDialog)

CDlgTab03::CDlgTab03(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_TAB4, pParent)
{

}

CDlgTab03::~CDlgTab03()
{
}

void CDlgTab03::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List3);
}


BEGIN_MESSAGE_MAP(CDlgTab03, CDialog)
	ON_LBN_SELCHANGE(IDC_LIST1, &CDlgTab03::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// CDlgTab03 �޽��� ó�����Դϴ�.


void CDlgTab03::OnLbnSelchangeList1()
{
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFCDiet1Doc * pDoc = (CMFCDiet1Doc *)pFrame->GetActiveDocument();
	CMFCDiet1View *pView = (CMFCDiet1View *)pFrame->GetActiveView();
	int nIndex = m_List3.GetCurSel();
	CString str;
	CString name;
	if (LB_ERR != nIndex) {
		m_List3.GetText(nIndex, str);
		AfxExtractSubString(name, str, 0, ' ');
		pView->c_edit1.SetWindowText(name);

		POSITION  pos = pDoc->list.GetHeadPosition();
		for (int i = 0; i < pDoc->list.GetCount(); i++) {
			Food tmp = (Food)pDoc->list.GetNext(pos);
			CString tmp_name;
			int meal;
			tmp_name = tmp.foodname;
			meal = tmp.time;
			if (!name.Compare(tmp_name) && meal == 2) {
				CString str, str2;
				str.Format(_T("%.1lf"), tmp.cal);
				str2.Format(_T("%.1lf"), tmp.plate);
				pView->c_edit2.SetWindowText(str);
				pView->c_edit3.SetWindowText(str2);
				break;
			}
		}
	}
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
