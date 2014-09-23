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

ll a[100][100];

int main(){
	a[0][0]=a[1][0]=a[2][0]=a[3][0]=0;
	a[0][1]=233;a[0][2]=2333;a[0][3]=23333;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			a[i][j]=a[i-1][j]+a[i][j-1];
	for(int i=0;i<=3;i++){
		for(int j=0;j<=3;j++)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
