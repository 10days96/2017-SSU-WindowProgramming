#pragma once


// CShowBMIDlg ��ȭ �����Դϴ�.

class CShowBMIDlg : public CDialog
{
	DECLARE_DYNAMIC(CShowBMIDlg)

public:
	CShowBMIDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CShowBMIDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOWBMI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
