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

int react[55][55];
int vis[55];
ll ans;
int n,m;
ll cnt;

void dfs(int x)
{
	vis[x]=1;
	for(int i=1;i<=n;i++)
		if(react[i][x]&&!vis[i])
		{
			cnt++;
			dfs(i);
		}
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		react[a][b]=react[b][a]=1;
	}
	ans=1;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			cnt=0;
			dfs(i);
			for(int j=0;j<cnt;j++)
				ans*=2;
		}
	cout<<ans<<endl;
	return 0;
}
