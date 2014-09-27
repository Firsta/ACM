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
#define MAXN 200005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int a[MAXN],b[MAXN],da[MAXN],db[MAXN],f[MAXN];
int n,m;

void getFail(int *P,int *f){
	f[0]=0;f[1]=0;
	for(int i=1;i<m;i++){
		int j=f[i];
		while(j&&P[i]!=P[j])
			j=f[j];
		f[i+1]=(P[i]==P[j] ? j+1:0);
	}
}

int find(int *T,int *P,int *f){
	int ret=0;
	getFail(P,f);
	int j=0;
	for(int i=0;i<n;i++){
		while(j&&P[j]!=T[i])
			j=f[j];
		if(P[j]==T[i])
			j++;
		if(j==m){
			ret++;
			cout<<i<<endl;
		}
	}
	return ret;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<m;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<n;i++)
		da[i-1]=a[i]-a[i-1];
	for(int i=1;i<m;i++)
		db[i-1]=b[i]-b[i-1];
	n--;m--;
	printf("%d",find(da,db,f));
	return 0;
}
