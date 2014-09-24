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
#define MAXN 100

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector<int> a,b;

bool cmp(const int &a,const int &b){
	return a>b;
}

bool cmpp(const int &a,const int &b){
	int ta=a%10,tb=b%10;
	if(ta!=tb)
		return ta<tb;
	else
		return a<b;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		int n1,n2;
		a.clear();
		b.clear();
		int tmp;
		scanf("%d%d",&n1,&n2);
		for(int i=0;i<n1;i++){
			scanf("%d",&tmp);
			a.push_back(tmp);
		}
		for(int i=0;i<n2;i++){
			scanf("%d",&tmp);
			b.push_back(tmp);
		}
		a.erase(unique(a.begin(),a.end()),a.end());
		b.erase(unique(b.begin(),b.end()),b.end());
		n1=a.size();
		n2=b.size();
		sort(a.begin(),a.end(),cmp);
		sort(b.begin(),b.end(),cmp);
		int maxx=0;
		for(int i=0;i<n1;i++)
			for(int j=0;j<n2;j++){
				int ti=i,tj=j;
				int cnt=0;
				while(ti<n1&&tj<n2){
					if(a[ti]==b[tj]){
						cnt++;
						ti++;
						tj++;
					}else{
						break;
					}
				}
				maxx=max(cnt,maxx);
			}
		if(maxx==0){
			printf("NONE");
			if(cas!=t)
				printf("\n");
			continue;
		}
		int tsum=0;
		int ind;
		for(int i=0;i<n1;i++){
			bool flag=false;
			for(int j=0;j<n2;j++){
				int ti=i,tj=j;
				int cnt=0;
				int sum=0;
				while(ti<n1&&tj<n2){
					if(a[ti]==b[tj]){
						cnt++;
						sum+=a[ti];
						ti++;
						tj++;
					}else{
						break;
					}
				}
				if(cnt==maxx){
					ind=i;
					flag=true;
				}
			}
			if(flag)
				break;
		}
		vector<int> ans;
		for(int i=ind;i<ind+maxx;i++)
			ans.push_back(a[i]);
		printf("%d",ans[0]);
		for(int i=1;i<ans.size();i++)
			printf(" %d",ans[i]);
		printf("\n");
		sort(ans.begin(),ans.end(),cmpp);
		printf("%d",ans[0]);
		for(int i=1;i<ans.size();i++)
			printf(" %d",ans[i]);
		if(cas!=t)
			printf("\n");
	}
	return 0;
}
