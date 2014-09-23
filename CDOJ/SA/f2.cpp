//方老师与迷宫
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
char map[31][31][31];
bool vis[31][31][31];
int x,y,z;
int xx[]={0,0,0,0,-1,1};
int yy[]={0,0,-1,1,0,0};
int zz[]={-1,1,0,0,0,0};
struct lx
{
    int x,y,z;
};
lx S,E;
int bfs()
{
    queue<lx>q;
    lx tmp;
    q.push(S);
    tmp.x=-1,tmp.y=-1,tmp.z=-1;
    q.push(tmp);
    int ans=0;
    while(!q.empty())
    {
        tmp=q.front();
        if(tmp.x==-1&&tmp.y==-1&&tmp.z==-1)
        {
            q.pop();
            if(q.empty())
            return -1;
            ans++;
            q.push(tmp);continue;
        }q.pop();
        if(tmp.x==E.x&&tmp.y==E.y&&tmp.z==E.z)return ans;
        for(int l=0;l<6;l++)
        {
            int i=tmp.x+xx[l];
            int j=tmp.y+yy[l];
            int k=tmp.z+zz[l];
            if(i>=x||i<0||j>=y||j<0||k>=z||k<0)continue;
            if(!vis[i][j][k]&&map[i][j][k]!='#')
            {
                vis[i][j][k]=1;
                lx now;
                now.x=i,now.y=j,now.z=k;
                q.push(now);
            }
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d%d%d",&x,&y,&z),x&&y&&z)
    {
        char str[31];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
        {
            scanf("%s",str);
            for(int k=0;k<z;k++)
            {
                map[i][j][k]=str[k];
                if(str[k]=='E')E.x=i,E.y=j,E.z=k;
                if(str[k]=='S')S.x=i,S.y=j,S.z=k;
            }
        }
        vis[S.x][S.y][S.z]=1;
        int tmp=bfs();
        if(tmp==-1)puts("Trapped!");
        else printf("Escaped in %d minute(s).\n",tmp);
    }
}

