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
using namespace std;

int a[5005];

int dfs(int l,int r){
	if(l>r){
		return 0;
	}
	int tmp=a[l];int ind=l;
	for(int i=l;i<=r;i++){
		if(a[i]<tmp){
			tmp=a[i];
			ind=i;
		}
	}
	for(int i=l;i<=r;i++)
		a[i]-=tmp;
	return min(r-l+1,dfs(l,ind-1)+dfs(ind+1,r)+tmp);
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=dfs(1,n);
	printf("%d\n",ans);
	return 0;
}
