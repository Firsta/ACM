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

int n,m;
int vis[55][55];
char maze[55][55];
int dx[]={
	0, 0,-1,1
};
int dy[]={
	1,-1,0,0
};

struct node
{
	int x,y;
	int step;
};

int bfs(node s,node e)
{
	queue<node> q;
	q.push(s);
	vis[s.x][s.y]=1;
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		for(int d=0;d<4;d++)
		{
			node next;
			next.x=now.x+dx[d];
			next.y=now.y+dy[d];
			next.step=now.step+1;
			if(next.x==e.x&&next.y==e.y)
				return next.step;
			if(next.x>=0&&next.x<n&&next.y>=0&&next.y<m&&!vis[next.x][next.y]&&maze[next.x][next.y]!='#')
			{
				vis[next.x][next.y]=1;
				char temp=maze[next.x][next.y];
				if(temp>='a'&&temp<='z')
				{
					for(int i=0;i<n;i++)
					{
						int find=0;
						for(int j=0;j<m;j++)
							if(maze[i][j]==temp&&(i!=next.x||j!=next.y))
							{
						//		cout<<next.x<<' '<<next.y;
						//		cout<<i<<' '<<j<<endl;
						//		cout<<"Find!"<<endl;
								next.x=i;
								next.y=j;
								q.push(next);
								find=1;
								break;
							}
						if(find)
							break;
					}
				}
				else
				{
					q.push(next);
				}
			}
		}
	}
	return -1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(vis,0,sizeof(vis));
		char str[55];
		node s,e;
		for(int i=0;i<n;i++)
		{
			scanf("%s",str);
			for(int j=0;j<m;j++)
			{
				maze[i][j]=str[j];
				if(maze[i][j]=='L')
				{
					s.x=i;
					s.y=j;
					s.step=0;
				}
				if(maze[i][j]=='Q')
				{
					e.x=i;
					e.y=j;
				}
			}
		}
/*		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cout<<maze[i][j];
			cout<<endl;
		}*/
		int ans=bfs(s,e);
	/*	for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cout<<vis[i][j];
			cout<<endl;
		}*/
		printf("%d\n",ans);
	}
	return 0;
}
