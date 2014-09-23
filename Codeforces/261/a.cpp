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
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1==x2){
		cout<<x1+abs(y1-y2)<<' '<<y1<<' ';
		cout<<x2+abs(y1-y2)<<' '<<y2;
	}else if(y1==y2){
		cout<<x1<<' '<<y1+abs(x1-x2)<<' ';
		cout<<x2<<' '<<y2+abs(x1-x2);
	}else if(abs(x1-x2)==abs(y1-y2)){
		cout<<x1<<' '<<y2<<' ';
		cout<<x2<<' '<<y1;
	}else
		cout<<-1<<endl;
	return 0;
}
