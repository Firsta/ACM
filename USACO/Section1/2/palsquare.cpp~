/*
ID: firstaw1
PROG: palsquare
LANG: C++
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<sstream>
#include<vector>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<set>

typedef long long ll;
using namespace std;

string cha(int x,int ba)
{
	string s;
	int k=x;
	while(k!=0)
	{
		int t=k%ba;
		if(t>=10)
			s=s+(char)('A'+t-10);
		else
			s=s+(char)('0'+t);
		k/=ba;
	}
	string t;
	for(int i=s.size()-1;i>=0;i--)
		t+=s[i];
	return t;
}

bool judge(string s)
{
	string t;
	for(int i=s.size()-1;i>=0;i--)
		t=t+s[i];
	for(int i=0;i<s.size();i++)
		if(t[i]!=s[i])
			return false;
	return true;
}

int main()
{
	freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=300;i++)
	{
		if(judge(cha(i*i,n)))
		{
			cout<<cha(i,n)<<' ';
			string t=cha(i*i,n);
			cout<<t;
			cout<<endl;
		}
	}
	return 0;
}
