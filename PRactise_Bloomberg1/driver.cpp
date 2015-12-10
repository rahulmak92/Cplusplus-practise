#include "IntersectionArray.h"
#include <string>
using namespace std;
int main()
{
	IntersectionArray st(10);
	st.push(90);
	st.push(12);
	st.push(23);
	st.push(44);st.push(2);st.push(189);st.push(345);
	cout<<"elements in stack : "<<st.size()<<endl;
	st.display();
	cout<<"top element in stack = "<<st.topElement()<<endl;

	st.pop_last();
	st.pop_last();
	cout<<"After popping few: "<<endl;
	cout<<"elements in stack : "<<st.size()<<endl;
	st.display();
	cout<<"top element in stack = "<<st.topElement()<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"-----------------------------------------"<<endl;
	string s1;
	s1 = "84/";
	if(isdigit(s1[1]))
	{
		cout<<"Yes";
	}
	return 0;
}
