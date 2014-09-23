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

int vis[100005];
char c[100005];

int main()
{
	int n;string s;
	cin>>n;
	while(n--)
	{
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='?'||vis[i]==-1)
				continue;
			if(vis[i]&&s[i]!=c[i]&&c[i]!='?')
				vis[i]=-1;
			else
			{
				c[i]=s[i];
				vis[i]=1;
			}
		}
	}
	for(int i=0;i<s.size();i++)
	{
		if(vis[i]==-1)
			cout<<'?';
		else if(!vis[i])
			cout<<'a';
		else
			cout<<c[i];
	}
	return 0;
}
