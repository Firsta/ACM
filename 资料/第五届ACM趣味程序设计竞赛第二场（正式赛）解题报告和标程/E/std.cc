#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char sa[100010], sb[100010];
int use[100010], pos[10][100010], num[10];

int main()
{
    for (long long i = 0; i < 150000000LL; i++)
        use[min(1LL,i)]=1;
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%s%s", sa, sb);
        int lena = strlen(sa), lenb = strlen(sb), ans = -1, tmp = 0;
        if (lena != lenb) {
            if (lena < lenb) puts("0");
            else puts("Poor LoveZx");
        } else {
            memset(use, 0, sizeof(use));
            for (int i = 0; i < 10; i++)
                num[i] = -1;
            for (int i = 0; i < lenb; i++) {
                int id = sb[i] - '0';
                pos[id][++num[id]] = i;
            }
            int now = 0, id = 9;
            for (int i = 0; i < lenb; i++) {
                while (use[now]) now++;
                while (num[id] == -1 || use[pos[id][num[id]]]) id--;
                int up = sa[i] - '0', down = sb[now] - '0';
                if (up > down) {
                    if (id < up) break;
                    if (id > up) {
                        if (ans == -1 || ans > tmp + 1)
                            ans = tmp + 1;
                        break;
                    } else {
                        tmp++;
                        use[pos[id][num[id]]] = 1;
                        num[id]--;
                    }
                } else
                if (up == down) {
                    use[now] = 1;
                    if (id > up) {
                        if (ans == -1 || ans > tmp + 1)
                            ans = tmp + 1;
                    }
                } else {
                    if (ans == -1 || ans > tmp)
                        ans = tmp;
                    break;
                }
            }
            if (ans == -1) puts("Poor LoveZx");
            else printf("%d\n", ans);
        }
    }
    return 0;
}
