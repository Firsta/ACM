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

int grid[55][55];
int maze[55][55];
int vis[55][55][12];
int dx[]={-1, 0, 1, 0,-2, 0, 2, 0,-3, 0, 3, 0 };
int dy[]={ 0, 1, 0,-1, 0, 2, 0,-2, 0, 3, 0,-3 };
int n,m;

struct node
{
	int x,y;
	int dir;
	int t;
}s,f;

void bfs()
{
	memset(vis,0,sizeof(vis));
	queue<node> q;
	q.push(s);
	vis[s.x][s.y][s.dir]=1;
	//cout<<1;
	while(!q.empty())
	{
		node now=q.front();
	//	cout<<now.t+1<<endl;
		q.pop();
		for(int i=0;i<12;i++)
		{
			int x,y;
			x=now.x+dx[i];
			y=now.y+dy[i];
			if(x>0&&x<n&&y>0&&y<m&&!vis[x][y][now.dir]&&maze[x][y]&&i%4==now.dir)
			{
				if(i>7)
				{
					if(!maze[now.x+dx[i-4]][now.y+dy[i-4]]||!maze[now.x+dx[i-8]][now.y+dy[i-8]])
						break;
				}
				if(x==f.x&&y==f.y)
				{
					printf("%d\n",now.t+1);
					return;
				}
				node nn;
				nn.x=x;nn.y=y;
				nn.dir=now.dir;
				nn.t=now.t+1;
				vis[x][y][now.dir]=1;
				q.push(nn);
			}
		}
		if(!vis[now.x][now.y][(now.dir+1)%4])
		{
			node nn;
			nn.x=now.x;nn.y=now.y;nn.t=now.t+1;nn.dir=(now.dir+1)%4;
			vis[nn.x][nn.y][nn.dir]=1;
			q.push(nn);
		}
		if(!vis[now.x][now.y][(now.dir-1+4)%4])
		{
			node nn;
			nn.x=now.x;nn.y=now.y;nn.t=now.t+1;nn.dir=(now.dir-1+4)%4;
			vis[nn.x][nn.y][nn.dir]=1;
			q.push(nn);
		}
	}
	printf("-1\n");
}

void trans()
{
	memset(maze,0,sizeof(maze));
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			if(i==0||j==0||i==n||j==m)
				maze[i][j]=0;
			else if(grid[i][j]==1||grid[i][j-1]==1||grid[i-1][j-1]==1||grid[i-1][j]==1)
				maze[i][j]=0;
			else
				maze[i][j]=1;
		}
}

int main()
{
	while(~scanf("%d%d",&n,&m)&&(n||m))
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&grid[i][j]);
		trans();//transfer the grid into a maze
/*		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
				cout<<maze[i][j]<<' ';
			cout<<endl;
		}*/
		scanf("%d%d%d%d%d",&s.x,&s.y,&f.x,&f.y,&s.dir);
/*		if(s.x==f.x&&s.y==f.y)
		{
			cout<<0<<endl;
			continue;
		}*/
		s.t=0;
//		cout<<-1<<endl;
		bfs();
	}
	return 0;
}
