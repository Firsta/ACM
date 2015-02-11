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

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	while(true)
	{
		int v=-1,tm=INF;
		for(int i=0;i<n;i++)
			if(!vis[i]&&d[i]<=tm)
			{
				v=i;
				tm=d[i];
			}
		if(v==-1)
			break;
		vis[v]=1;
		for(int e=head[v];e!=-1;e=edges[e].next)
		{
			int tmp=edges[e].to;
			d[tmp]=min(d[tmp],d[v]+edges[e].w);
		}
	}
	return 0;
}
