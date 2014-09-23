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
	int p;
	scanf("%d",&p);
	while(p--){
		int n,m;
		scanf("%d%d",&n,&m);
		int a=1,b=1,cnt=2,ans;
		for(;;){
			int tmp=(a+b)%m;
			if(tmp==b&&tmp==1){
				ans=cnt-1;
				break;
			}else{
				a=b;
				b=tmp;
				cnt++;
			}
		}
		printf("%d ",n);
		printf("%d\n",ans);
	}
	return 0;
}
