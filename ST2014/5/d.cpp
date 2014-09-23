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
using namespace std;

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int ans=b*2+40;
	ans=max(ans,39*2+40+2*(a-40)+1);
	printf("%d\n",ans);
	return 0;
}
