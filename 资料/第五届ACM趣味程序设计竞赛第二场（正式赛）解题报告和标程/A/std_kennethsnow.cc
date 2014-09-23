#include <cstdio>

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n, m;
        scanf("%d%d", &n, &m);
        if ((n % 2) == 1 || (m % 2) == 1)
            puts("UDK");
        else
            puts("RU");
    }
    return 0;
}
