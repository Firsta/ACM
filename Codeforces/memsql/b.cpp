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
	if(n==0){
		cout<<0<<' '<<1<<endl;
		cout<<0<<' '<<m<<endl;
		cout<<0<<' '<<0<<endl;
		cout<<0<<' '<<m-1;
	}else if(m==0){
		cout<<1<<' '<<0<<endl;
		cout<<n<<' '<<0<<endl;
		cout<<0<<' '<<0<<endl;
		cout<<n-1<<' '<<0;
	}else{
		if(m>=n){
			double lena,lenb;
			lena=sqrt(m*m+(n-1)*(n-1))*2;
			lenb=sqrt(n*n+m*m)+m;
			if(lena>lenb){
				cout<<1<<' '<<0<<endl;
				cout<<n<<' '<<m<<endl;
				cout<<0<<' '<<0<<endl;
				cout<<n-1<<' '<<m<<endl;
			}else{
				cout<<0<<' '<<0<<endl;
				cout<<n<<' '<<m<<endl;
				cout<<n<<' '<<0<<endl;
				cout<<0<<' '<<m<<endl;
			}
		}else{
			double lena,lenb;
			lena=sqrt(n*n+(m-1)*(m-1))*2;
			lenb=sqrt(n*n+m*m)+n;
			if(lena>lenb){
				cout<<0<<' '<<1<<endl;
				cout<<n<<' '<<m<<endl;
				cout<<0<<' '<<0<<endl;
				cout<<n<<' '<<m-1<<endl;
			}else{
				cout<<0<<' '<<0<<endl;
				cout<<n<<' '<<m<<endl;
				cout<<0<<' '<<m<<endl;
				cout<<n<<' '<<0<<endl;
			}
		}
	}
	return 0;
}
