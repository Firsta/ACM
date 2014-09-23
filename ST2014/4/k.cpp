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
#define MAXN 300

typedef long long ll;
using namespace std;

struct node{
	int x,y;
};

node Cnt[5][MAXN*MAXN];

int check(char c){
	if(c=='B')
		return 0;
	if(c=='J')
		return 1;
	if(c=='H')
		return 2;
	if(c=='Y')
		return 3;
	if(c=='N')
		return 4;
	return -1;
}

char G[MAXN][MAXN];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			char tmp[MAXN];
			scanf("%s",tmp);
			for(int j=0;j<m;j++){
				G[i][j]=tmp[j];
			}
		}
		ll ans=0;
		for(int i=0;i<5;i++){
			for(int j=0;j<n;j++)
				for(int k=j+1;k<n;k++)
				{
					ll cnt=0;
					for(int l=0;l<m;l++)
						if(check(G[j][l])==i&&check(G[k][l])==i){
								cnt++;
					}
					ans=ans+cnt*(cnt-1)/2;
				}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
