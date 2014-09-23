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

int a[200005];

int main(){
	int n;
	cin>>n;
	int minn=INT_MAX,maxx=0;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
	}
	cout<<maxx-minn<<' ';
	ll cnta=0,cntb=0;
	for(int i=0;i<n;i++){
		if(a[i]==maxx)
			cnta++;
		if(a[i]==minn)
			cntb++;
	}
	if(maxx==minn){
		cout<<cnta*(cnta-1)/2;
		return 0;
	}
	cout<<cnta*cntb;
	return 0;
}
