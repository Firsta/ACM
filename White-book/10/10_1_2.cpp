#include<cstdio>
#include<cstring>
#include<cmath>
int vis[1000000];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(vis,0,sizeof(vis));
	int s=sqrt(m+0.5);
	int c=0;
	for(int i=2;i<=s;i++)
		if(!vis[i])
		{
			for(int j=i*i;j<=m;j+=i*i)
				vis[j]=1;
		}
	int cnt=0;
	for(int i=n;i<=m;i++)
		if(!vis[i])
			cnt++;
	printf("%d\n",cnt);
	return 0;
}
