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
	int n,m;
	cin>>n>>m;
	int ans=0;
	int i=1;
	int sum=n;
	for(;;i++){
		if(sum==0)
			break;
		ans++;
		sum--;
		if(i%m==0)
			sum++;
	}
	cout<<ans<<endl;
	return 0;
}
