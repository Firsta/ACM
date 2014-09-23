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
#define MAXN 1100

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int head[MAXN],in[MAXN];
int em;

struct edge{
	int to,next;
}edges[MAXN*MAXN];

void addedge(int u,int v){
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
}

int main(){
	//c1=>r1 1=>1+2
	//c2=>r1 2=>1+2
	//r2=>c1 2+2=>1
	//c2=>r2 2=>2+2
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		em=0;
		memset(head,-1,sizeof(head));
		char tmp[505];
		//x:column x+n:row
		for(int i=1;i<=n;i++){
			scanf("%s",tmp);
			for(int j=0;j<n;j++){
				if(tmp[j]=='X'){
					addedge(j+1,i+n);
					in[i+n]++;
				}else{
					addedge(i+n,j+1);
					in[j]++;
				}
			}
		}
		priority_queue<int,vector<int>,greater<int> > pque;
		bool find=false;
		for(int i=1;i<=2*n;i++)
			if(in[i]==0){
				pque.push(i);
				find=true;
			}
		if(!find){
			printf("No solution\n");
			continue;
		}
		vector<int> ans;
		while(!pque.empty()){
			int now=pque.top();
			ans.push_back(now);
			pque.pop();
			for(int e=head[now];e!=-1;e=edges[e].next){
				int v=edges[e].to;
				in[v]--;
				if(in[v]==0)
					pque.push(v);
			}
		}
		int s=0;
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<' ';
		cout<<endl;
		if(ans[0]>n)
			while(ans[s]>n)
				s++;
		else
			while(ans[s]<=n)
				s++;
		if(ans[s]<=n)
			printf("C%d",ans[s]);
		else
			printf("R%d",ans[s]-n);
		for(;s<ans.size();s++){
			if(ans[s]>n){
				printf(" R%d",ans[s]-n);
			}else
				printf(" C%d",ans[s]);
		}
		printf("\n");
	}
	return 0;
}
