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

ll dp[2][1024][1024];
ll temp[1024][1024];

int main(){
	int m,n;
	while(~scanf("%d%d",&n,&m)){
		if(n<3||m<3){
			printf("0\n");
			continue;
		}
		if(m>n){
			int tmp=m;
			m=n;
			n=tmp;
		}
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1;
		for(int i=n-1;i>=0;i--)
			for(int j=m-1;j>=0;j--){
				for(int h1=0;h1<(1<<m);h1++)
					for(int h2=0;h2<(1<<m);h2++){
						if(h1&(1<<j))
							dp[1][h1][h2]=dp[0][h1&(~(1<<j))][h2&(~(1<<j))];
						else{
							ll res=0;
							if(j+2<m&&(!(h1&(1<<(j+1))))&&(!(h1&(1<<(j+2)))))
								res+=dp[0][(h1|(1<<(j+1)))|(1<<(j+2))][h2];
							if(i+2<n&&(!(h2&(1<<j))))
								res+=dp[0][h1|(1<<j)][h2&(~(1<<j))];
							dp[1][h1][h2]=res;
						}
					}
				for(int i=0;i<(1<<m);i++)
					for(int j=0;j<(1<<m);j++)
						temp[i][j]=dp[0][i][j];
				for(int i=0;i<(1<<m);i++)
					for(int j=0;j<(1<<m);j++)
						dp[0][i][j]=dp[1][i][j];
				for(int i=0;i<(1<<m);i++)
					for(int j=0;j<(1<<m);j++)
						dp[1][i][j]=temp[i][j];
			}
		printf("%lld\n",dp[0][0][0]);
	}
	return 0;
}
