#include<cstdio>
#define ll long long
ll x[50000];
ll y[50000];
ll dx[50000],dy[50000];
int main()
{
	int n;
	scanf("%d",&n);
	int temp[50000]={
		0
	};
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&x[i],&y[i]);
	}
	for(int i=0;i<n-1;i++)
	{
		dx[i]=x[i+1]-x[i];
		dy[i]=y[i+1]-y[i];
	}
	for(int i=0;i<n-2;i++)
		if(dx[i+1]*dy[i]!=dx[i]*dy[i+1])
		{
			temp[i]++;
			temp[i+1]++;
			temp[i+2]++;
		}
	int max=0,j;
	for(int i=0;i<n;i++)
		if(temp[i]>max)
		{
			max=temp[i];
			j=i;
		}
	if(dx[j+1]*dy[j]==dx[j]*dy[j+1])
		j=n-1;
	printf("%lld %lld",x[j+1],y[j+1]);
}
