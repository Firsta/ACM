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

int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		string s;
		cin>>s;
		int cnt=0;
		if(s[s.size()-1]=='B')
		{
			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='R')
					cnt++;
			}
			if(cnt==7)
				cout<<"Red"<<endl;
			else
				cout<<"Yellow"<<endl;
		}
		else
		{
			for(int i=0;i<s.size();i++)
				if(s[i]=='Y')
					cnt++;
			if(cnt==7)
				cout<<"Yellow"<<endl;
			else
				cout<<"Red"<<endl;
		}
	}
	return 0;
}
