#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<sstream>
#include<string>
#define MAXN 100005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct node{
	int x,y;
}me[MAXN],ta[MAXN];

bool vis[MAXN];

bool cmp(const node &a,const node &b){
	if(a.x!=b.x)
		return a.x>b.x;
	else
		return a.y>b.y;
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++)
			scanf("%d%d",&me[i].x,&me[i].y);
		for(int i=0;i<m;i++)
			scanf("%d%d",&ta[i].x,&ta[i].y);
		sort(me,me+n,cmp);
		sort(ta,ta+m,cmp);
		int i=0,j=0;
		ll ans=0;
		int cnt=0;
		while(i<m){
			if(j<n&&me[j].x>=ta[i].x&&me[j].y>=ta[i].y){
				ans+=(ll)ta[i].x*500+(ll)ta[i].y*2;
				j++;
				cnt++;
			}
			i++;
		}
		printf("%d ",cnt);
		printf("%I64d\n",ans);
	}
	return 0;
}
