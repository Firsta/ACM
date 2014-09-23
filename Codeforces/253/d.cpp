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

double p[105];
vector<double> a;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>p[i];
	sort(p,p+n);
	double ans=0;
	for(int i=1;i<=n;i++){
		a.clear();
		a.push_back(p[n-1]);
		for(int j=0;j<i-1;j++)
			a.push_back(p[j]);
		double tmp=1;
		double tp=0;
		for(int j=0;j<a.size();j++)
			tmp*=1-a[j];
		for(int j=0;j<a.size();j++)
			tp+=tmp/(1-a[j])*a[j];
		ans=max(ans,tp);
	}
	printf("%.12f",ans);
	return 0;
}
