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
#define MAXN 100005

typedef long long ll;
using namespace std;

ll sumv[MAXN];
vector<ll> addv[MAXN];

ll sum(int l,int r)
{
	int ret=(r+1)*r/2-(l-1)*l/2;
	return ret;
}

ll sumw(int l,int r,int w)
{
	int ret=(r-l+1)*w;
	return ret;
}

void build(ll id,ll l,ll r)
{	
	int lc=id*2,rc=id*2+1;
	if(l==r)
	{
		sumv[id]=0;
	}
	else
	{
		ll mid=(l+r)/2;
		build(lc,l,mid);
		build(rc,mid+1,r);
		sumv[id]=sumv[lc]+sumv[rc];
	}
}

void maintain(ll id,ll l,ll r)
{
	if(addv[id].size()!=0)
	{
		int mid=(l+r)/2;
		for(int i=0;i<addv[id].size();i++)
		{
			int w=addv[id][i];
			addv[id*2].push_back(w);
			addv[id*2+1].push_back(w);
			int tl,tr;
			tl=l,tr=mid;
			if(tr<=w)
				sumv[id*2]+=sumw(tl,tr,w)-sum(tl,tr);
			else if(tl>=w)
				sumv[id*2]+=sum(tl,tr)-sumw(tl,tr,w);
			else
				sumv[id*2]+=sum(tl,w-1)-sumw(tl,w-1,w)+sumw(w+1,tr,w)-sum(w+1,tr);
			tl=mid+1,tr=r;
			if(tr<=w)
				sumv[id*2+1]+=sumw(tl,tr,w)-sum(tl,tr);
			else if(tl>=w)
				sumv[id*2+1]+=sum(tl,tr)-sumw(tl,tr,w);
			else
				sumv[id*2+1]+=sum(tl,w-1)-sumw(tl,w-1,w)+sumw(w+1,tr,w)-sum(w+1,tr);
		}
		addv[id].clear();
	}
}

void update(ll id,ll l,ll r,ll w,ll a,ll b)
{
	int lc=id*2,rc=id*2+1;
	if(a<=l&&b>=r)
	{
		addv[id].push_back(w);
		if(r<=w)
			sumv[id]+=sumw(l,r,w)-sum(l,r);
		else if(l>=w)
			sumv[id]+=sum(l,r)-sumw(l,r,w);
		else
			sumv[id]+=sum(l,w-1)-sumw(l,w-1,w)+sumw(w+1,r,w)-sum(w+1,r);
	}
	else
	{
		maintain(id,l,r);
		ll mid=(l+r)/2;
		if(a<=mid)
			update(lc,l,mid,w,a,b);
		if(b>mid)
			update(rc,mid+1,r,w,a,b);
		sumv[id]=sumv[lc]+sumv[rc];
	}
}

int query(int id,int l,int r,int a,int b)
{
	if(a<=l&&b>=r)
		return sumv[id];
	else
	{
		maintain(id,l,r);
		int mid=(l+r)/2;
		int ans=0;
		if(a<=mid)
			ans+=query(id*2,l,mid,a,b);
		if(b>mid)
			ans+=query(id*2+1,mid+1,r,a,b);
		return ans;
	}
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int t,l,r,x;
		cin>>t;
		if(t==1)
		{
			cin>>l>>r>>x;
			update(1,1,n,x,l,r);
		}
		else
		{
			cin>>l>>r;
			cout<<query(1,1,n,l,r)<<endl;
		}
	}
	return 0;
}
