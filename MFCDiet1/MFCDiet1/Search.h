#pragma once


// CSearch ��ȭ �����Դϴ�.

class CSearch : public CDialog
{
	DECLARE_DYNAMIC(CSearch)

public:
	CSearch(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	
	virtual ~CSearch();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCH_CHECK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
