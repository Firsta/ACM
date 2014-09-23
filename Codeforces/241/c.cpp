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

int rn[1001],rm[1001],rs[1001];
bool vis[1001];

struct table
{
	int index;
	int maxn;
}ta[1001];

int cmp(const table &a,const table &b)
{
	if(a.maxn<b.maxn)
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>rn[i]>>rm[i];
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>ta[i].maxn;
		ta[i].index=i;
	}
	sort(ta,ta+k,cmp);
	for(int i=0;i<k;i++)
	{
		int money=0;
		int rnum;
		bool flag=false;
		for(int j=0;j<n;j++)
		{
			if(!vis[j]&&rn[j]<=ta[i].maxn&&rm[j]>money)
			{
				money=rm[j];
				rnum=j;
				flag=true;
			}

		}
		if(flag)
		{
			vis[rnum]=true;
			rs[rnum]=ta[i].index;
		}
	}
	int sum=0;
	int am=0;
	for(int i=0;i<n;i++)
		if(vis[i])
		{
			sum+=rm[i];
			am+=1;
		}
	cout<<am<<' '<<sum<<endl;
	for(int i=0;i<n;i++)
		if(vis[i])
			cout<<i+1<<' '<<rs[i]+1<<endl;
	return 0;
}
