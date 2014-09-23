#include<iostream>
#include<string>
#define maxn 1000000005

typedef long long ll;
using namespace std;

int main()
{
	int n;
	char c;
	string s;
	cin>>n;
	ll l=-maxn;
	ll r=maxn;
	ll x;
	while(n--)
	{
		cin>>s;
		cin>>x;
		cin>>c;
		if(c=='Y')
		{
			if(s==">="&&l<x)
				l=x;
			if(s==">" &&l<x+1)
				l=x+1;
			if(s=="<="&&r>x)
				r=x;
			if(s=="<" &&r>x-1)
				r=x-1;
		}
		if(c=='N')
		{
			if(s==">="&&r>x-1)
				r=x-1;
			if(s==">" &&r>x)
				r=x;
			if(s=="<="&&l<x+1)
				l=x+1;
			if(s=="<" &&l<x)
				l=x;
		}
	}
	if(l>r)
		cout<<"Impossible";
	else
		cout<<l;
	return 0;
}
