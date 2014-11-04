#include<cstdio>
using namespace std;
typedef long long ll;
const long long mod = 1000000000LL;
struct BigInt {
	long long num[4];

	BigInt() {
		num[3] = num[2] = num[1] = num[0] = 0;
	}
	BigInt(ll v) {
		num[3] = num[2] = num[1] = 0;
		num[0] = v%mod;
		v /= mod;
		if (!v) return;
		num[1] = v%mod;
		v /= mod;
		if (!v) return;
		num[2] = v%mod;
	}
	BigInt operator *(const BigInt &b) const {
		BigInt tmp;
		tmp.num[0] = num[0]*b.num[0];
		tmp.num[1] = num[1]*b.num[0];
		tmp.num[1] += num[0]*b.num[1];
		tmp.num[2] = num[1]*b.num[1];
		tmp.num[1] += tmp.num[0]/mod;
		tmp.num[0] %= mod;
		tmp.num[2] += tmp.num[1]/mod;
		tmp.num[1] %= mod;
		return tmp;
	}
    BigInt operator *(const ll &b) const {
		BigInt tmp;
		tmp.num[0] = num[0]*b;
		tmp.num[1] = num[1]*b;
		tmp.num[2] = num[2]*b;

		tmp.num[1] += tmp.num[0]/mod;
		tmp.num[0] %= mod;
		tmp.num[2] += tmp.num[1]/mod;
		tmp.num[1] %= mod;
		return tmp;
	}
	BigInt operator +(const BigInt &b) const {
		BigInt tmp;
		tmp.num[0] = num[0]+b.num[0];
		tmp.num[1] = num[1]+b.num[1];
		tmp.num[2] = num[2]+b.num[2];

		tmp.num[1] += tmp.num[0]/mod;
		tmp.num[0] %= mod;
		tmp.num[2] += tmp.num[1]/mod;
		tmp.num[1] %= mod;
		return tmp;
	}
	BigInt operator -(const BigInt &b) const {
		BigInt tmp = (*this);
		if (tmp.num[0] < b.num[0]) {
			tmp.num[0] = tmp.num[0]+mod-b.num[0];
			tmp.num[1]--;
		} else {
			tmp.num[0] -= b.num[0];
		}
		if (tmp.num[1] < b.num[1]) {
			tmp.num[1] = tmp.num[1]+mod-b.num[1];
			tmp.num[2]--;
		} else {
			tmp.num[1] -= b.num[1];
		}
		tmp.num[2] -= b.num[2];
		return tmp;
	}
	void output() {
		if (num[2] > 0) {
			printf("%I64d", num[2]);
			printf("%09I64d", num[1]);
			printf("%09I64d", num[0]);
			return ;
		}
		if (num[1] > 0) {
			printf("%I64d", num[1]);
			printf("%09I64d", num[0]);
			return ;
		}
		printf("%I64d", num[0]);
	}
};
int main() {
	BigInt eight = BigInt(8), seven = BigInt(7), one = BigInt(1) ,N, ans;
	int T;
	ll n;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%I64d", &n);
		N = BigInt(n);
		ans = N*N*(8LL)-N*(7LL)+one;
		printf("Case #%d: ", t); ans.output(); puts("");
	}
	return 0;

}

