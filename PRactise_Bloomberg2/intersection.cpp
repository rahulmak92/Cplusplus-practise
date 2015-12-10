#include <iostream>
using namespace std;

void printIntersection(int[],int[],int,int);
int main()
{
	int a[9]={1,2,2,3,3,3,4,5,5};
	int b[9]={1,2,3,3,4,4,5,5,5};
	printIntersection(a,b,9,9);
	return 0;
}
void printIntersection(int arr1[], int arr2[], int m, int n)
{
  int i = 0, j = 0;
  while(i < m && j < n)
  {
    if(arr1[i] < arr2[j])
      i++;
    else if(arr2[j] < arr1[i])
      j++;
    else /* if arr1[i] == arr2[j] */
    {
      printf(" %d ", arr2[j++]);
      i++;
    }
  }
}
