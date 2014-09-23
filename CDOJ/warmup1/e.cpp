#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ok;
int a[14];
int c[10];
/*void dfs(int i)
{
	if(i>14)
		return;
	if(i==14)
	{
		ok=1;
		return;
	}
	if(i<=12&&a[i]==a[i+1])
	{
		if(p==0)
		{
			p=1;
			dfs(i+2);
			p=0;
		}
		if(i<=11&&a[i+1]==a[i+2])
		{
			if(t+s<4)
			{
				t++;
				dfs(i+3);
				t--;
			}
		}
	}
	if(i<=11&&a[i]==a[i+1]-1&&a[i]==a[i+2]-2)
	{
		if(t+s<4)
		{
			s++;
			dfs(i+3);
			s--;
		}
	}
	return;
}*/
bool search(int dep)
{
	for(int i=1;i<=9;i++)
		if(c[i]>=3)
		{
			if(dep==3)
				return true;
			c[i]-=3;
			if(search(dep+1))
				return true;
			c[i]+=3;
		}
	for(int i=1;i<=7;i++)
		if(c[i]>=1&&c[i+1]>=1&&c[i+2]>=1)
		{
			if(dep==3) 
				return true;
			c[i]--;c[i+1]--;c[i+2]--;
			if(search(dep+1))
				return true;
			c[i]++;c[i+1]++;c[i+2]++;
		}
	return false;
}
bool check()
{
	for(int i=1;i<=9;i++)
		if(c[i]>=2)
		{
			c[i]-=2;
			if(search(0))
				return true;
			c[i]+=2;
		}
	return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		memset(c,0,sizeof(c));
		for(int i=0;i<14;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<14;i++)
			c[a[i]]++;
		if(check())
			printf("Vulnerable\n");
		else
			printf("Immune\n");
	}
	return 0;
}
