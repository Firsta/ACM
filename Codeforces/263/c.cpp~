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
#define MAXN 300005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll a[MAXN];

int main(){
	int n;
	cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	ll ans=sum;
	for(int i=0;i<n-1;i++){
		ans+=sum;
		sum-=a[i];
	}
	cout<<ans;
	return 0;
}
