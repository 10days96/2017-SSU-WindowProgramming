#pragma once


// CPieChartDlg ��ȭ �����Դϴ�.

class CPieChartDlg : public CDialog
{
	DECLARE_DYNAMIC(CPieChartDlg)

public:
	CPieChartDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPieChartDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PIECHART };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
