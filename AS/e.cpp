#include<cstdio>
#include<vector>
#include<iostream>
#define MAXN 50
#define MAXD 10000
using namespace std;

double dp[MAXN][MAXD],cnt[MAXN][MAXD][MAXN],sum[MAXN];
vector<int> edge[MAXN+5];

int main() {
	int T, n, m, d, u, v, num, size, a, b;
	double base, ptmp;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &d);
		for (int i = 1; i <= n; i++)
			edge[i].clear();
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= d; j++)
					dp[i][j] = 0.0;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=d;j++)
				for(int k=0;k<=n;k++)
					cnt[i][j][k]=0;
		for(int i=0;i<=n;i++)
			cnt[i][0][i]=1;
		for(int i=0;i<=n;i++)
			sum[i][0]=1;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		base = (double)((double)1.0/((double)n));
		for (int i = 1; i <= n; i++)
			dp[i][0] = base;
		for (int j = 1; j <= d; j++) {
			for (int u = 1; u <= n; u++) {
				for (int k = 0; k <edges[u].size(); k++) {
					v = edge[u][k];
					num = edge[v].size();
					int tsum=sum[v][j-1];
					int in=cnt[v][j-1][u];
					if(dp[v][j-1]!=0){
						sum[u][j]+=tsum;
						for(int s=0;s<=n;s++)
							cnt[u][j][s]+=cnt[v][j-1][s];
						dp[u][j]+=(1.0*(tsum-in)/(1.0*tsum))*dp[v][j-1]/(1.0*num);
					}
				}
				cnt[u][j][u]++;
			}
		}
		double ans;
		for (int i = 1; i <= n; i++) {
			ans = 0.0;
			for (int j = 0; j <= d; j++) {
				ans += dp[i][j];
			}
			printf("%f\n", 1.0-ans);
		}
		/*for (int i = 1; i <= n; i++) {
			printf("%f\n", 1.0-dp[i][d]);
		}*/
	}
	return 0;
}
