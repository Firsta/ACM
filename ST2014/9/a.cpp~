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
#define INF 1000000007
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		string s;
		cin>>s;
		stack<int> sa,sb;
		int n=s.size();
		for(int i=0;i<n/2;i++){
			sa.push(s[i]-'0');
		}
		for(int i=n-1;i>=n/2;i--){
			sb.push(s[i]-'0');
		}
		ll ans=0;
		while(!(sa.empty()&&sb.empty())){
			int now;
			if(sa.size()>sb.size()){
				now=sa.top();
				ans=(ans*2+now)%INF;
				sa.pop();
			}else if(sb.size()>sa.size()){
				now=sb.top();
				ans=(ans*2+now)%INF;
				sb.pop();
			}else if(sa.size()==sb.size()){
				int nowa=sa.top();
				int nowb=sb.top();
				if(nowb>nowa){
					now=nowb;
					ans=(ans*2+nowb)%INF;
					sb.pop();
				}else{
					now=nowa;
					ans=(ans*2+nowa)%INF;
					sa.pop();
				}
			}
	//		cout<<now<<'!'<<ans<<endl;
		}
		printf("Case #%d: %lld\n",cas,ans%INF);
	}
	return 0;
}
