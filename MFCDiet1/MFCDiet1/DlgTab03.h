#pragma once


// CDlgTab03 ��ȭ �����Դϴ�.

class CDlgTab03 : public CDialog
{
	DECLARE_DYNAMIC(CDlgTab03)

public:
	CDlgTab03(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgTab03();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
