#pragma once


// CDlgTab01 ��ȭ �����Դϴ�.

class CDlgTab01 : public CDialog
{
	DECLARE_DYNAMIC(CDlgTab01)

public:
	CDlgTab01(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgTab01();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB1};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
