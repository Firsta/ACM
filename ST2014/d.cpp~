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
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int dp[7005][2005],head[7005];
bool inq[7005],mark[7005];
map<string,int> mapp;

struct edge{
	int to,w,next;
}edges[7005];
int em=0;

void addedge(int u,int v,int w){
	edges[em].next=head[u];
	edges[em].to=v;
	edges[em].w=w;
	head[u]=em++;
	edges[em].next=head[v];
	edges[em].to=u;
	edges[em].w=w;
	head[v]=em++;
}

int main(){
	int n,m,cap;
	while(~scanf("%d%d%d",&n,&m,&cap)&&(n||m||cap)){
		int cnt=1;
		em=0;
		cap*=10;
		string s,t,tt,mm;
		mapp.clear();
		cin>>s>>t;
		mapp[s]=cnt++;//s:1
		mapp[t]=cnt++;//t:2
		memset(head,-1,sizeof(head));
		while(n--){
			int w;
			cin>>tt>>mm;
			scanf("%d",&w);
			if(mapp[tt]==0)
				mapp[tt]=cnt++;
			if(mapp[mm]==0)
				mapp[mm]=cnt++;
			addedge(mapp[tt],mapp[mm],w);
		}
		memset(mark,false,sizeof(mark));
		while(m--){
			cin>>tt;
			mark[mapp[tt]]=true;
		}
		queue<int> q;
		memset(inq,false,sizeof(inq));
		for(int i=0;i<=cnt;i++)
			for(int j=0;j<=cap;j++)
				dp[i][j]=INF;
		dp[1][cap]=0;
		q.push(1);
		inq[1]=true;
//		cout<<1<<endl;
		while(!q.empty()){
//			cout<<3<<endl;
			int now=q.front();
			q.pop();
			inq[now]=false;
			if(mark[now])
				for(int i=0;i<cap;i++)
					dp[now][cap]=min(dp[now][i],dp[now][cap]);
			for(int e=head[now];e!=-1;e=edges[e].next){
//				cout<<4<<endl;
				int v=edges[e].to,w=edges[e].w;
				bool flag=false;
				for(int i=cap;i>=0;i--)
					if(i>=w){
						if(dp[v][i-w]>dp[now][i]+w){
//							cout<<5<<endl;
							dp[v][i-w]=dp[now][i]+w;
							flag=true;
						}
					}
				if(flag&&!inq[v]){
//					cout<<6<<endl;
					inq[v]=true;
					q.push(v);
				}
			}
		}
//		cout<<2<<endl;
		int ans=INF;
		for(int i=0;i<=cap;i++)
			ans=min(dp[2][i],ans);
		if(ans==INF)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
