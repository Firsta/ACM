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
typedef unsigned __int64 ull;
using namespace std;

ull gcd(ull a,ull b){
	ull tmp;
	while(b!=0){
		a%=b;
		tmp=a;
		a=b;
		b=tmp;
	}
	return a;
}

int main(){
	ull g,l;
	while(~scanf("%I64d%I64d",&g,&l)){
		ull c=l/g;
		for(ull i=(ull)sqrt(double(c));i>=1;i--){
			if(c%i==0&&gcd(i,c/i)==1){
				printf("%I64d %I64d\n",i*g,l/i);
				break;
			}
		}
	}
	return 0;
}
