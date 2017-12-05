#include "stdafx.h"
#include "Food.h"


Food::Food()
{
}


Food::~Food()
{
}

IMPLEMENT_SERIAL(Food, CObject, 1)

void Food::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
		ar >> date_day >> date_month >> date_year >> time >> foodname >> plate >> cal >> Carbo >> Protein >> Fat >> Cholest >> Fiber >> Na;
	else
		ar << date_day << date_month << date_year << time << foodname << plate << cal << Carbo << Protein << Fat << Cholest << Fiber << Na;
}