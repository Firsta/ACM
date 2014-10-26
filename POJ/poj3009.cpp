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

int n,m,ex,ey,sx,sy,ans;
int maze[25][25];
int dx[4]={
	0,0,-1,1
};
int dy[4]={
	1,-1,0,0
};

void dfs(int x,int y,int d,bool stop,int f){
	if(f>10)
		return;
	else if(stop==true){
		for(int i=0;i<4;i++){
			int tx=x+dx[i],ty=y+dy[i];
			if(tx<0||tx>=n||ty<0||ty>=m)
				continue;
			else if(maze[tx][ty]==1)
				continue;
			else if(tx==ex&&ty==ey)
				ans=min(ans,f+1);
			else if(maze[tx][ty]==0)
				dfs(tx,ty,i,false,f+1);
		}
	}else{
		int tx=x+dx[d],ty=y+dy[d];
		if(tx<0||tx>=n||ty<0||ty>=m)
			return;
		else if(tx==ex&&ty==ey)
			ans=min(ans,f);
		else if(maze[tx][ty]==0)
			dfs(tx,ty,d,false,f);
		else if(maze[tx][ty]==1){
			maze[tx][ty]=0;
			dfs(x,y,d,true,f);
			maze[tx][ty]=1;
		}
	}
}

int main(){
	while(scanf("%d%d",&m,&n)!=EOF&&(n||m)){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				scanf("%d",&maze[i][j]);
				if(maze[i][j]==2){
					sx=i;sy=j;
					maze[i][j]=0;
				}else if(maze[i][j]==3){
					ex=i;ey=j;
					maze[i][j]=0;
				}
			}
		ans=INT_MAX;
		dfs(sx,sy,0,true,0);
		if(ans==INT_MAX)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
