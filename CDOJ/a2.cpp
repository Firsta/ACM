#include<cstdio>
#include<cstring>
#define maxn 100000
int dis[maxn][maxn];
int temp[maxn][maxn];
int n;
void floyd()
{
	for(int k=0;i<n;i++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					dis[i][j]=dis[i][j]<dis[i][k]+dis[k][j]?dis[i][j]:(dis[i][k]+dis[k][j]);
}
void floyd2()
{
	for(int k=0;i<n;i++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					temp[i][j]=temp[i][j]<temp[i][k]+temp[k][j]?temp[i][j]:(temp[i][k]+temp[k][j]);
}
void init()
{
	memset(dis,10001,sizeof(dis));
	for(int i=0;i<n;i++)
		dis[i][i]=0;
	memset(temp,10001,sizeof(temp));
	for(int i=0;i<n;i++)
		temp[i][i]=0;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		int m;
		scanf("%d%d",&n,&m);
		init();
		while(m--)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			dis[u][v]=dis[v][u]=w;
			temp[u][v]=temp[v][u]=w;
		}
		int s,e,p1,p2,K;
		scanf("%d%d%d%d%d",&s,&e,&p1,&p2,&K);
		floyd2();
		int t4=temp[s][p1];
		for(int i=0;i<n&&i!=p1;i++)
			dis[p1][i]=dis[i][p1]=10001;
		floyd();
		int t1=dis[s][e],t2=dis[p2][p1],t2=dis[p2][e],t3=dis[p1][e];
		int sum1=t1;
		int sum2=t4+t2;
		int sum3=t1+K*t2+t3;
		int sum=min(sum1,min(sum2,sum3));
		if(sum>=10001)
			sum=-1;
		printf("Case #%d: %d\n",cas,sum);
	}
	return 0;
}
