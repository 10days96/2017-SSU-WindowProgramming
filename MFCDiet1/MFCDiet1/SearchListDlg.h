#pragma once
#include "afxwin.h"


// CSearchListDlg ��ȭ �����Դϴ�.

class CSearchListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSearchListDlg)

public:
	CSearchListDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSearchListDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCH_LIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_searchlist;
	CList<CString, CString> foodNameList;
	CString selectedName;
	BOOL whichButton;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
