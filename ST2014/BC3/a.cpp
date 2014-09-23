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

int ttime[200100];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		memset(ttime,0,sizeof(ttime));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
			ttime[tmp]=1;
		}
		while(m--){
			int q;
			scanf("%d",&q);
			for(int i=q;;i++){
				if(ttime[i]==0){
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
}
