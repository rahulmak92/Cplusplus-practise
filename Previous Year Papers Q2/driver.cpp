/*
 * Author : Rahul Makwana
 * Problem :
 * 2.	The value of  π can be calculated from the infinite series
 	 pi = 4 - 4/3 + 4/5 - 4/7 + 4/9 - 4/11 + 4/13......
More and more accurate values of π is obtained by including more and more of the smaller terms in the series.

Write a C++ function that returns a value for π accurate to a given positive tolerance. That is, the function should compute the return value by using the first n terms in the series such that, had the (n+1)th term been included in the calculation, the return value would not differ by more than the specified tolerance. Use the following prototype:
double CalcPi(double tolerance);
 *
 *
 */
#include <iostream>
#include <cmath>
using namespace std;
double CalcPi(double tolerance);
int main()
{
	double tolerance = 0.001;
	cout<<CalcPi(tolerance)<<endl;
	return 0;
}
double CalcPi(double tolerance)
{
	int counter=1;
	double e=1;
	double final_result=0;
	double tol = tolerance;
    double par = 0, impar = 0;
    while (e > tol && e > 0)
    {
          if (counter%2 == 0)
          {
                        par += 4.0/(2*counter +1);
          }
          if (counter%2 == 1)
          {
                        impar += 4.0/(2*counter +1);
          }
          ++counter;
          e = abs(M_PI - (4 + par - impar));
    }
    cout.precision(7);
    final_result=4+par-impar;
    return final_result;
}
