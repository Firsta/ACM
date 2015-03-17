#include    <iostream>
#include    <stdio.h>

using namespace std;

int dp[8][10];

void init()
{
    dp[0][0] = 1;
    for (int i = 1; i <= 7; i++) {
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (j != 4 && !(j == 6 && k == 2))
                    dp[i][j] += dp[i - 1][k];
    }
}

int dig[10];
int handle(int x)
{
    int cnt = 0;
    while (x) {
        dig[cnt++] = x % 10;
        x /= 10;
    }
    dig[cnt] = 0;
    int ans = 0;
    for (int i = cnt - 1; i >= 0; i--) {
        for (int j = 0; j < dig[i]; j++)
            if (j != 4 && !(j == 2 && dig[i + 1] == 6))
                ans = ans + dp[i + 1][j];
        if (dig[i] == 4 || (dig[i] == 2 && dig[i + 1] == 6))
            break;
    }
    return ans;
}

int main()
{
    int n, m;
    init();
    while ((scanf("%d%d", &n, &m) != EOF) && (n || m)) {
        printf("%d\n", handle(m + 1) - handle(n));
    }
}
