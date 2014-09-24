#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<cstring>
#include<vector>
#define MAXN 50
using namespace std;
bool visited[203][203];
int tx[MAXN+5], ty[MAXN+5], bx[MAXN+5], by[MAXN+5];
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
vector<int> sx, sy;
map<int, int> fx, fy;
bool can(int x, int y) {
	if (x >= 0 && x <= 200 && y >= 0 && y <= 200) {
		return !visited[x][y];
	} else {
		return false;
	}
}
void dfs(int x, int y) {
	int nx, ny;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		nx = x+dx[i];
		ny = y+dy[i];
		if (can(nx, ny)) {
			dfs(nx, ny);
		}
	}
}
int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		if (n == 0) break;
		sx.clear(); sy.clear(); fx.clear(); fy.clear();
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d%d", &tx[i], &ty[i], &bx[i], &by[i]);
			sx.push_back(tx[i]);
			sy.push_back(ty[i]);
			sx.push_back(bx[i]);
			sy.push_back(by[i]);
		}
		sort(sx.begin(), sx.end());
		sx.erase(unique(sx.begin(), sx.end()), sx.end());
		sort(sy.begin(), sy.end());
		sy.erase(unique(sy.begin(), sy.end()), sy.end());
		int size = sx.size();
		for (int i = 0; i < size; i++) {
			fx[sx[i]] = i*2+1;
		}
		size = sy.size();
		for (int i = 0; i < size; i++) {
			fy[sy[i]] = i*2+1;
		}
		for (int i = 0; i < n; i++) {
			tx[i] = fx[tx[i]];
			ty[i] = fy[ty[i]];
			bx[i] = fx[bx[i]];
			by[i] = fy[by[i]];
		}
		for (int i = 0; i < n; i++) {
			for (int j = tx[i]; j <= bx[i]; j++) {
				visited[j][ty[i]] = true;
				visited[j][by[i]] = true;
			}
			for (int j = ty[i]; j >= by[i]; j--) {
				visited[tx[i]][j] = true;
				visited[bx[i]][j] = true;
			}
		}
		int ans = 0;
		for (int i = 0; i < 200; i++) {
			for (int j = 0; j < 200; j++) {
				if (can(i, j)) {
					ans++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", ans);
	}


}
