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

int read[1005];

int main(){
	int n;
	scanf("%d",&n);
	int cnt=0;
	for(int i=0;i<n;i++){
		scanf("%d",&read[i]);
		if(read[i]==1)
			cnt++;
	}
	int ans=0;
	int cc=0;
	for(int i=0;i<n;i++){
		if(read[i]==1){
			cc++;
			ans++;
		}else if(read[i]==0)
			if(i>0&&read[i-1]==1)
				ans++;
		if(cc==cnt)
			break;
	}
	printf("%d",ans);
	return 0;
}
