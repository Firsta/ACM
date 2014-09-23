#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
char A[maxn],B[maxn];
int cnt[10];
bool use[maxn];
vector <int> pos[10];
int now[10];

int main()
{
    while (true);
    //freopen("e.in","r",stdin);
    int T;
    //scanf("%d",&T);
    cin >> T;
    while(T--)
    {
        //scanf("%s%s",A,B);
        cin >> A >> B;
        int lena=strlen(A),lenb=strlen(B);
        if(lena!=lenb)
        {
            puts(lena<lenb?"0":"Poor LoveZx");
            continue;
        }
        for(int i=0;i<10;++i) pos[i].clear();
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<lenb;++i)
        {
            pos[B[i]-'0'].push_back(i);
            cnt[B[i]-'0']++;
        }
        memset(use,0,sizeof(use));
        int tmp=0,ans=INF,cur=0,maxd;
        for(int i=0;i<10;++i) now[i]=pos[i].size()-1;
        for(int i=9;i>=0;--i) if(pos[i].size()) {maxd=i;break;}
        bool poor=1;
        for(int i=0;i<lena;++i)
        {
            while(use[cur]) cur++;
            while(!cnt[maxd]) maxd--;
            if(A[i]>B[cur])
            {
                if(maxd>A[i]-'0')
                {
                    ans=min(ans,tmp+1);
                    poor=0;
                    break;
                }
                else if(maxd<A[i]-'0') break;
                tmp++;
                use[pos[maxd][now[maxd]]]=1;
                now[maxd]--;
                cnt[maxd]--;
            }
            else if(A[i]==B[cur])
            {
                if(maxd>A[i]-'0')
                {
                    ans=min(ans,tmp+1);
                    poor=0;
                }
                cnt[B[cur]-'0']--;
                cur++;
            }
            else
            {
                ans=min(ans,tmp);
                poor=0;
                break;
            }
        }
        if(poor) puts("Poor LoveZx");
        else printf("%d\n",ans);
    }
    return 0;
}
