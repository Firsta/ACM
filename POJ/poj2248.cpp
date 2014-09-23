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

int n;
bool vis[105];

bool dfs(int now,int step){
	if(step==0)
		return false;
	vis[now]=true;
	if(now==n)
		return true;
	if(now>n)
		return false;
	for(int i=1;i<=now;i++)
		if(vis[i]&&!vis[i+now])
			if(dfs(i+now,step-1))
				return true;
	vis[now]=false;
	return false;
}

int main(){
	while(~scanf("%d",&n)&&n){
		memset(vis,false,sizeof(vis));
		for(int i=1;;i++)
			if(dfs(1,i)){
				for(int i=1;i<=n;i++)
					if(vis[i])
						printf("%d ",i);
				break;
			}
		puts("");
	}
	return 0;
}
