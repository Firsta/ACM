/*
ID: firstaw1
PROG: pprime
LANG: C++
*/
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
#define MAXN 100000001

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int a,b;

int t[8];

int l;

vector<int> ans;

bool isprime(int x){
	bool flag=true;
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			flag=false;
			break;
		}
	return flag;
}

void dfs(int len,int step){
	if(step==0){
		int tmp=0;
		for(int i=0;i<l;i++)
			tmp=tmp*10+t[i];
		if(isprime(tmp)&&tmp<=b&&tmp>=a)
			ans.push_back(tmp);
		return;
	}
	if(len==l){
		for(int i=1;i<=9;i++){
			t[len-1]=t[0]=i;
			dfs(len-1,step-1);
		}
	}else{
		for(int i=0;i<=9;i++){
			t[len-1]=t[l-len]=i;
			dfs(len-1,step-1);
		}
	}
}

int main(){
	freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
	scanf("%d%d",&a,&b);
	int lena=0,lenb=0;
	int ta=a,tb=b;
	while(ta){
		lena++;
		ta/=10;
	}
	while(tb){
		lenb++;
		tb/=10;
	}
	if(lenb==9)
		lenb--;
	for(l=lena;l<=lenb;l++){
		if(l%2)
			dfs(l,l/2+1);
		else
			dfs(l,l/2);
	}
	if(ans.size()==0)
		return 0;
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		printf("%d\n",ans[i]);
	return 0;
}
