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
	int a1,a2,a3,b1,b2,b3;
	cin>>a1>>a2>>a3;
	cin>>b1>>b2>>b3;
	int n;
	cin>>n;
	int cnta;
	cnta=(a1+a2+a3)/5;
	if((a1+a2+a3)%5!=0)
		cnta++;
	int cntb=(b1+b2+b3)/10;
	if((b1+b2+b3)%10!=0)
		cntb++;
//cout<<cnta<<' '<<cntb<<endl;
	if(cnta+cntb>n){
		cout<<"NO"<<endl;
	}else
		cout<<"YES"<<endl;
	return 0;
}
