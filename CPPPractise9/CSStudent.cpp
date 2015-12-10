#include "CSStudent.h"
#include <iostream>
using namespace std;

int CSStudent::getRemainingHours() const
{
	int reqHours,remainingHours;
	reqHours = MATH_HOURS + CS_HOURS + GEN_ED_HOURS;
	remainingHours = reqHours - (mathHours+csHours+genEdHours);
	return remainingHours;
}
