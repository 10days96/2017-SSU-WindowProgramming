#pragma once
class CMFCDiet1View;

// CShowInfoDialog ��ȭ �����Դϴ�.

class CShowInfoDialog : public CDialog
{
	DECLARE_DYNAMIC(CShowInfoDialog)

public:
	CShowInfoDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CShowInfoDialog();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CMFCDiet1View* m_pView;
	//afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedCancel();
};
