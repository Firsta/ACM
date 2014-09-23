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
#define MAXN 300005
#define MAXM 300005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int dp[MAXM],dpt[MAXN];

struct edge{
	int to,from,w;
}edges[MAXM];

bool cmp(const edge &a,const edge &b){
	return a.w<b.w;
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>edges[i].from>>edges[i].to>>edges[i].w;
	sort(edges,edges+m,cmp);
	memset(dp,0,sizeof(dp));
	memset(dpt,0,sizeof(dpt));
	vector<edge> a;
	for(int i=0;i<m;i++){
		int w=edges[i].w;
		a.clear();
		while(edges[i].w==w&&i<m){
			a.push_back(edges[i]);
			i++;
		}
		i--;
		for(int j=0;j<a.size();j++){
			dpt[a[j].to]=max(dpt[a[j].to],dp[a[j].from]+1);
		}
		for(int j=0;j<a.size();j++){
			dp[a[j].to]=dpt[a[j].to];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
