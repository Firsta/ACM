/*
ID: firstaw1
PROG: combo
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n,ans,a[3],t[3],mark[101][101][101];

void dfs(int dep){
	if(dep==-1){
		if(!mark[t[0]][t[1]][t[2]]){
			mark[t[0]][t[1]][t[2]]=1;
			ans++;
		}
	}else{
		for(int i=-2;i<=2;i++){
			t[dep]=(a[dep]+i+n)%n;
			dfs(dep-1);
		}
	}
}

int main(){
	freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
	memset(mark,0,sizeof(mark));
	ans=0;
	scanf("%d",&n);
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	dfs(2);
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	dfs(2);
	printf("%d\n",ans);
	return 0;
}
