//Lab 3 exercise 3//Fall 2014#include<iostream>#include<iomanip>using namespace std;struct DailyTemp {    string date;    double temperature;};double averageTemp (DailyTemp temps[], int size) {    double total = 0;    for (int i=0; i<size; i++) {        total += temps[i].temperature;    }    return total/size;}int daysOver100 (DailyTemp temps[], int size) {    int days = 0;    for (int i=0; i<size; i++)        if (temps[i].temperature >= 100)            days++;    return days;}//change to return the INDEX of the element with max tempint max (DailyTemp temps[], int size) {    int max = 0;  // now stores the index of the max elem    for (int i=1; i<size; i++)        if (temps[i].temperature > temps[max].temperature)            max = i;    return max;}int main(){    cout << fixed << setprecision(1) << endl;        DailyTemp temperatures[100];    int count = 0;        cout << "Please enter the list of daily high temperatures and " << endl         << "dates they occurred on , (enter -1 when finished): ";    double temp;    cin >> temp;    while (temp != -1 && count < 100) {        temperatures[count].temperature = temp;        cin >> temperatures[count].date;  // added this for the date part        count++;        cin >> temp;    }        cout << "Average     = " << averageTemp(temperatures,count) << endl;    cout << "Days >= 100 = " << daysOver100(temperatures,count) << endl;    int maxIndex = max (temperatures,count);  //just call this once    cout << "Max temp    = " << temperatures[maxIndex].temperature                   << " on " << temperatures[maxIndex].date << endl;}