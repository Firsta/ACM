#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<queue>
#define MAXN 5010
#define INF 100000000
#define MAXM 200100

using namespace std;
typedef long long ll;

int n,m,s,t,k;

bool vis[MAXN][51];
int dis[MAXN][51],u[MAXM],v[MAXM],w[MAXM],nex[MAXM],first[MAXN];

struct node
{
	int pos,d,step;
};

struct cmp
{
	bool operator() (const node &a,const node &b)
	{
		if(a.d>b.d)
			return 1;
		else
			return 0;
	}
};

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(first,-1,sizeof(first));
		memset(u,0,sizeof(u));
		memset(v,0,sizeof(v));
		memset(nex,0,sizeof(nex));
		for(int e=0;e<2*m;e++)
		{
			scanf("%d%d%d",&u[e],&v[e],&w[e]);
			nex[e]=first[u[e]];
			first[u[e]]=e;
			e++;
			u[e]=v[e-1];
			v[e]=u[e-1];
			w[e]=w[e-1];
			nex[e]=first[u[e]];
			first[u[e]]=e;
		}
//		cout<<INT_MAX<<endl;
/*		for(int i=0;i<2*m;i++)
		{
			cout<<u[i]<<'>'<<v[i]<<' '<<w[i]<<endl;
		}*/
		scanf("%d%d%d",&s,&t,&k);
//		cout<<s<<' '<<t<<' '<<k<<endl;
//		cout<<n<<' '<<k<<endl;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=k;j++)
			{
				dis[i][j]=INF;
			}
		dis[s][0]=0;
		memset(vis,0,sizeof(vis));
		priority_queue<node,vector<node>,cmp> pque;
		node f;
		f.pos=s;f.d=0;f.step=0;
		pque.push(f);
//		cout<<dis[3][1]<<endl;
		while(!pque.empty())
		{
			node u=pque.top();
			pque.pop();
			if(vis[u.pos][u.step])
				continue;
			vis[u.pos][u.step]=true;
			if(u.pos==t&&u.step==k)
				break;
			for(int e=first[u.pos];e!=-1;e=nex[e])
			{
//				cout<<1<<endl;
				node nn;
				nn.pos=v[e];
				nn.step=u.step+1;
				if(nn.step>k)
					nn.step=k;
				if(vis[nn.pos][nn.step])
					continue;
				if(dis[nn.pos][nn.step]>dis[u.pos][u.step]+w[e])
				{
//					cout<<dis[u.pos][u.step]+w[e]<<endl;
					dis[nn.pos][nn.step]=dis[u.pos][u.step]+w[e];
					nn.d=dis[u.pos][u.step]+w[e];
					pque.push(nn);
				}
			}
		}
		if(dis[t][k]==INF)
			printf("-1\n");
		else
			printf("%d\n",dis[t][k]);
	}
	return 0;
}
