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

struct node{
	int h,m;
}t[100];

int h1[4][7],h2[4][7],h[4][7];

void add(node &x,int d){
	x.m+=d;
	x.h+=x.m/60;
	x.h%=24;
	x.m%=60;
}

void ch(int a[],int num){
	if(num==0)
		a[0]=a[1]=a[2]=a[3]=a[4]=a[5]=1;
	if(num==1)
		a[3]=a[4]=1;
	if(num==2)
		a[1]=a[2]=a[4]=a[5]=a[6]=1;
	if(num==3)
		a[2]=a[3]=a[4]=a[5]=a[6]=1;
	if(num==4)
		a[3]=a[4]=a[0]=a[6]=1;
	if(num==5)
		a[0]=a[2]=a[3]=a[5]=a[6]=1;
	if(num==6)
		a[0]=a[1]=a[2]=a[3]=a[6]=a[5]=1;
	if(num==7)
		a[3]=a[4]=a[5]=1;
	if(num==8)
		a[0]=a[1]=a[2]=a[3]=a[4]=a[5]=a[6]=1;
	if(num==9)
		a[0]=a[2]=a[3]=a[4]=a[5]=a[6]=1;
}

void hash1(node x){
	memset(h1,0,sizeof(h1));
	ch(h1[0],x.h/10);
	ch(h1[1],x.h%10);
	ch(h1[2],x.m/10);
	ch(h1[3],x.m%10);
}

void hash2(node x){
	memset(h2,0,sizeof(h2));
	ch(h2[0],x.h/10);
	ch(h2[1],x.h%10);
	ch(h2[2],x.m/10);
	ch(h2[3],x.m%10);
}

bool cmp(){
	for(int i=0;i<4;i++)
		for(int j=0;j<7;j++){
			if(h2[i][j]==1&&h1[i][j]==0){
				if(h[i][j]==0)
					h[i][j]=-1;
				else if(h[i][j]==1)
					return false;
			}else if(h2[i][j]==0&&h1[i][j]==1)
				return false;
			else if(h2[i][j]==1&&h1[i][j]==1){
				if(h[i][j]==0)
					h[i][j]=1;
				else if(h[i][j]==-1)
					return false;
				else if(h[i][j]==1)
					continue;
			}
		}
	return true;
}

bool ccmp(const node &a,const node &b){
	if(a.h!=b.h)
		return a.h<b.h;
	else
		return a.m<b.m;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d:%d",&t[i].h,&t[i].m);
		vector<node> ans;
		for(int th=0;th<24;th++)
			for(int tm=0;tm<60;tm++){
				node tmp;
				tmp.h=th;
				tmp.m=tm;
				bool flag=true;
				memset(h,0,sizeof(h));
				for(int d=0;d<n;d++){
					node tmp2=tmp;
					add(tmp2,d);
					hash1(t[d]);
					hash2(tmp2);
					if(!cmp()){
						flag=false;
						break;
					}
				}
				if(flag){
					ans.push_back(tmp);
				}
			}
		sort(ans.begin(),ans.end(),ccmp);
		if(ans.size()==0){
			printf("none\n");
			continue;
		}
		printf("%02d:%02d",ans[0].h,ans[0].m);
		for(int i=1;i<ans.size();i++)
			printf(" %02d:%02d",ans[i].h,ans[i].m);
		printf("\n");
	}
	return 0;
}
