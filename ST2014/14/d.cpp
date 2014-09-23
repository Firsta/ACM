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

int hash[105];
vector<int> ss[15];
set<int> se[15];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int tmp;
			scanf("%d",&tmp);
			ss[i].push_back(tmp);
			se[i].insert(tmp);
		}
	}
	while(m--){
		int k;
		scanf("%d",&k);
		memset(hash,0,sizeof(hash));
		for(int i=0;i<k;i++){
			int tmp;
			scanf("%d",&tmp);
			if(tmp>0)
				hash[tmp]++;
			else
				hash[-tmp]--;
		}
		vector<int> ans;
		int cnt=0;
		for(int i=0;i<n;i++){
			bool flag=true;
			for(int j=0;j<101;j++){
				if(hash[j]>0&&(!se[i].count(j))||hash[j]<0&&se[i].count(j)){
					flag=false;
					break;
				}
			}
			if(flag){
				cnt++;
				ans.push_back(i);
			}
		}
		printf("%d\n",cnt);
		if(!cnt)
			continue;
		else{
			for(int i=0;i<ans.size();i++){
				printf("%d",ss[ans[i]].size());
				for(int j=0;j<ss[ans[i]].size();j++)
					printf(" %d",ss[ans[i]][j]);
				printf("\n");
			}
		}
	}
	return 0;
}
