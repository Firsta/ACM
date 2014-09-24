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

int head[105],em,vis[105][105],vis2[105][105];

struct edge
{
	int to,next;
}edges[5000];

void addedge(int u,int v)
{
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,k,ans=0;
		em=0;
		cin>>n>>m>>k;
		memset(head,-1,sizeof(head));
		memset(vis,0,sizeof(vis));
		while(m--)
		{
			int u,v;
			cin>>u>>v;
			if(!vis[u][v])
			{
				addedge(u,v);
				addedge(v,u);
				vis[u][v]=vis[v][u]=1;
			}
		}
		while(1)
		{
			bool found=false;
			for(int i=0;i<n;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(vis[i][j])
						continue;
					int cnt=0;
					for(int e1=head[i];e1!=-1;e1=edges[e1].next)
						for(int e2=head[j];e2!=-1;e2=edges[e2].next)
						{
							if(edges[e1].to==edges[e2].to)
							{
								cnt++;
								break;
							}
						}
					if(cnt>=k)
					{
						ans++;
						addedge(i,j);
						addedge(j,i);
						vis[i][j]=vis[j][i]=1;
						found=true;
					}
				}
			}
			if(!found)
				break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
