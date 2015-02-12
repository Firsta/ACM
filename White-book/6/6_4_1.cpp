#include<cstdio>
#include<cstring>
const int MAXN=10000;
int mat[MAXN][MAXN],vis[MAXN][MAXN];
void dfs(int x,int y)
{
	if(!mat[x][y]||vis[x][y]) return;
	vis[x][y]=1;
	dfs(x-1,y-1);dfs(x-1,y);dfs(x-1,y+1);
	dfs(x,y-1);             dfs(x,y+1);
	dfs(x+1,y-1);dfs(x+1,y);dfs(x+1,y+1);
}
int main()
{
	int n;
	char s[MAXN];
	while(scanf("%d",&n)==1)
	{
		memset(mat,0,sizeof(mat));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			for(int j=0;j<n;j++)
			{
				mat[i+1][j+1]=s[j]-'0';
			}
		}
		int count=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(!vis[i][j]&&mat[i][j]){
					count++;
					dfs(i,j);
				}
		printf("%d\n",count);
	}
	return 0;
}
