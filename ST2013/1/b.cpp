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

int mark[205],a[3];

int ab(int x)
{
	if(x<0)
		return -x;
}

void dfs(int x,int num)
{
	mark[ab(num)]=1;
	if(x==3)
		return;
	dfs(x+1,num-a[x]);
	dfs(x+1,num+a[x]);
	dfs(x+1,num);
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		int ans=0;
		for(int i=1;i<x;i++)
		{
			memset(mark,0,sizeof(mark));
			a[0]=i;a[1]=x-i;a[2]=y;
			dfs(0,0);
			int cnt=0;
			for(int j=1;j<=x+y;j++)
				if(mark[j])
					cnt++;
			if(cnt>ans)
				ans=cnt;
		}
		for(int i=1;i<y;i++)
		{
			memset(mark,0,sizeof(mark));
			a[0]=i;a[1]=y-i;a[2]=x;
			dfs(0,0);
			int cnt=0;
			for(int j=1;j<=x+y;j++)
				if(mark[j])
					cnt++;
			if(cnt>ans)
				ans=cnt;
		}
		cout<<ans<<endl;
	}
	return 0;
}
