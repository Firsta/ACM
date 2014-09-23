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

void dfs(int s,int k){
	if(k==1){
		if(!vis[s])
			ans++;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			dfs(s-i,k-1);
			vis[i]=0;
		}
}

int main(){
	int n,k,s;
	while(~scanf("%d%d%d",&n,&k,&s)){
		ans=0;
		dfs(s,k);
		printf("%d\n",ans);
	}
	return 0;
}
