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

char maze[35][35][35];
int vis[35][35][35];
int l,r,c,sl,sr,sc,el,er,ec;

struct node
{
	int x,y,z,step;
};

int dl[6]={ 1,-1,0, 0,0, 0};
int dr[6]={ 0, 0,1,-1,0, 0};
int dc[6]={ 0, 0,0, 0,1,-1};

int bfs(int sl,int sr,int sc)
{
	queue<node> q;
	node u;
	u.x=sl;u.y=sr;u.z=sc;u.step=0;
	vis[sl][sr][sc]=1;
	q.push(u);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		if(u.x==el&&u.y==er&&u.z==ec)
			return u.step;
		for(int d=0;d<6;d++)
		{
			node nn;
			nn.x=u.x+dl[d];
			nn.y=u.y+dr[d];
			nn.z=u.z+dc[d];
			nn.step=u.step+1;
			if(nn.x>=0&&nn.y>=0&&nn.z>=0&&nn.x<l&&nn.y<r&&nn.z<c&&!vis[nn.x][nn.y][nn.z]&&maze[nn.x][nn.y][nn.z]!='#')
			{
				q.push(nn);
				vis[nn.x][nn.y][nn.z]=1;
			}

		}
	}
	return -1;
}

int main()
{
	while(~scanf("%d%d%d",&l,&r,&c))
	{
		if(l==0&&r==0&&c==0)
			break;
		char str[35];
		memset(vis,0,sizeof(vis));
		for(int i=0;i<l;i++)
			for(int j=0;j<r;j++)
			{
				scanf("%s",str);
				for(int k=0;k<c;k++)
				{
					maze[i][j][k]=str[k];
					if(maze[i][j][k]=='S')
					{
						sl=i;
						sr=j;
						sc=k;
					}
					if(maze[i][j][k]=='E')
					{
						el=i;
						er=j;
						ec=k;
					}
				}
			}
		int ans;
		ans=bfs(sl,sr,sc);
		if(ans==-1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n",ans);
	}
	return 0;
}
