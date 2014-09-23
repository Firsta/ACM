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
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		int n,m;
		scanf("%d%d",&n,&m);
		int cnta=0,cntb=0;
		if(n%2){
			cntb+=m;
		}
		if(m%2){
			if(cntb!=0)
				cntb+=(n-1);
			else
				cntb+=n;
		}
		if(n%2)n--;if(m%2)m--;
		int sum=n*m/4;
		cnta+=(sum-sum/2)*4;
		cntb+=(sum/2)*4;
		printf("Case #%d: ",cas);
		if(cnta>cntb)
			printf("Ana\n");
		else if(cntb>cnta)
			printf("Bob\n");
		else
			printf("Draw\n");
	}
	return 0;
}
