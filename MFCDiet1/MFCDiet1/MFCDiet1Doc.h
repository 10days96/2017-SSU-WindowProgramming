
// MFCDiet1Doc.h : CMFCDiet1Doc 클래스의 인터페이스
//


#pragma once

typedef struct Food {
	//SYSTEMTIME date ;
	CTime date_day  ;  
	CTime date_month;
	CTime date_year;
	int time = 0;    //아침 점심 저녁 간식
	CString foodname;
	double plate;
	double cal;
} Food;

class CMFCDiet1Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CMFCDiet1Doc();
	DECLARE_DYNCREATE(CMFCDiet1Doc)

// 특성입니다.
public:

	typedef struct{
		int age;
		double length;
		double weight;
		BOOL gender;
		int exercise;
	} UserInfo;

	UserInfo user;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CMFCDiet1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
