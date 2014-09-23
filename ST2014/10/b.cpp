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
#define MAXN 1000005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

double dp[MAXN];
int isprime[MAXN];

double dfs(int n){
	if(dp[n]>=0)
		return dp[n];
	double cnt=0;
	for(int i=2;i<=n;i++)
		if(isprime[i])
			cnt+=1;
	double l=cnt,rsum=cnt;
	for(int i=2;i<=n;i++)
		if(isprime[i]){
			if(n%i!=0){
				l=(l-1);
			}else{
				rsum+=dfs(n/i);
			}
		}
//	if(n==13)
//		cout<<cnt<<' '<<l<<' '<<rsum<<' '<<cnta<<' '<<cntb<<endl;
	dp[n]=rsum/l;
	return dp[n];
}

int main(){
	for(int i=0;i<MAXN;i++)
		isprime[i]=true;
	isprime[0]=isprime[1]=false;
	for(int i=2;i<MAXN;i++){
		if(isprime[i]){
			for(int j=2*i;j<MAXN;j+=i)
				isprime[j]=0;
		}
	}
	for(int i=0;i<MAXN;i++)
		dp[i]=-1.0;
	dp[1]=0.0;
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		int n;
		scanf("%d",&n);
		double ans=dfs(n);
		printf("Case %d: %.10f\n",cas,ans);
	}
	return 0;
}
