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

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int b,p,l,n;
ll c[MAXN];

int lowbit(int x){
	return x&-x;
}

int sum(int x){
	int ret=0;
	while(x>0){
		ret=(ret+c[x])%p;
		x-=lowbit(x);
	}
	return ret;
}

void add(int x,int d){
	while(x<=n){
		c[x]=(c[x]+d)%p;
		x+=lowbit(x);
	}
}

int extgcd(int a,int b,int &x,int &y){
	int d=a;
	if(b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else{
		x=1;y=0;
	}
	return d;
}

//ax=1(mod m)=>ax-mk=1
int mod_inverse(int a,int m){
	int x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}

int fact[MAXN];

int main(){
	while(~scanf("%d%d%d%d",&b,&p,&l,&n)&&(b||p||l||n)){
		string s;
		memset(c,0,sizeof(c));
		fact[0]=1;
		for(int i=1;i<=n;i++)
			fact[i]=(fact[i-1]%p)*(b%p)%p;
		while(n--){
			cin>>s;
			if(s=="E"){
				int i,v;
				scanf("%d%d",&i,&v);
				int ori=sum(i)-sum(i-1);
				int now=(v%p)*(fact[n-i]%p)%p;
				int d=(now-ori);
				add(i,d);
			}else if(s=="H"){
				int i,j;
				scanf("%d%d",&i,&j);
				int up=(sum(n)-sum(i-1))%p;
				int down=fact[n-j-1];
				int ans=up*mod_inverse(down%p,p)%p;
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
