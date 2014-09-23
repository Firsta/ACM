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
#define MAXN 100005

typedef __int64 ll;
typedef unsigned long long ull;
using namespace std;

ll a[MAXN],b[MAXN],c[MAXN];
int hash[MAXN];

int main(){
	int n;
	while(~scanf("%d",&n)&&(n)){
		for(int i=0;i<n;i++)
			scanf("%I64d",&a[i]);
		memset(hash,-1,sizeof(hash));
		memset(b,0,sizeof(b));
		hash[a[n-1]]=n-1;
		for(int i=n-2;i>=0;i--){
			for(ll k=1;k*k<=a[i];k++){
				if(a[i]%k==0){
					if(hash[k]!=-1){
						b[hash[k]]=a[i];
						hash[k]=-1;
					}
					if(hash[a[i]/k]!=-1){
						b[hash[a[i]/k]]=a[i];
						hash[a[i]/k]=-1;
					}
				}
			}
			hash[a[i]]=i;
		}
		for(int i=0;i<n;i++)
			if(b[i]==0)
				b[i]=a[i];
		memset(hash,-1,sizeof(hash));
		memset(c,0,sizeof(c));
		hash[a[0]]=0;
		for(int i=1;i<n;i++){
			for(int k=1;k*k<=a[i];k++){
				if(a[i]%k==0){
					if(hash[k]!=-1){
						c[hash[k]]=a[i];
						hash[k]=-1;
					}
					if(hash[a[i]/k]!=-1){
						c[hash[a[i]/k]]=a[i];
						hash[a[i]/k]=-1;
					}
				}
			}
			hash[a[i]]=i;
		}
		for(int i=0;i<n;i++)
			if(c[i]==0)
				c[i]=a[i];
		ll ans=0;
		for(int i=0;i<n;i++)
			ans+=b[i]*c[i];
		printf("%I64d\n",ans);
	}
	return 0;
}
