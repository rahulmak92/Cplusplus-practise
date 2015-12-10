#ifndef BUDGET_H
#define BUDGET_H
class Budget
{
	private:
			 static double corpBudget;
			double divisionBudget;
	public:
			Budget()
			{
				divisionBudget=0;
			}
			void addBudget(double b)
			{
				divisionBudget +=b;
				corpBudget +=b;
			}
			double getDivisionBudget() const
			{
				return divisionBudget;
			}
			double getCorpBudget() const
			{
				return corpBudget;
			}
			static void mainOffice(double);
};
#endif
