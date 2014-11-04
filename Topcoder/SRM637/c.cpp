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

int belong[MAXN][MAXN],cn[MAXN*MAXN],con[MAXN*MAXN][MAXN*MAXN],head[MAXN*MAXN],dx[4]={
	0,0,1,-1
},dy[4]={
	-1,1,0,0
};
bool mleft[MAXN*MAXN],mright[MAXN*MAXN],vis[MAXN*MAXN],vv[MAXN][MAXN];
int cnt,n,m,ans;
char cor;

vector<string> tb;

struct edge{
	int to,next;
}edges[2*MAXN*MAXN*MAXN*MAXN];
int em;

void addedge(int u,int v){
	cout<<u<<' '<<v<<"hh"<<endl;
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
	edges[em].next=head[v];
	edges[em].to=u;
	head[v]=em++;
}

void dfs(int x,int y){
	if(y==0)
		mleft[cnt]=true;
	if(y==m-1)
		mright[cnt]=true;
	cn[cnt]++;
	belong[x][y]=cnt;
	for(int i=0;i<4;i++){
		int tx=x+dx[i],ty=y+dy[i];
	cout<<'k'<<endl;
		if(tx>=0&&tx<n&&ty>=0&&ty<m&&tb[tx][ty]==cor&&!belong[tx][ty])
			dfs(tx,ty);
	}
}

void dfs2(int x,int y){
	vv[x][y]=true;
	cout<<x<<' '<<y<<endl;
	for(int i=0;i<4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx<0||tx>=n||ty<0||ty>=m)
			continue;
		else if(tb[tx][ty]==tb[x][y]&&!vv[tx][ty])
			dfs2(tx,ty);
		else if(tb[tx][ty]!=tb[x][y]&&!con[belong[x][y]][belong[tx][ty]]){
			addedge(belong[x][y],belong[tx][ty]);
			con[belong[x][y]][belong[tx][ty]]=con[belong[tx][ty]][belong[x][y]]=1;
		}
	}
}

struct node{
	int num,step;
	node(int num=0,int step=0):num(num),step(step){
		//
	}
};
void bfs(int x){
	memset(vis,false,sizeof(vis));
	queue<node> q;
	q.push(node(x,cn[x]));
	vis[x]=true;
	while(!q.empty()){
		node now=q.front();q.pop();
		cout<<now.step<<endl;
		int nx=now.num;
		if(mright[nx]){
			ans=min(ans,now.step);
			cout<<now.step<<';'<<endl;
		}
		for(int e=head[nx];e!=-1;e=edges[e].next){
			int to=edges[e].to;
			if(!vis[to]){
				q.push(node(to,now.step+cn[to]));
				vis[to]=true;
			}
		}
	}
}

int main(){
//		int getmin(vector <string> board){
	vector<string> board;
	cin>>n;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		board.push_back(str);
	}
	tb=board;
	n=board.size(),m=board[0].size();
	memset(head,-1,sizeof(head));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!belong[i][j]){
				cnt++;
				cor=board[i][j];
				dfs(i,j);
			}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!vis[belong[i][j]]){
				dfs2(i,j);
				vis[belong[i][j]]=true;
			}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<belong[i][j]<<' ';
		cout<<endl;
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<mleft[i]<<'?';
	cout<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<mright[i]<<'?';
	cout<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<head[i]<<'l';
	ans=INT_MAX;
	for(int i=1;i<=cnt;i++)
		if(mleft[i]){
			bfs(i);
		}
	cout<<ans<<':'<<endl;
	return 0;
	//		}
}
