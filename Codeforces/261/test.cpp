#include<bits/stdc++.h>
#define MAXN 1000000
using namespace std;
map<int, int> mp1, mp2;
int a[MAXN+5], r[MAXN+5], l[MAXN+5], tree[MAXN+5];
int lowbit(int t) {
    return t&(t^(t-1));
}
void modify(int pos, int num) {
    while (pos <= MAXN) {
        tree[pos] += num;
        pos += lowbit(pos);
    }
}
int get(int end) {
    int ans = 0;
    while (end > 0) {
        ans += tree[end];
        end -= lowbit(end);
    }
    return ans;
}
int main() {
    int n, ans = 0;
    memset(tree,0,sizeof(tree));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        l[i] = ++mp1[a[i]];
    }
    for (int i = n; i > 0; i--) {
        r[i] = ++mp2[a[i]];
    }
    for (int i = n; i > 0; i--) {
        ans += get(l[i]-1);
        modify(r[i], 1);
    }
    cout << ans << endl;
    return 0;
}
