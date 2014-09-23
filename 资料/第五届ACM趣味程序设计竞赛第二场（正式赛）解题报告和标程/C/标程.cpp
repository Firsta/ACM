#include<cstdio>
int main()
{
    int n,f,tt;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d%d",&n,&f);
        if(f<(2*n*n*n+3*n*n+n)/6)
            printf("-1\n");
        else
        {
            for(int i=1;i<=n-1;i++)
                printf("%d ",i);
            printf("%d\n",n+f-(2*n*n*n+3*n*n+n)/6);
        }
    }
}
