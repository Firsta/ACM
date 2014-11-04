#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXS 1024
#define MAXN 10
#define MAXM 1000
using namespace std;
bool vis[MAXN+3][MAXS+5];
double dp[MAXN+3][MAXS+5], p[MAXN+3][MAXM+3];
inline double max(double a, double b) {
	return a > b ? a : b;
}
int n;
double dfs(int now, int s, int begin, int end) {
	int pron = end-begin;
	if (now > pron) return 0;
	if (vis[now][s]) return dp[now][s];
	//int n = end-begin;
	double ans = 0;
	for (int i = 0; i < n; i++) {
		if (!((s >> i)&1)) {
			ans = max(ans, p[i+1][now+begin-1]+dfs(now+1, (s|(1 << i)), begin, end));
		}
	}
	vis[now][s] = true;
	return dp[now][s] = ans;
}
int main() {
	int T, m, group, begin, end;
	double ans;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%lf", &p[i][j]);
			}
		}
		group = m/n;
		ans = 0;
		for (int i = 0; i < group; i++) {
			begin = 1+i*n;
			end = n+begin;
			memset(dp, 0, sizeof(dp));
			memset(vis, false, sizeof(vis));
			ans += dfs(1, 0, begin, end);
		}
		memset(dp, 0, sizeof(dp));
		memset(vis, false, sizeof(vis));
		begin = group*n+1;
		ans += dfs(1, 0, begin, m+1);
		printf("Case #%d: %.5f\n", t, ans);
	}
	return 0;
}

