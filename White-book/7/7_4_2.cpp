#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
int n;
int vis[100];
int A[100];
int isp(int x)
{
	int m=floor(sqrt(x)+0.5);
	if(x==1)
		return 0;
	for(int i=2;i<=m;i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}
void dfs(int cur)
{
	if(cur==n&&isp(A[0]+A[n-1]))
	{
		for(int i=0;i<n;i++)
			printf("%d ",A[i]);
		printf("\n");
	}
	else for(int i=2;i<=n;i++)
		if(!vis[i]&&isp(A[cur-1]+i))
		{
			A[cur]=i;
			vis[i]=1;
			dfs(cur+1);
			vis[i]=0;
		}
}
int main()
{
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	A[0]=1;
	dfs(1);
	return 0;
}
