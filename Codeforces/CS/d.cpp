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

int G[10005][10006];
int vis[10005][10005];

stack<int> q;
int n,m;
void euler(int u)
{
	for(int v=0;v<n;v++)
		if(G[u][v]&&!vis[u][v])
		{
			vis[u][v]=vis[v][u]=1;
			q.push(v+1);
			euler(v);
		}
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(i==j)
				G[i][j]=0;
			else
				G[i][j]=1;
		}
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		G[a][b]=0;
	}
	int flag=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				vis[j][k]=0;
		while(!q.empty())
			q.pop();
		euler(i);
		if(q.size()==n)
		{
			flag=1;
			break;
		}
	}
	if(flag)
		while(!q.empty())
		{
			int u=q.top();
			cout<<u<<' ';
			q.pop();
		}
	else
		cout<<"-1";
	return 0;
}
