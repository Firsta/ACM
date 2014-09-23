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

ll sumz[10000];
ll sumf[10000];
int a[2005][2005];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			sumz[i+j]+=a[i][j];
			sumf[i-j+n]+=a[i][j];
		}
	ll max0=-1,max1=-1;
	int x1,x2,y1,y2;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if((i+j)%2==0){
				if(sumz[i+j]+sumf[i-j+n]-a[i][j]>max0){
					max0=sumz[i+j]+sumf[i-j+n]-a[i][j];
					x1=i;y1=j;
				}
			}
			else{
				if(sumz[i+j]+sumf[i-j+n]-a[i][j]>max1){
					max1=sumz[i+j]+sumf[i-j+n]-a[i][j];
					x2=i;y2=j;
				}
			}
		}
	printf("%I64d\n",max0+max1);
	printf("%d %d %d %d",x1+1,y1+1,x2+1,y2+1);
	return 0;
}
