// DlgTab02.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDiet1.h"
#include "DlgTab02.h"
#include "MFCDiet1Doc.h"
#include "MFCDiet1View.h"
#include "MainFrm.h"
#include "afxdialogex.h"


// CDlgTab02 대화 상자입니다.

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
	ON_LBN_SELCHANGE(IDC_LIST1, &CDlgTab02::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// CDlgTab02 메시지 처리기입니다.


void CDlgTab02::OnLbnSelchangeList1()
{
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFCDiet1Doc * pDoc = (CMFCDiet1Doc *)pFrame->GetActiveDocument();
	CMFCDiet1View *pView = (CMFCDiet1View *)pFrame->GetActiveView();
	int nIndex = m_List2.GetCurSel();
	CString str;
	CString name;
	if (LB_ERR != nIndex) {
		m_List2.GetText(nIndex, str);
		AfxExtractSubString(name, str, 0, ' ');
		pView->c_edit1.SetWindowText(name);

		POSITION  pos = pDoc->list.GetHeadPosition();

		for (int i = 0; i < pDoc->list.GetCount(); i++) {
			Food tmp = (Food)pDoc->list.GetNext(pos);
			CString tmp_name;
			int meal;
			tmp_name = tmp.foodname;
			meal = tmp.time;
			if (!name.Compare(tmp_name) && meal == 1) {
				CString str, str2;
				str.Format(_T("%.1lf"), tmp.cal);
				str2.Format(_T("%.1lf"), tmp.plate);
				pView->c_edit2.SetWindowText(str);
				pView->c_edit3.SetWindowText(str2);
				break;
			}
		}
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
