#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
int lock[100000];
int fa[100000];
int key[100000];
int inp[100000];
int vis[100000];
vector<int> G[100000];
queue<int> q,p;
int n,m;
int find(int x)
{
	if(fa[x]!=x)
		fa[x]=find(fa[x]);
	return fa[x];
}
void bfs()
{
	memset(vis,0,sizeof(vis));
	memset(inp,0,sizeof(inp));
	q.push(0);
	vis[0]=1;
	bool change=true;
	while(1)
	{
		change=false;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int v=0;v<G[u].size();v++)
			{
				if(lock[G[u][v]]==1)
				{
					if(!inp[G[u][v]])
					{
						p.push(G[u][v]);
						inp[G[u][v]]=1;
					}
					continue;
				}
				if(!vis[G[u][v]])
				{
					q.push(G[u][v]);
					vis[G[u][v]]=1;
					if(key[G[u][v]])
						lock[key[G[u][v]]]=0;
					change=true;
				}
			}
		}
		if(change==false) break;
		if(!p.empty())
		{
			for(int i=0;i<p.size();i++)
			{
				int u=p.front();
				p.pop();
				if(lock[u]==0)
				{
					q.push(u);
					vis[u]=1;
				}
				else
					p.push(u);
			}
		}
	}
}
int main()
{
	int t;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
			fa[i]=i;
		while(m--)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
			u=find(u);v=find(v);
			fa[u]=v;
		}
		int ln;
		cin>>ln;
		memset(key,0,sizeof(key));
		memset(lock,0,sizeof(lock));
		while(ln--)
		{
			int x,y;
			cin>>x>>y;
			key[y]=x;
			lock[x]=1;
		}
		for(int i=0;i<n;i++)
			find(i);
		bool link=true;
		for(int i=0;i<n;i++)
			if(fa[i]!=fa[0])
			{
				link=false;
				break;	
			}
		if(!link)
		{
			printf("Case #%d: No\n",c);
			continue;
		}
		if(key[0]!=0)
			lock[key[0]]=0;
		while(!q.empty()) 
			q.pop();
		while(!p.empty()) 
			p.pop();
		bfs();
		if(!p.empty())
			printf("Case #%d: No\n",c);
		else
			printf("Case #%d: Yes\n",c);
	}
	return 0;
}
