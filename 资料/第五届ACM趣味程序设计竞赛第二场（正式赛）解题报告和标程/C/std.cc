#include <cstdio>

int ans[110];

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n, f, sum = 0;
        scanf("%d%d", &n, &f);
        for (int i = 0; i < n - 1; i++) {
            ans[i] = i + 1;
            sum += ans[i] * (2*n - i*2 -1);
        }
        ans[n - 1] = f - sum;
        bool sol = true;
        if (n > 1 && ans[n - 1] <= ans[n - 2]) sol=false;
        if (sol) {
            for (int i = 0; i < n; i++) {
                if (i) printf(" ");
                printf("%d", ans[i]);
            }
            puts("");
        } else {
            puts("-1");
        }
    }
    return 0;
}
