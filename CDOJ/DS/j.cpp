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
#define MAXN 10000100

typedef long long ll;
using namespace std;

struct Trie
{
	int ch[MAXN][2];
	int val[MAXN];
	int sz;

	Trie()
	{
		sz=1;
		memset(ch[0],0,sizeof(ch[0]));
	}

	int idx(char c)
	{
		return c-'0';
	}

	void insert(string s)
	{
		int u=0,n=s.size();
		for(int i=0;i<n;i++)
		{
			int c=idx(s[i]);
			if(!ch[u][c])
			{
				memset(ch[sz],0,sizeof(ch[sz]));
				ch[u][c]=sz;
				sz++;
			}
			u=ch[u][c];
			val[u]+=i+1;
		}
	}
}tree;

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		string s;
		cin>>s;
		tree.insert(s);
	}
	int max=0;
	for(int i=0;i<tree.sz;i++)
		if(tree.val[i]>max)
			max=tree.val[i];
	printf("%d\n",max);
	return 0;
}
