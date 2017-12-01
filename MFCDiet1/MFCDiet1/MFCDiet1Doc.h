
// MFCDiet1Doc.h : CMFCDiet1Doc Ŭ������ �������̽�
//


#pragma once

typedef struct Food {
	//SYSTEMTIME date ;
	CTime date_day  ;  
	CTime date_month;
	CTime date_year;
	int time = 0;    //��ħ ���� ���� ����
	CString foodname;
	double plate;
	double cal;
} Food;

class CMFCDiet1Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMFCDiet1Doc();
	DECLARE_DYNCREATE(CMFCDiet1Doc)

// Ư���Դϴ�.
public:

	typedef struct{
		int age;
		double length;
		double weight;
		BOOL gender;
		int exercise;
	} UserInfo;

	UserInfo user;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CMFCDiet1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
