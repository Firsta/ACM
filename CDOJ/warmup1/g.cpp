#include<cstdio>
#include<cstring>
int v[20];
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		memset(v,0,sizeof(v));
		for(int i=0;i<20;i++)
			scanf("%d",&v[i]);
		for(int i=18;i>=0;i--)
		{
			v[i]+=v[i+1]/2;
			v[i+1]=v[i+1]%2?1:0;
		}
		printf("%d",v[0]);
		for(int i=1;i<20;i++)
			printf(" %d",v[i]);
		printf("\n");
	}
}
