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
#define MAXN 10010

typedef long long ll;
using namespace std;

vector<int> G[MAXN];
int in[MAXN],sum[MAXN];

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		memset(in,0,sizeof(in));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
			G[i].clear();
		while(m--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			G[y].push_back(x);
			in[x]++;
		}
		queue<int> q;
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(in[i]==0)
				q.push(i);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();cnt++; 
			for(int i=0;i<G[u].size();i++)
			{
				int temp=G[u][i];
				if(sum[temp]<sum[u]+1)
					sum[temp]=sum[u]+1;
				in[temp]--;
				if(in[temp]==0)
					q.push(temp);
			}
		}
		if(cnt==n)
		{
			int ans=888*n;
			for(int i=1;i<=n;i++)
				ans+=sum[i];
			printf("%d\n",ans);
		}
		else
			printf("-1\n");
	}
	return 0;
}
