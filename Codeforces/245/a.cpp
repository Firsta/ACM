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

int co[105],ispo[105],vis[105],l[105],r[105];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		ispo[temp]=1;
	}
	for(int i=0;i<m;i++)
	{
		cin>>l[i]>>r[i];
		int cor=0;
		for(int j=l[i];j<=r[i];j++)
		{
			if(ispo[j]&&!vis[j])
			{
				co[j]=cor;
				vis[j]=1;
				cor=!cor;
			}
			if(ispo[j]&&vis[j])
				cor=!co[j];
		}
	}
	bool flag=1;
	for(int i=0;i<m;i++)
	{
		int red=0,blue=0;
		for(int j=l[i];j<=r[i];j++)
		{
			if(ispo[j])
			{
				if(co[j]==1)
					blue++;
				else
					red++;
			}
			if(red-blue>1||blue-red>1)
				flag=0;
		}
	}
	if(!flag)
		cout<<-1<<endl;
	else
	{
		int cnt=0;
		for(int i=0;i<105;i++)
		{
			if(ispo[i])
			{	
				if(cnt==0)
				{
					cout<<co[i];
					cnt++;
				}
				else
					cout<<' '<<co[i];
			}
		}
	}
	return 0;
}
