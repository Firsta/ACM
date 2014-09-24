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
#define MAXN 1010

typedef long long ll;
using namespace std;

int head[26],in[26],out[26],fa[26],vis[MAXN],ans[MAXN],cnt;

struct word
{
	int from,to;
	string s;
}words[MAXN];

bool cmp(const word &a,const word &b)
{
	return a.s>b.s;
}

struct edge
{
	int ind,next,to;
}edges[MAXN];

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

int jud()
{
	for(int i=0;i<26;i++)
		for(int j=i+1;j<26;j++)
			if(vis[i]&&vis[j]&&find(i)!=find(j))
			{
//				cout<<'a'<<endl;
				return -1;
			}
	int st=-1,end=-1,all=0;
	for(int i=0;i<26;i++)
		if(vis[i])
		{
			if(in[i]!=out[i])
			{
				if(in[i]==out[i]+1)
				{
					if(end=-1)
						end=i;
					else
						return -1;
				}
				else if(in[i]+1==out[i])
				{
					if(st==-1)
						st=i;
					else
						return -1;
				}
				else
					return -1;
			}
		}
	if(st==-1&&end==-1)
	{
		for(int i=0;i<26;i++)
			if(vis[i])
				return i;
	}
	else if(st!=-1&&end!=-1)
		return st;
	else
		return -1;
}

void dfs(int u,int ei)
{
	for(int e=head[u];e!=-1;e=edges[e].next)
	{
		if(!vis[e])
		{
			vis[e]=1;
			dfs(edges[e].to,e);
		}
	}
	if(ei!=-1)
		ans[cnt++]=edges[ei].ind;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		memset(head,-1,sizeof(head));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		for(int i=0;i<26;i++)
			fa[i]=i;
//		cout<<-1<<endl;
		for(int i=0;i<n;i++)
		{
			cin>>words[i].s;
			words[i].from=words[i].s[0]-'a';
			words[i].to=words[i].s[words[i].s.size()-1]-'a';
			out[words[i].from]++;
			in[words[i].to]++;
			vis[words[i].from]=vis[words[i].to]=1;
			int x=find(words[i].from),y=find(words[i].to);
//			cout<<x<<' '<<y<<endl;
			if(x!=y)
				fa[x]=y;
		}
/*		for(int i=0;i<26;i++)
			cout<<' '<<fa[i];
		cout<<endl;
		for(int i=0;i<26;i++)
		{
			find(i);
			cout<<i<<' '<<fa[i];
			cout<<endl;
		}
		for(int i=0;i<26;i++)
			cout<<' '<<vis[i];
		cout<<endl;*/
		sort(words,words+n,cmp);
		for(int i=0;i<n;i++)
		{
			int temp=head[words[i].from];
			edges[i].next=temp;
			edges[i].ind=i;
			edges[i].to=words[i].to;
			head[words[i].from]=i;
		}
		int t=jud();
		cnt=0;
		if(t==-1)
		{
			printf("***\n");
			continue;
		}
		else
		{
			memset(vis,0,sizeof(vis));
			dfs(t,-1);
		}
		cout<<words[ans[cnt-1]].s;
		for(int i=cnt-2;i>=0;i--)
		{
			cout<<'.'<<words[ans[i]].s;
		}
		cout<<endl;
	}
	return 0;
}
