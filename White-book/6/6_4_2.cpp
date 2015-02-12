#include<cstdio>
#include<cstdlib>
#include<cstring>
const int MAXN=100;
int vis[MAXN][MAXN],fa[MAXN][MAXN],maze[MAXN][MAXN],dist[MAXN][MAXN],q[MAXN*MAXN],last_dir[MAXN][MAXN];
int n,m,ok,r,s;
int dx[4]={
	-1,0,0,1
};
int dy[4]={
	0,-1,1,0
};
char name[4]={
	'U','L','R','D'
};
void bfs(int x,int y,int r,int s)
{
	int front=0,rear=0,d,u;
	ok=0;
	u=x*m+y;
	vis[x][y]=1;fa[x][y]=u;dist[x][y]=0;
	q[rear++]=u;
	while(front<rear)
	{
		u=q[front++];
		x=u/m;y=u%m;
		if(x==r&&y==s)
		{
			ok=1;
			return;
		}
		for(d=0;d<r;d++)
		{
			int nx=x+dx[d],ny=y+dy[d];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&maze[nx][ny]&&!vis[nx][ny])
			{
				int v=nx*m+ny;
				q[rear++]=v;
				vis[nx][ny]=1;
				dist[nx][ny]=dist[x][y]+1;
				fa[nx][ny]=u;
				last_dir[nx][ny]=d;
			}
		}
	}
}
void printf_path(int x,int y)
{
	int fx=fa[x][y]/m;
	int fy=fa[x][y]%m;
	if(fx!=x||fy!=y)
	{
		printf_path(fx,fy);
		putchar(name[last_dir[x][y]]);
	}
	putchar('\n');
}
int main()
{
	char t[MAXN];
	while(scanf("%d%d%d%d",&n,&m,&r,&s)==4)
	{
		memset(vis,0,sizeof(vis));
		memset(maze,0,sizeof(maze));
		memset(fa,0,sizeof(fa));
		memset(dist,0,sizeof(dist));
		for(int i=0;i<n;i++)
		{
			scanf("%s",t);
			for(int j=0;j<n;j++)
				maze[i][j]=t[j]-'0';
		}
		bfs(0,0,r,s);
		if(ok)
		{
			printf_path(r,s);
		}else{
			printf("-1\n");
		}
	}
}
