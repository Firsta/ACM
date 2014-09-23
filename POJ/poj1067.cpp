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
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		if((max(a,b)-min(a,b))%2)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}
