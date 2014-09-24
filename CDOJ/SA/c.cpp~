#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<sstream>
#include<vector>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define MAXN 17

typedef long long ll;
using namespace std;

int n,m;
char maze[MAXN][MAXN];
int px[10],py[10];
int dx[]={
	0,1, 0,-1
};
int dy[]={
	1,0,-1, 0
};

struct node
{
	int x,y;
	int ha;
	int step;
};

int main()
{
	int cas=0;
	while(~scanf("%d%d",&n,&m))
	{
//		scanf("%d%d",&n,&m);
		set<int> vis[MAXN][MAXN];
		cas++;
		int len=0;
		for(int i=0;i<n;i++)
		{
			char str[MAXN];
			scanf("%s",str);
			for(int j=0;j<m;j++)
			{
				maze[i][j]=str[j];
				if(str[j]-'0'>=1&&str[j]-'0'<=9)
				{
					len=max(len,str[j]-'0');
					px[str[j]-'0']=i;
					py[str[j]-'0']=j;
				}
			}
		}
		int mask=0;
		for(int i=2;i<=len;i++)
			for(int j=0;j<4;j++)
			{
				if(px[i]-px[i-1]==dx[j]&&py[i]-py[i-1]==dy[j])
				{
					mask^=j<<(2*(i-2));
					break;
				}
			}
		node fr;fr.x=px[1];fr.y=py[1];fr.step=0;fr.ha=mask;
		vis[px[1]][py[1]].insert(mask);
		queue<node> q;
		q.push(fr);
		bool flag=0;
//		cout<<1<<endl;
		while(!q.empty())
		{
			node u=q.front();
			q.pop();
			px[1]=u.x;py[1]=u.y;
			for(int i=2;i<=len;i++)
			{
				int temp=(u.ha>>(2*(i-2)))&3;
				px[i]=px[i-1]+dx[temp];
				py[i]=py[i-1]+dy[temp];
			}
			for(int i=1;i<=len-1;i++)
			{
				maze[px[i]][py[i]]='#';
			}
			for(int d=0;d<4;d++)
			{
				node nn;
				nn.x=u.x+dx[d];
				nn.y=u.y+dy[d];
				int pnx[10],pny[10];
				pnx[1]=nn.x;pny[1]=nn.y;
				for(int i=2;i<=len;i++)
				{
					pnx[i]=px[i-1];
					pny[i]=py[i-1];
				}
				int nm=0;
				for(int i=2;i<=len;i++)
					for(int j=0;j<4;j++)
					{
						if(pnx[i]-pnx[i-1]==dx[j]&&pny[i]-pny[i-1]==dy[j])
						{
							nm^=j<<(2*(i-2));
							break;
						}
					}
				if(nn.x>=0&&nn.x<n&&nn.y>=0&&nn.y<m&&maze[nn.x][nn.y]!='#'&&!vis[nn.x][nn.y].count(nm))
				{
					if(maze[nn.x][nn.y]=='@')
					{
						flag=1;
						cout<<"Case #"<<cas<<": ";
						cout<<u.step+1<<endl;
						break;
					}
					vis[nn.x][nn.y].insert(nm);
					nn.step=u.step+1;
					nn.ha=nm;
					q.push(nn);
				}
			}
			for(int i=1;i<=len-1;i++)
			{
				maze[px[i]][py[i]]='.';
			}
			if(flag)
				break;
		}
		if(!flag)
		{
			cout<<"Case #"<<cas<<": ";
			cout<<-1<<endl;
		}
	}
	return 0;
}
