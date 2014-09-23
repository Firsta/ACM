#include<cstdio>
#include<climits>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int e[300005][2];
int map[10005][10005];
int cap[10005][10005];
int flow[10005][10005];
int a[10005];
int p[10005];
int f,s,t,m,n;
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[i][0]=u;
		e[i][1]=v;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&map[i][j]);
	for(int i=0;i<m;i++)
	{
		cap[e[i][0]][e[i][1]]=cap[e[i][1]][e[i][0]]=map[e[i][0]][e[i][1]];
	}
}
void bfs()
{
	queue<int> q;
	memset(flow,0,sizeof(a));
	f=0;
	for(;;)
	{
		memset(a,0,sizeof(a));
		a[s]=INT_MAX;
		q.push(s);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int v=1;v<=n;v++)
				if(!a[v]&&cap[u][v]>flow[u][v])
				{
					p[v]=u;
					if(a[u]<cap[u][v]-flow[u][v])
						a[v]=a[u];
					else
						a[v]=cap[u][v]-flow[u][v];
				}
		}
		if(a[t]==0)
			break;
		for(int u=t;u!=s;u=p[u])
		{
			flow[p[u]][u]+=a[t];
			flow[u][p[u]]-=a[t];
		}
		f+=a[t];
	}
}
string solve()
{
	int flag=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			s=i;t=j;
			bfs();
			if(f==0)
				if(map[i][j]!=-1)
				{
					flag=0;
					break;
				}
			else
				if(map[i][j]!=f)
				{
					flag=0;
					break;
				}
		}
	if(flag)
		return "Yes";
	else
		return "No";
}
int main()
{
	int ca;
	scanf("%d",&ca);
	for(int i=1;i<=ca;i++)
	{
		init();
		cout<<"Case #"<<i<<": "<<solve()<<endl;
	}
	return 0;
}
