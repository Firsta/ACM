/*
ID: firstaw1
PROG: castle
LANG: C++
*/
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
#include<cmath>
#include<sstream>
#include<string>
#define MAXN 55

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int grid[MAXN][MAXN],belong[MAXN][MAXN],cntn[MAXN*MAXN],cnt;
bool vis[MAXN][MAXN];

int m,n;
void dfs(int x,int y){
	vis[x][y]=true;
	belong[x][y]=cnt;
	cntn[cnt]++;
	int t=grid[x][y];
	if(t==0||t==2||t==4||t==8||t==6||t==10||t==12||t==14)
		if(y-1>=0&&!vis[x][y-1])
			dfs(x,y-1);
	if(t==0||t==1||t==4||t==8||t==5||t==9||t==12||t==13)
		if(x-1>=0&&!vis[x-1][y])
			dfs(x-1,y);
	if(t==0||t==1||t==2||t==8||t==3||t==9||t==10||t==11)
		if(y+1<m&&!vis[x][y+1])
			dfs(x,y+1);
	if(t==0||t==1||t==2||t==4||t==3||t==5||t==6||t==7)
		if(x+1<n&&!vis[x+1][y])
			dfs(x+1,y);
	return;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&grid[i][j]);
	cnt=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!vis[i][j]){
				cnt++;
				dfs(i,j);
			}
	int maxi=0;
	for(int i=1;i<=cnt;i++)
		if(cntn[i]>maxi)
			maxi=cntn[i];
	printf("%d\n%d\n",cnt,maxi);
	return 0;
}
