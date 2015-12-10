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
	int cnt = size;
	while (cnt > 0) {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
	}
}

