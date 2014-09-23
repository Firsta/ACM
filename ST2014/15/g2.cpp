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

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int mark[23];
vector<int> G[23];

int main(){
	int t;
	ll tt=(1<<22);
	cout<<tt<<endl;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			G[i].clear();
			int k;
			scanf("%d",&k);
			while(k--){
				int v;
				scanf("%d",&v);
				G[i].push_back(v);
			}
			G[i].push_back(i+1);
		}
		int ans=23;
		for(int i=1;i<(1<<n);i++){
			fill(mark,mark+n,0);
			int cnt=0;
			for(int j=0;j<n;j++)
				if(i&(1<<j)){
					cnt++;
					for(int k=0;k<G[j].size();k++)
							mark[G[j][k]-1]=1;
				}
			bool find=false;
			for(int j=0;j<n;j++)
				if(!mark[j]){
					find=true;
					break;
				}
			if(!find)
				ans=min(ans,cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}
