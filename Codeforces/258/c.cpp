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
	cin>>t;
	while(t--){
		ll n,k,d1,d2;
		cin>>n>>k>>d1>>d2;
		if(n%3!=0){
			cout<<"no"<<endl;
			continue;
		}
		ll w1,w2,w3;
		bool flag=true;
		if(k-2*d1-d2<0||(k-2*d1-d2)%3!=0)
			flag=false;
		if(flag){
			w1=(k-2*d1-d2)/3;
			w2=d1+w1;
			w3=d1+d2+w1;
			if(w1>n/3||w2>n/3||w3>n/3)
				flag=false;
		}
		if(!flag){
			flag=true;
			if(k+2*d2-d1<0||(k+2*d2-d1)%3!=0)
				flag=false;
			if(flag){
				w3=(k+2*d2-d1)/3;
				w1=w3+d1-d2;
				w2=w3-d2;
				if(w1>n/3||w2>n/3||w3>n/3||w1<0||w2<0)
					flag=false;
			}
		}
		if(!flag){
			flag=true;
			if(k+d2-2*d1<0||(k+d2-2*d1)%3!=0)
				flag=false;
			if(flag){
				w1=(k+d2-2*d1)/3;
				w2=d1+w1;
				w3=d1-d2+w1;
				if(w1>n/3||w2>n/3||w3>n/3||w3<0)
					flag=false;
			}
		}
		if(!flag){
			flag=true;
			if(k-2*d2-d1<0||(k-2*d2-d1)%3!=0)
				flag=false;
			if(flag){
				w3=(k-2*d2-d1)/3;
				w1=w3+d1+d2;
				w2=d2+w3;
				if(w3>n/3||w2>n/3||w1>n/3)
					flag=false;
			}
		}
		if(flag)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
