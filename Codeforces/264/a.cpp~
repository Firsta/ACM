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

int main(){
	int n,s;
	cin>>n>>s;
	int ans=-1;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		if(x<s){
			if(y!=0)
				ans=max(ans,100-y);
			else
				ans=max(ans,0);
		}else if(x==s&&y==0)
			ans=max(ans,0);
	}
	cout<<ans;
	return 0;
}
