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
	while(t--){
		int n,a,d;
		scanf("%d%d%d",&n,&a,&d);
		cout<<(2*a+(n-1)*d)*n/2<<endl;
	}
	return 0;
}
