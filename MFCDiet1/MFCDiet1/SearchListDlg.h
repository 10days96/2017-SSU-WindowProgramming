#pragma once
#include "afxwin.h"


// CSearchListDlg 대화 상자입니다.

class CSearchListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSearchListDlg)

public:
	CSearchListDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSearchListDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCH_LIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_searchlist;
	CList<CString, CString> foodNameList;
	CString selectedName;
	BOOL whichButton;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
