#include <iostream>
#include <string>
using namespace std;

void func(string);
int main()
{

string s = "aaabbbcccaa";
func(s);

return 0;

}
void func(string s)
{
	int len = s.length(), count=0, i=0;
	string substring="";
	char temp='\0';

	while(i<len)
	{

		if(count ==0)
		{
		temp = s[i];
		i++;
		substring+=temp;
		count++;
		}
		else
		{
			if(s[i]==temp)
			{
				count++;
				i++;
			}
			else
			{
				string cnt= to_string(count);
//				cout<<"Added this digit "<<count<<endl;
				substring+=cnt;
//				cout<<"Substring :"<<substring;
				count=0;
			}
		}
	}
	if(i==len)
		substring+=count;
		cout<<substring;

}
