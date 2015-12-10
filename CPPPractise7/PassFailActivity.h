#ifndef PASSFAILACTIVITY_H
#define PASSFAILACTIVITY_H
#include "GradeActivity.h"
class PassFailActivity : public GradedActivity
{
	private:
			double minPassingScore;
	public:
			PassFailActivity():GradedActivity()
			{
				minPassingScore=0.0;
			}
			PassFailActivity(double mps):GradedActivity()
			{
				minPassingScore=mps;
			}
			void setMinPassingScore(double mps)
			{
				minPassingScore=mps;
			}
			double getMinPassingScore() const
			{
				return minPassingScore;
			}
			virtual char getLetterGrade() const;
};
#endif
