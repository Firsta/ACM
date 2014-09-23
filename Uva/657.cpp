#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char map[55][55];
int vis[55][55];
int ans[50];
int m,n,cnt;
void dfs2(int x,int y)
{
	if(vis[x][y]||map[x][y]!='X'||x<0||y<0||x>=n||y>=m)
		return;
	else
	{
		vis[x][y]=1;
		             dfs2(x-1,y);
		dfs2(x,y-1);		  dfs2(x,y+1);
			     dfs2(x+1,y);
	}
}
void dfs1(int x,int y)
{
	if(vis[x][y]||map[x][y]=='.'||x<0||y<0||x>=n||y>=m)
		return;
	else
	{
		if(map[x][y]=='X')
		{
			dfs2(x,y);
			cnt++;
		}
		else
		{
			vis[x][y]=1;
			            dfs1(x-1,y);
			dfs1(x,y-1);		  dfs1(x,y+1);
			            dfs1(x+1,y);
		}
	}
}
int main()
{
	int c=1;
	while(scanf("%d%d",&m,&n)==2&&m!=0)
	{
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
		{
			scanf("%s",map[i]);
			getchar();
		}
		int t=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(!vis[i][j]&&map[i][j]=='*')
				{
					cnt=0;
					dfs1(i,j);
					ans[t++]=cnt;
				}
			}
		sort(ans,ans+t);
		printf("Throw %d\n",c);
		c++;
		if(t>0)
			printf("%d",ans[0]);
		for(int i=1;i<t;i++)
			printf(" %d",ans[i]);
		printf("\n");
	}
}
