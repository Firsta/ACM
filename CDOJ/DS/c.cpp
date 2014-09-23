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

#define MAXN 400010

typedef long long ll;
using namespace std;

typedef struct Tree
{
	int left,right;
}Tree;

Tree tree[MAXN];
int sumv[MAXN],addv[MAXN];
int a[100005];

void maintain(int id)
{
	int lc=id*2;int rc=id*2+1;
	sumv[id]=0;
	if(tree[id].right>tree[id].left)
	{
		sumv[id]=sumv[lc]+sumv[rc];
	}
	sumv[id]+=addv[id]*(tree[id].right-tree[id].left+1);
}

void build(int id,int l,int r)
{
	tree[id].left=l;
	tree[id].right=r;
	if(l==r)
		sumv[id]=a[l];
	else
	{
		int mid=(l+r)/2;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		sumv[id]=sumv[id*2]+sumv[id*2+1];
	}
}

void update(int id,int l,int r,int w)
{
	if(l<=tree[id].left&&r>=tree[id].right)
	{
		addv[id]+=w;
	}
	else
	{
		int mid=(tree[id].left+tree[id].right)/2;
		if(l<=mid)
			update(id*2,l,r,w);
		if(r>mid)
			update(id*2+1,l,r,w);
	}
	maintain(id);
}

int ans=0;
void query(int id,int l,int r,int add)
{
	if(l<=tree[id].left&&r>=tree[id].right)
	{
		ans+=sumv[id]+add*(tree[id].right-tree[id].left+1);
	}
	else
	{
		int mid=(tree[id].left+tree[id].right)/2;
		if(l<=mid)
			query(id*2,l,r,add+addv[id]);
		if(r>mid)
			query(id*2+1,l,r,add+addv[id]);
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	while(m--)
	{
		int s;
		scanf("%d",&s);
		if(!s)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			ans=0;
			query(1,l,r,0);
			printf("%d\n",ans);
		}
		else
		{
			int l,r,w;
			scanf("%d%d%d",&l,&r,&w);
			update(1,l,r,w);
		}
	}
	return 0;
}
