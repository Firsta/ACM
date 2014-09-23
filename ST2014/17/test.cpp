#include<bits/stdc++.h>
using namespace std;

bool legal(long long num, int base) {
    //cout << "***" << num << "&&" << base << endl;
     long long a;
	while (num > 0) {
		a = num%base;
		if (a != 3 && a != 4 && a != 5 && a != 6) {
			return false;
		}
		num /= base;
	}
	return true;
}
int b[] = {3, 4, 5, 6};
long long abs(long long n) {
	return n >= 0 ? n : -n;
}
void dfs(long long n) {
}
int main() {
	int T; long long n;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		//scanf("%lld", &n);
		n = i;
		long long ans = 0;
		if (n < 3) {
			ans = 0;
		}
		if (n >= 3 && n < 7) {
			ans = -1;
		}
		if (n >= 7) {
			for (long long j = n-1; j >= 4; j--) {
				if (legal(n, j)) {
					ans++;
					cout << j << ' ';
				}
			}
			cout << endl;
		}
		printf("Case #%d: %lld\n", i, ans);
	}
	return 0;
}
