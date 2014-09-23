#include<cstdio>
using namespace std;

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(n%2||m%2)puts("UDK");
        else puts("RU");
    }
    return 0;
}