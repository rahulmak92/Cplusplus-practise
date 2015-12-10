#include "PassFailActivity.h"
char PassFailActivity::getLetterGrade() const
{
	char letterGrade;
	double score = GradedActivity::getScore();
	if( score >= minPassingScore)
	{
		letterGrade = 'P';
	}
	else
	{
		letterGrade = 'F';
	}
	return letterGrade;
}
