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

int n,m,k,nx,ny;

int vis[305][305];

void dfs(int x,int y,int cnt)
{
	if(cnt==0)
	{
		nx=x;
		ny=y;
		return;
	}
	else
		cout<<' '<<x<<' '<<y;
	vis[x][y]=1;
	if(y+1<=m&&!vis[x][y+1])
		dfs(x,y+1,cnt-1);
	else if(y-1>=1&&!vis[x][y-1])
		dfs(x,y-1,cnt-1);
	else if(x+1<=n&&!vis[x+1][y])
		dfs(x+1,y,cnt-1);
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	cin>>n>>m>>k;
	int cnt=n*m/k;
	nx=1;ny=1;
	for(int i=0;i<k-1;i++)
	{
		cout<<cnt;
		dfs(nx,ny,cnt);
		cout<<endl;
	}
	cout<<cnt+(n*m)%k;
	dfs(nx,ny,cnt+(n*m)%k);
	return 0;
}
