#include<iostream>
using namespace std;
void printSpecialPairs(int*, int);
int main() {
	int size = 0;
	cout << "How many elements:";
	cin >> size;
	int array[size];
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	printSpecialPairs(array, size);
	return 0;
}
void printSpecialPairs(int *arr, int size) {
	int cnt = size, outer_count=size-1;
	//while (outer_count>0)
	{
		//for (int i = 0; i < size; i++)
		{

			cnt=0;
			while(outer_count>=0)
			{
				//cout<<"Checking " << arr[outer_count] <<" with "<<arr[cnt]<< " ";
				if(outer_count!=cnt && (7-arr[outer_count])==arr[cnt])
				{
					cout<<"This matches : ("<<arr[cnt]<<", "<<arr[outer_count]<<")";
					cnt++;
				}
				outer_count--;

				cout<<endl;
			}
		}

	}
}

