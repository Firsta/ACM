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
#include <bitset>
#define INF 1000000005
#define eps 1e-6
#define PI acos(-1.0)
#define K (0.017453292519943295769236907684886l)

using namespace std;

string word[100005];

int Cpy(string s1,string s2)
{
    int i,len,cnt=0;
    len=min(s1.size(),s2.size());
    for (i=0;i<len;i++)
    {
        if (s1[i]!=s2[i]) break;
        cnt++;
    }
    return cnt;
}

int main()
{
    int n=0,now,num;
    while(cin>>word[n])
    {
       // if (word[n][0]=='#') break;
        n++;
    }
    cout<<word[0]<<endl;
    now=0;
    for (int i=1;i<n;i++)
    {
        //num=Cpy(word[i],word[i-1]);
       // printf("%d\n",now);
        if (word[i][0]!=word[i-1][0])
        {
            cout<<word[i]<<endl;
            now=0;
        }
        else
        {
            if (now==0)
            {
                cout<<' '<<word[i]<<endl;
                now=1;
            }
            else
            {
                if (word[i].size()>now&&word[i-1].size()>now&&word[i][now]==word[i-1][now]) now++;
                else
                {
                    now=1;
                    while(word[i].size()>now&&word[i-1].size()>now&&word[i][now]==word[i-1][now])
                        now++;
                }
                if (now<1) now=1;
                for (int j=1;j<=now;j++)
                    cout<<' ';
                cout<<word[i]<<endl;
            }
        }
    }
    return 0;
}
