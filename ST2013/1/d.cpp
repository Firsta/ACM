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

int maze[505][505];
int t[505],s[505];

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		memset(maze,0,sizeof(maze));
		int cnte=0;
		for(int i=0;i<m;i++)
			cin>>s[i];
		for(int i=0;i<m;i++)
			cin>>t[i];
		for(int i=0;i<m;i++)
		{
			if(maze[s[i]][t[i]]==0)
			{
				maze[s[i]][t[i]]=maze[t[i]][s[i]]=1;
				cnte++;
			}
		}
		double ans;
		ans=cnte*1.0/n;
		printf("%.3lf\n",ans);
	}
	return 0;
}
