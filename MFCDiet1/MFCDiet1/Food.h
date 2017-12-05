#pragma once
class Food : public CObject
{
	DECLEAR_SERIAL(Food);
public:
	CTime date_day;
	CTime date_month;
	CTime date_year;
	int time = 0;    //��ħ ���� ���� ����
	CString foodname;
	double plate;
	double cal;
	double Carbo;
	double Protein;
	double Fat;
	double Cholest;
	double Fiber;
	double Na;

public:
	Food();
	~Food();
	void Serialize(CArchive& ar);
};

