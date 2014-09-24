/*
ID: firstaw1
PROG: sprime
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

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

bool isprime(int x){
	if(x==1)
		return false;
	bool flag=true;
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			flag=false;
			break;
		}
	return flag;
}

vector<int> ans;

void dfs(int now,int step){
	if(step==0){
		if(isprime(now))
			ans.push_back(now);
		return;
	}
	if(now==0){
		for(int i=1;i<=9;i++)
			if(isprime(i))
				dfs(i,step-1);
	}else{
		for(int i=0;i<=9;i++)
			if(isprime(now*10+i))
				dfs(now*10+i,step-1);
	}
}

int main(){
	freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
	int n;
	scanf("%d",&n);
	dfs(0,n);
	if(ans.size()==0)
		return 0;
	else{
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
