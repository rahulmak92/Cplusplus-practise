#include "FinalExam.h"
void FinalExam::set(int questions,int missed)
{
	double numericScore=0.0;
	numQuestions = questions;
	numMissed = missed;

	pointsEach = 100.0/numQuestions;
	numericScore = 100.0 - (missed*pointsEach);
	setScore(numericScore);
}
