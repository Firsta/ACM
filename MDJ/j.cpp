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
#define eps 1e-10
#define PI acos(-1.0)
#define K (0.017453292519943295769236907684886l)

using namespace std;

string s,pe,A,B,C;

int Lenpe;

bool Can(int la,int lb)
{
    int i,lc,flag;
    A.clear();B.clear();C.clear();
    //printf("%d %d\n",la,lb);
    //for the first case;
    if (la*3+lb*2==Lenpe)
    {
        flag=1;
        for (i=0;i<la;i++)
            A.push_back(pe[i]);
        for (i=0;i<lb;i++)
            B.push_back(pe[i+la]);
        if (A==B) flag=0;
        for (i=0;i<la;i++)
        {
            if (pe[i]!=pe[i+la+lb]) { flag=0;break; }
            if (pe[i]!=pe[i+la*2+lb*2]) { flag=0;break;}
        }
        for (i=0;i<lb;i++)
        {
            if (pe[i+la]!=pe[i+la*2+lb]) { flag=0;break;}
        }
        if (flag==1) return true;
    }
    else if (la*3+lb*3<Lenpe)
    {
        for (i=0;i<la;i++)
            A.push_back(pe[i]);
        for (i=0;i<lb;i++)
            B.push_back(pe[i+la]);
        flag=1;
        lc=Lenpe-(la+lb)*3;
        for (i=0;i<lc;i++)
            C.push_back(pe[i+la*2+lb*2]);
        if (A==B||B==C||A==C) flag=0;
        for (i=0;i<la;i++)
        {
          //  printf("%c %c %c\n",pe[i],pe[i+la+lb],pe[i+la*2+lb*2+lc]);
            if (pe[i]!=pe[i+la+lb]) { flag=0;break;}
            if (pe[i]!=pe[i+la*2+lb*2+lc]) { flag=0;break;}
        }
       // printf("%d\n",flag);
        for (i=0;i<lb;i++)
        {
           // printf("%c %c %c\n",pe[i+la],pe[i+la*2+lb],pe[i+la*3+lb*2+lc]);
            if (pe[i+la]!=pe[i+la*2+lb]) { flag=0;break;}
            if (pe[i+la]!=pe[i+la*3+lb*2+lc]) { flag=0;break;}
        }
        //if (flag==1) cout<<A<<' '<<B<<' '<<C<<endl;
        if (flag==1) return true;
        //if (flag==1) cout<<A<<' '<<B<<' '<<C<<endl;
    }
    return false;
}

int main()
{
    int t,i,j,flag;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        pe.clear();
        int len=s.size();
        for (i=0;i<len;i++)
            {
                if (s[i]>='a'&&s[i]<='z') pe.push_back(s[i]);
                if (s[i]>='A'&&s[i]<='Z') pe.push_back(s[i]-'A'+'a');
            }
        Lenpe=pe.size();
        int lena=Lenpe/3;
        int lenb=Lenpe/2;
        //printf("%d\n",Lenpe);
        //printf("%d %d\n",lena,lenb);
       // cout<<pe<<endl;
        flag=0;
        for (i=1;i<=lena;i++)
            {
                for (j=1;j<=lenb;j++)
                if (Can(i,j))
                {
                    flag=1;
                    //printf("%d %d\n",i,j);
                    break;
                }
                if  (flag==1) break;
            }
        if (flag==1) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}

