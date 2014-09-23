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

priority_queue<ll> qa;
priority_queue<ll> qb;

int a[1010],b[1010];
ll pa[1000100],pb[1000100];

int main(){
	int n,m,p;
	int k;
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			int tmp;
			scanf("%d",&tmp);
			a[i]+=tmp;
			b[j]+=tmp;
		}
	for(int i=0;i<n;i++)
		qa.push(a[i]);
	for(int i=0;i<m;i++)
		qb.push(b[i]);
	for(int i=1;i<=k;i++){
		ll t=qa.top();
		qa.pop();
		pa[i]=t+pa[i-1];
		qa.push(t-m*p);
		t=qb.top();
		qb.pop();
		pb[i]=t+pb[i-1];
		qb.push(t-n*p);
	}
	ll ans=-1000000000;
	ans*=-ans;
//	for(int i=0;i<=k;i++)
//		cout<<pa[i]<<' ';
//	cout<<endl;
//	for(int i=0;i<=k;i++)
//		cout<<pb[i]<<' ';
//	cout<<endl;
	for(int i=0;i<=k;i++){
		ans=max(ans,pa[i]+pb[k-i]-((ll)i)*(k-i)*p);
	}
	printf("%I64d",ans);
	return 0;
}
