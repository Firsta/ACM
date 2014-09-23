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
using namespace std;

int ans1,ans2;
int dp[105][105][105];

int main(){
	dp[0][0][0]=1;
	for(int i=1;i<=100;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<=j;k++){
				for(int l=1;l<=i;l++){
					if(dp[l-1][min(l-1,j)][min(k,min(l-1,j))]==0){
						dp[i][j][k]=1;
						break;
					}
					if(l<=j){
						if(dp[i][l-1][min(l-1,k)]==0){
							dp[i][j][k]=1;
							break;
						}
					}
					if(l<=k){
						if(dp[i][j][l-1]==0){
							dp[i][j][k]=1;
							break;
						}
					}
				}
			}
	int t;
	scanf("%d",&t);
	while(t--){
		int k,p,q,r;
		scanf("%d%d%d%d",&k,&p,&q,&r);
		printf("%d ",k);
		if(dp[p][q][r]==0){
			printf("L\n");
			continue;
		}
		printf("W");
		for(int i=1;i<=p;i++){
			if(dp[i-1][min(i-1,q)][min(i-1,r)]==0){
				printf(" %d 1\n",i);
				break;
			}
			if(i<=q){
				if(dp[p][i-1][min(i-1,r)]==0){
					printf(" %d 2\n",i);
					break;
				}
			}
			if(i<=r){
				if(dp[p][q][i-1]==0){
					printf(" %d 3\n",i);
					break;
				}
			}
		}
	}
	return 0;
}
