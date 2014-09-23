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
#define MAXN 50100

typedef long long ll;
using namespace std;

ll a[MAXN];
ll x;int n,m;

//search(l,r)
//ans!=0
ll search(ll l,ll r)
{
	int del;
	ll ans=0;
	int flag=0;
	ll mid;
	while(l<r)
	{
//		if(flag)
//			break;
		mid=(l+r)/2;
		del=0;
		int i=0;
		for(int j=i+1;j<n+2;j++)
		{
			if(a[j]-a[i]<=mid)
			{
				if(i!=0||j!=n+1)
					del++;
			}
			else
				i=j;
		}
	//	cout<<l<<' '<<r<<' '<<mid<<' '<<del<<endl;
		if(del<=m)
			l=mid+1;
		else
			r=mid;
	}
	return l;
}

int main()
{
	cin>>x>>n>>m;
	ll ans;
	int l=x;
	a[0]=0;a[n+1]=x;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]-a[i-1]<l)
			l=a[i]-a[i-1];
	}
	if(a[n+1]-a[n]<l)
		l=a[n+1]-a[n];
	sort(a,a+n+2);
/*	if(m==0)
	{
		ans=x;
		for(int i=0;i<n+1;i++)
			if(a[i+1]-a[i]<ans)
				ans=a[i+1]-a[i];
		cout<<ans;
		return 0;
	}*/
/*	if(m==n)
	{
		cout<<x;
		return 0;
	}*/
	ans=search(0,x);
	cout<<ans;
	return 0;
}
