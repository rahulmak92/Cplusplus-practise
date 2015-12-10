#include "StudentTestScores.h"
void StudentTestScores::operator =(const StudentTestScores &right)
{
	delete [] testScores;
	studentName=right.studentName;
	numTestScores=right.numTestScores;
	testScores=new double[numTestScores];
	for(int i=0;i<numTestScores;i++)
	{
		testScores[i]=right.testScores[i];
	}
}
