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

int fa[100005];

int find(int x)
{
	if(fa[x]==x)
		return x;
	else
	{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}

struct node
{
	int xi,index;
}x[100005];

bool cmp(const node &a,const node &b)
{
	return a.xi<b.xi;
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int n,k,p;
	cin>>n>>k>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i].xi;
		x[i].index=i;
		fa[i]=i;
	}
	sort(x+1,x+n+1,cmp);
	for(int i=2;i<=n;i++)
		if(x[i].xi-x[i-1].xi<=k)
			fa[x[i].index]=find(x[i-1].index);
	while(p--)
	{
		int a,b;
		cin>>a>>b;
		if(fa[a]==fa[b])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
