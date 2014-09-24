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

int a[43];

int main(){
	int sum=0;
	for(int i=1;i<=43;i++){
		int tmp=1;
		for(int j=0;j<i;j++)
			tmp=(tmp%7)*(i%7)%7;
		sum=(sum%7+tmp%7)%7;
//		cout<<sum<<endl;
		a[i]=sum;
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		n=((n/42%7)*(a[42]%7)%7+a[n%42]%7)%7;
		if(n==0)
			printf("Saturday");
		else if(n==1)
			printf("Sunday");
		else if(n==2)
			printf("Monday");
		else if(n==3)
			printf("Tuesday");
		else if(n==4)
			printf("Wednesday");
		else if(n==5)
			printf("Thursday");
		else
			printf("Friday");
		printf("\n");
	}
	return 0;
}
