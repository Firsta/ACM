#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<fstream>
#include<sstream>
#include<string>

typedef long long ll;
using namespace std;
//有向图
void tarjan(int x)
{
	low[x]=dfn[x]=++ind;
	ins[x]=1;
	st.push(x);
	for(int e=head[x];e!=-1;e=edges[e].next)
	{
		int v=edges[e].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(ins[v])
			low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x])
	{
		int tmp;
		cnt++;
		do
		{
			tmp=st.top();
			st.pop();
			belong[tmp]=cnt;
			ins[tmp]=0;
		}while(tmp!=x);
	}
}
//无向图
void tarjan(int u)
{
	low[u]=dfn[u]=++ind;
	for(int e=head[u];e!=-1;e=edges[e].next)
	{
		int v=edges[e].to;
		if(!dfn[v])
		{
			tarjan(v);
		}
		low[u]=min(low[u],low[v])
	}
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	return 0;
}
