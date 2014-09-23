#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>

using namespace std;

int a[70];
bool vis[70];
int n,x;

int cmp(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}

bool dfs(int t,int now,int res)
{
	if(res==0)
		return true;
	if(now==0)
	{
		while(vis[t])
			t++;
		vis[t]=1;
		if(a[t]==x)
		{
			if(dfs(0,0,res-x))
				return true;
			vis[t]=0;
			return false;
		}
		else
		{
			if(dfs(t+1,a[i],res))
				return true;
			vis[t]=0;
			return false;
		}
	}
	for(int i=t;i<n;i++)
	{
		if(i>0&&!vis[i-1]&&a[i]==a[i-1])
			continue;
		if(!vis[i])
		{
			if(now+a[i]==x)
			{
				vis[i]=1;
				if(dfs(0,0,res-x))
					return true;
				vis[i]=0;
				return false;
			}
			else if(now+a[i]<x)
			{
				vis[i]=1;
				if(dfs(i+1,now+a[i],res))
					return true;
				vis[i]=0;
			}
		}
	}
	return false;
}

int main()
{
	while((~scanf("%d",&n))&&n)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		qsort(a,n,sizeof(int),cmp);
		int ans=sum;
		for(x=a[0];x<=sum/2;x++)
		{
			if(sum%x==0)
			{
				for(int i=0;i<n;i++)
					vis[i]=0;
				if(dfs(0,0,sum))
				{
					ans=x;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

