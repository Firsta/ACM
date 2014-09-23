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

int vis[2010];
vector<int> G[1010];
int linked[2010];

bool find(int u)
{
	for(int i=0;i<G[u].size();i++)
	{
		int temp=G[u][i];
		if(!vis[temp])
		{
			vis[temp]=1;
			if(!linked[temp]||find(linked[temp]))
			{
				linked[temp]=u;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int n,m;
	int k;
	scanf("%d%d",&n,&m);
	scanf("%d",&k);
	while(k--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v+1000);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(find(i))
			ans++;
		memset(vis,0,sizeof(vis));
	}
	printf("%d\n",ans);
	return 0;
}
