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

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

char maze[25][25];
char str[25];

int dx[4]={
	0,0,-1,1
};
int dy[4]={
	1,-1,0,0
};

int ans,n,m,sx,sy;

void dfs(int x,int y){
	ans++;
	maze[x][y]='#';
	for(int i=0;i<4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx>=0&&tx<n&&ty>=0&&ty<m&&maze[tx][ty]=='.')
			dfs(tx,ty);
	}
}

int main(){
	while(scanf("%d%d",&m,&n)!=EOF&&(n||m)){
		for(int i=0;i<n;i++){
			scanf("%s",str);
			for(int j=0;j<m;j++){
				maze[i][j]=str[j];
				if(maze[i][j]=='@'){
					sx=i;sy=j;
				}
			}
		}
		ans=0;
		dfs(sx,sy);
		printf("%d\n",ans);
	}
	return 0;
}
