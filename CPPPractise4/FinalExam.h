#ifndef FINALEXAM_H
#define FINALEXAM_H
#include "GradeActivity.h"
class FinalExam : public GradedActivity
{
	private:
			int numQuestions;
			double pointsEach;
			int numMissed;
	public:
			FinalExam()
			{
				numQuestions=0;
				pointsEach=0.0;
				numMissed=0;
			}
			void set(int,int);
			double getNumQuestions() const
			{
				return numQuestions;
			}
			double getPointsEach() const
			{
				return pointsEach;
			}
			int getNumMissed() const
			{
				return numMissed;
			}
			FinalExam(int questions,int missed)
			{
				set(questions,missed);
			}
};
#endif
