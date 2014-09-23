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

int h[100005];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	ll ans=0;
	ll s=0;
	for(int i=0;i<n;i++){
		if(h[i+1]>h[i]&&s<h[i+1]-h[i]){
			ans+=h[i+1]-h[i]-s;
			s=0;
		}else if(h[i+1]>h[i]&&s>=h[i+1]-h[i])
			s-=(h[i+1]-h[i]);
		else if(h[i+1]<=h[i])
			s+=h[i]-h[i+1];
	}
	cout<<ans;
	return 0;
}
