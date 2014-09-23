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
#define MAXN 2000000

typedef long long ll;
using namespace std;

int isprime[MAXN],prime[MAXN],cnt[MAXN],S[MAXN];

struct node{
	int num;
	int ind;
}x[MAXN];

stack<node> s;

int main(){
	for(int i=0;i<MAXN;i++)
		isprime[i]=1;
	int cnt=0;
	isprime[0]=isprime[1]=0;
	for(int i=0;i<MAXN;i++){
		if(isprime[i]){
			prime[cnt++]=i;
			for(int j=2*i;j<MAXN;j+=i)
				isprime[j]=0;
		}
	}
	cout<<cnt<<endl;
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		while(!s.empty())
			s.pop();
		int cnt=0,maxx,last=0;
		for(int i=0;i<n;i++){
			x[i].num=prime[i]%m;
			x[i].ind=i;
//			cout<<prime[i]%m<<' '<<cnt<<' '<<maxx<<' '<<ans<<endl;
		}
		for(int i=0;i<n;i++){
			while(!s.empty()){
				node tmp=s.top();
				if(x[i].num>=tmp.num)
					s.pop();
				else
					break;
			}
			if(s.empty())
				S[i]=i+1;
			else{
				node tmp=s.top();
				S[i]=i-tmp.ind;
			}
			s.push(x[i]);
		}
		int ans=0;
		for(int i=0;i<n;i++)
			ans=(ans+S[i]%m);
		printf("%d\n",ans%m);
	}
	return 0;
}
