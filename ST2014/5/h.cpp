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
#define MAXN 4005

typedef long long ll;
using namespace std;

map<int,int> mapp;
int a[MAXN];

int main(){
	int n1;
	scanf("%d",&n1);
	for(int i=0;i<n1;i++){
		scanf("%d",&a[i]);
		mapp[a[i]]++;
	}
	int nt;
	scanf("%d",&nt);
	for(int i=0;i<nt;i++){
		int tmp;
		scanf("%d",&tmp);
		if(mapp[tmp]!=0){
			mapp[tmp]++;
		}
	}
	scanf("%d",&nt);
	for(int i=0;i<nt;i++){
		int tmp;
		scanf("%d",&tmp);
		if(mapp[tmp]!=0){
			mapp[tmp]++;
		}
	}
	int ans=0;
	for(int i=0;i<n1;i++){
		if(mapp[a[i]]==3)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}
