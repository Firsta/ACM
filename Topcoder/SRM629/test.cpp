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

double a,b,c;

double f(double x){
	return a*x*x-b*x+c;
}

int main(){
	vector<int> containerVolume, desiredWeight;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int t1,t2;
		cin>>t1>>t2;
		containerVolume.push_back(t1);
		desiredWeight.push_back(t2);
	}
	for(int i=0;i<n;i++){
		a+=containerVolume[i]*containerVolume[i];
		b+=2*containerVolume[i]*desiredWeight[i];
		c+=desiredWeight[i]*desiredWeight[i];
	}
	cout<<a<<' '<<b<<' '<<c<<endl;
	double avg=b/(2*a);
	cout<<avg<<endl;
	double diff=0.0;
	for(int i=0;i<n;i++){
		diff+=fabs((double)desiredWeight[i]-(double)containerVolume[i]*avg);
	}
	cout<<diff<<endl;
	return 0;
}
