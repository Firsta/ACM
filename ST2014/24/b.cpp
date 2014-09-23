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
#define MAXN 20005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

double phi[MAXN];
vector<int> t1,t2;

int main(){
	int n,r;
	int cas=0;
	while(~scanf("%d%d",&n,&r)&&(n||r)){
		ll ans=0;t1.clear();t2.clear();
		for(int i=0;i<n;i++)
			scanf("%lf",&phi[i]);
		sort(phi,phi+n);
		printf("Case %d: ",++cas);
		if(phi[0]>=180||phi[n-1]<=180){
			printf("0\n");
			continue;
		}
		int i=1,j=1;
		for(;j<n;j++)
			if(phi[j]>phi[0]+180)
				break;
		while(i<n&&phi[i]<=phi[0]+180){
			int cnt=0;
			while(j<n&&phi[j]<phi[i]+180){
				cnt++;
				j++;
			}
			t1.push_back(cnt);
			i++;
		}
		for(int i=0;i<t1.size();i++)
			cout<<t1[i]<<' ';
		cout<<endl;
		int lena=t1.size();
		for(int i=0;i<lena;i++)
			ans+=(ll)t1[i]*(ll)(lena-i)*(ll)(i+1);
		i=0,j=0;
		for(;i<n;i++)
			if(phi[i]>phi[0]+180)
				break;
		int base=i;i++;
		for(;j<base;j++)
			if(phi[j]>phi[base]-180)
				break;
		while(i<n){
			int cnt=0;
			while(j<base&&phi[j]<phi[i]-180){
				cnt++;
				j++;
			}
			t2.push_back(cnt);
			i++;
		}
		int lenb=t2.size();
		for(int i=0;i<lenb;i++)
			ans+=(ll)t2[i]*(ll)(i+1)*(ll)(lenb-i);
		printf("%lld\n",ans);
	}
	return 0;
}
