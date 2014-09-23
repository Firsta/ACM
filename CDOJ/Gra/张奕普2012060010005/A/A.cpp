#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MAXN 4100
#define MAXM 400100

typedef long long ll;
using namespace std;

int stack[MAXN],head[MAXN],nex[MAXM],to[MAXM];
int dfn[MAXN],low[MAXN],instack[MAXN],ori[MAXN],n,ind,cnt,top;
int ans[MAXN];

void init()
{
	for(int i=1;i<=n;i++)
	{
		dfn[i]=0;dfn[i+2000]=0;
		low[i]=0;low[i+2000]=0;
		instack[i]=0;instack[i+2000]=0;
		ori[i]=0;ori[i+2000]=0;
		head[i]=-1;head[i+2000]=-1;
	}
	ind=cnt=top=0;
	memset(nex,0,sizeof(nex));
}

void tarjan(int i)
{
	dfn[i]=low[i]=++ind;
	instack[i]=true;
	stack[++top]=i;
	for(int e=head[i];e!=-1;e=nex[e])
	{
		int temp=to[e];
		if(!dfn[temp])
		{
			tarjan(temp);
			low[i]=min(low[i],low[temp]);
		}
		else if(instack[temp])
			low[i]=min(low[i],dfn[temp]);
	}
	if(dfn[i]==low[i])
	{
		cnt++;
		int temp;
		do
		{
			temp=stack[top--];
			instack[temp]=false;
			ori[temp]=cnt;
		}
		while(temp!=i);
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		init();
		int em=0;
		for(int i=1;i<=n;i++)
		{
			int k;
			scanf("%d",&k);
			for(int j=0;j<k;j++)
			{
				int temp;
				scanf("%d",&temp);
				to[em]=temp+2000;
				nex[em]=head[i];
				head[i]=em;
				em++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			int temp;
			scanf("%d",&temp);
			to[em]=i;
			nex[em]=head[temp+2000];
			head[temp+2000]=em;
			em++;
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i])
				tarjan(i);
		for(int i=1;i<=n;i++)
		{
			int k=0;
			for(int j=head[i];j!=-1;j=nex[j])
			{
				if(ori[i]==ori[to[j]])
					ans[k++]=to[j]-2000;
			}
			sort(ans,ans+k);
			printf("%d",k);
			for(int j=0;j<k;j++)
				printf(" %d",ans[j]);
			printf("\n");
		}
	}
	return 0;
}
