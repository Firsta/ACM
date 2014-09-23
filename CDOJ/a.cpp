#include<cstdio>
#include<vector>
#define maxn 100000
queue<int> q;
vector<int> G[maxn];
int r[maxn][maxn];
int dis[maxn];
bool vis[maxn];
int min(int x,int y)
{
	if(x<y)
		return x;
	return y;
}
void bfs(int x)
{
	memset(vis,0,sizeof(vis));
	memset(dis,10001,sizeof(dis));
	q.push(x);
	dis[x]=0;
	vis[x]=true;
	while(!q.empty)
	{
		int u=q.front();
		q.pop();
		int len=G[u].size();
		for(int i=0;i<len;i++)
		{
			int v=G[u][i];
			if(!vis[v]&&v!=p1)
			{
				q.push(v);
				vis[v]=true;
				if(dis[u]+r[u][v]<dis[v])
				{
					dis[v]=dis[u]+r[u][v];
				}
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		memset(r,0,sizeof(r));
		while(m--)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			G[u].push_back(v);
			G[v].push_back(u);
			r[u][v]=r[v][u]=m;
		}
		int s,e,p1,p2,K;
		scanf("%d%d%d%d%d",&s,&e,&p1,&p2,&K);
		bfs(s);
		int t1=dis[e];
		int t2=dis[p1];
		bfs(p1);
		int t3=dis[e];
		int t4=dis[p2];
		bfs(p2);
		int t5=dis[e];
		int sum=min(t1,min(t2+t3,t2+K*t4+t5));
		sum=sum>=10001?-1:sum;
		printf("Case #%d: %d\n",cas,sum);
	}
}
