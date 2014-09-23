#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	int t;
	cin>>s;
	int n1=s.find('+');
	int n2=s.find('=');
	int n=s.size();
	if(n-n2-1==n2-1)
		cout<<s;
	else if(n-n2-1>n2-1)
	{
		if((n-2*n2)==2)
		{		
			for(int i=0;i<n1+1;i++)
				cout<<'|';
			cout<<'+';
			for(int i=0;i<n2-n1-1;i++)
				cout<<'|';
			cout<<'=';
			for(int i=0;i<n-n2-2;i++)
				cout<<'|';
			cout<<endl;
		}
		else
			cout<<"Impossible"<<endl;
	}
	else
	{
		if(2*n2-n==2)
		{
			if(n1-1>0)
			{		
				for(int i=0;i<n1-1;i++)
					cout<<'|';
				cout<<'+';
				for(int i=0;i<n2-n1-1;i++)
					cout<<'|';
				cout<<'=';
				for(int i=0;i<n-n2;i++)
					cout<<'|';
				cout<<endl;
			}
			else
			{		
				for(int i=0;i<n1;i++)
					cout<<'|';
				cout<<'+';
				for(int i=0;i<n2-n1-2;i++)
					cout<<'|';
				cout<<'=';
				for(int i=0;i<n-n2;i++)
					cout<<'|';
				cout<<endl;
			}	
		}
		else 
			cout<<"Impossible"<<endl;
	}
	return 0;
}
