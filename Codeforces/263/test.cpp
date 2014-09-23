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

vector<int> a;
int main(){
	freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
	int n,k;
	string s;
	cin>>n>>k>>s;
	sort(s.begin(),s.end());
	s.push_back('#');
	for(int i=0;i<n;i++)
		for(int j=i;j<=n;j++)
			if(s[j]!=s[i]){
				a.push_back(j-i);
				i=j-1;
				break;
			}
	sort(a.begin(),a.end(),greater<int>());
	int t=0,d=0,nt;
	__int64 r=0;
	for(int i=0;i<a.size()&&t<k;i++){
		nt=min(t+a[i],k);
		d=nt-t;
		t=nt;
		r+=1ll*d*d;
	}
	cout<<r;
	return 0;
}
