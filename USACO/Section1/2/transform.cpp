/*
ID: firstaw1
PROG: transform
LANG: C++
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<sstream>
#include<vector>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<set>

typedef long long ll;
using namespace std;

char a[10][10];
char b[10][10];
int n;

void rotate()
{
	char t[10][10];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			t[j][n-i-1]=a[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=t[i][j];
}

void reflect()
{
	char t[10][10];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			t[i][n-j-1]=a[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=t[i][j];
}

bool cmp()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]!=b[i][j])
				return false;
	return true;
}

int main()
{
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	cin>>n;
	char tmp[10];
	for(int i=0;i<n;i++)
	{
		scanf("%s",tmp);
		for(int j=0;j<n;j++)
			a[i][j]=tmp[j];
	}
	for(int i=0;i<n;i++)
	{
		scanf("%s",tmp);
		for(int j=0;j<n;j++)
			b[i][j]=tmp[j];
	}
	int rt1=0,flag1=0,flag0=0;
	for(int i=0;i<4;i++)
	{
		if(!cmp())
		{
			rotate();
			rt1++;
		}
		else if(rt1!=0)
		{
			flag1=1;
			break;
		}
		else
		{
			rotate();
			flag0=1;
			rt1++;
		}
	}
	reflect();
	int rt2=1,flag2=0;
	for(int i=0;i<4;i++)
	{
		if(!cmp())
		{
			rotate();
			rt2++;
		}
		else
		{
			flag2=1;
			break;
		}
	}
	int ans;
	if(flag1)
	{
		if(rt1==1)
			ans=1;
		else if(rt1==2)
		{
			ans=2;
		}
		else if(rt1==3)
			ans=3;
	}
	else if(flag2)
	{
		if(rt2==1)
			ans=4;
		else if(rt2>1)
			ans=5;
	}
	else if(flag0)
		ans=6;
	else
		ans=7;
	cout<<ans<<endl;
	return 0;
}
