#include <cstring>
#include <iostream>
using namespace std;

char s[100010];

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int x, y, t;
        scanf("%d%d%d", &x, &y, &t);
        scanf("%s",s);
        int anst = -1;
        for (int i = 0; i <= t; i++) {
            if (!x && !y) {
                anst = i;
                break;
            }
            if (i == t) break;
            switch (s[i]) {
                case 'L': if (x < 0) x++; break;
                case 'R': if (x > 0) x--; break;
                case 'U': if (y > 0) y--; break;
                case 'D': if (y < 0) y++; break;
            }
        }
        printf("%d\n", anst);
    }
    return 0;
}
