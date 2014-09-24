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
#define MAXN 505
#define MAXM 500005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

bool vis[MAXN];
int match[MAXN],head[MAXN];

struct edge{
	int to,next;
}edges[MAXM];
int em;

void addedge(int u,int v){
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
}

struct student{
	int height;
	char sex;
	string music,sport;
}stu[MAXN];

bool find(int u){
	for(int e=head[u];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!vis[v]){
			vis[v]=true;
			if(!match[v]||find(match[v])){
				match[v]=u;
				return true;
			}
		}
	}
	return false;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			cin>>stu[i].height>>stu[i].sex>>stu[i].music>>stu[i].sport;
		fill(head,head+n+1,-1);em=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
					if(abs(stu[i].height-stu[j].height)<=40&&stu[i].sex!=stu[j].sex&&stu[i].music==stu[j].music&&stu[i].sport!=stu[j].sport){
						addedge(i,j);addedge(j,i);
					}
		fill(match,match+n+1,0);
		int ans=0;
		for(int i=1;i<=n;i++){
			fill(vis,vis+n+1,false);
			if(stu[i].sex=='M'&&find(i))
				ans++;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
