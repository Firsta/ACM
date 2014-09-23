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
	double n,m;
	cin>>n>>m;
	double ans;
	if(n==1&&m==1){
		printf("%.9f",1);
	}
	ans=((n-1)*(m-1)/(n*m-1)+1)/n;
	printf("%.9f",ans);
	return 0;
}
