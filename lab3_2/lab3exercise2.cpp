//Lab 3 exercise 2//Fall 2014#include<iostream>#include<iomanip>using namespace std;double averageTemp (double temps[], int size) {    double total = 0;    for (int i=0; i<size; i++) {        total += temps[i];    }    return total/size;}int daysOver100 (double temps[], int size) {    int days = 0;    for (int i=0; i<size; i++)        if (temps[i] >= 100)            days++;    return days;}double max (double temps[], int size) {    double max = temps[0];    for (int i=1; i<size; i++)        if (temps[i] > max)            max = temps[i];    return max;}int main(){    cout << fixed << setprecision(1) << endl;        double temperatures[100];    int count = 0;        //input the values (this is almost EXACTLY like the lecture example!)    cout << "Please enter the list of daily high temperatures, "         << "(enter -1 when finished): ";    double temp;    cin >> temp;    while (temp != -1 && count < 100) {        temperatures[count] = temp;        count++;        cin >> temp;    }        //output the statistics, use count as the size    cout << "Average     = " << averageTemp(temperatures,count) << endl;    cout << "Days >= 100 = " << daysOver100(temperatures,count) << endl;    cout << "Max temp    = " << max (temperatures,count) << endl;}