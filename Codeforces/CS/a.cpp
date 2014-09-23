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

int n,k;
int vis[105];

bool check()
{
	for(int i=0;i<n;i++)
		if(!vis[i])
			return 0;
	return 1;
}

int main()
{
	string s;
	cin>>n>>k;
	cin>>s;
	int i=k-1;
	if(n-k<k)
	{
		for(;i<s.size();i++)
		{
			cout<<"PRINT "<<s[i]<<endl;
			vis[i]=1;
			if(i!=s.size()-1)
				cout<<"RIGHT"<<endl;
		}
		if(check())
			return 0;
		i--;
		while(vis[i])
		{
			i--;
			cout<<"LEFT"<<endl;
		}
		for(;i>=0;i--)
		{
			cout<<"PRINT "<<s[i]<<endl;
			if(i)
				cout<<"LEFT"<<endl;
		}
	}
	else
	{
		for(;i>=0;i--)
		{
			cout<<"PRINT "<<s[i]<<endl;
			vis[i]=1;
			if(i)
				cout<<"LEFT"<<endl;
		}
		if(check())
			return 0;
		i=0;
		while(vis[i])
		{
			i++;
			cout<<"RIGHT"<<endl;
		}
		for(;i<s.size();i++)
		{
			cout<<"PRINT "<<s[i]<<endl;
			if(i!=s.size()-1)
				cout<<"RIGHT"<<endl;
		}
	}
	return 0;
}
